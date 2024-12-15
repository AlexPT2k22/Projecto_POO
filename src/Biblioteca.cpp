#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "Biblioteca.h"
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroFiccao.h"
#include "Revista.h"
#include "Jornal.h"
#include "LeitorComum.h"
#include "Senior.h"
#include "Estudante.h"
#include "Professor.h"

/**
 * @brief Construtor da classe Biblioteca.
 * 
 * Este construtor é responsável por inicializar uma nova instância da classe Biblioteca.
 * Não recebe parâmetros e não realiza nenhuma inicialização específica, uma vez que
 * as colecções de livros, leitores e empréstimos são inicializadas automaticamente
 * como vectores vazios.
 * 
 * As colecções que são inicializadas são:
 * - Coleccao_LIVROS: Vector que armazena apontadores para objectos do tipo Livro
 * - Coleccao_LEITORES: Vector que armazena apontadores para objectos do tipo Leitor
 * - Coleccao_REQ: Vector que armazena apontadores para objectos do tipo Emprestimo
 */
Biblioteca::Biblioteca()
{
    // constructor
}

/**
 * @brief Destrutor da classe Biblioteca.
 * 
 * Este destrutor é responsável por limpar a memória dinamicamente alocada
 * associada à instância da classe Biblioteca. Ele itera através das colecções
 * de livros, leitores e empréstimos, deletando cada objecto alocado dinamicamente
 * e limpando as colecções.
 */
Biblioteca::~Biblioteca()
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Deleta cada livro
    {
        delete Coleccao_LIVROS[i];
    }
    Coleccao_LIVROS.clear(); //Limpa a colecção de livros

    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) //Deleta cada leitor
    {
        delete Coleccao_LEITORES[i];
    }
    Coleccao_LEITORES.clear(); //Limpa a colecção de leitores

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //Deleta cada empréstimo
    {
        delete Coleccao_REQ[i];
    }
    Coleccao_REQ.clear(); //Limpa a colecção de empréstimos
}

/**
 * @brief Salva os dados da biblioteca em um ficheiro CSV.
 * 
 * @param nf O nome do ficheiro CSV a ser salvo.
 * @return true se o ficheiro foi salvo com sucesso, false caso contrário.
 */
bool Biblioteca::SaveToFile(string nf)
{
    nf += ".csv";
    ofstream file(nf); //Abre o ficheiro para escrita
    if (!file.is_open()) //Verifica se o ficheiro foi aberto com sucesso
    {
        cout << "Erro ao abrir o ficheiro para escrita!" << endl;
        return false;
    }

    // Salvar livros
    file << "LIVROS" << endl;
    file << "TIPO,TITULO,AUTOR,ISBN,CATEGORIA,COPIAS,COPIAS_EMPRESTADAS,INFO_ADICIONAL" << endl;
    for (size_t i = 0; i < Coleccao_LIVROS.size(); i++) { //Itera sobre cada livro
        Livro* livro = Coleccao_LIVROS[i];
        file << livro->getTipo() << "," //Escreve o tipo do livro
             << livro->getTitulo() << "," //Escreve o título do livro
             << livro->getAutor() << "," //Escreve o autor do livro
             << livro->getIsbn() << "," //Escreve o ISBN do livro
             << livro->getCategoria() << "," //Escreve a categoria do livro
             << livro->getNumCopias() << "," //Escreve o número de copias do livro
             << livro->getCopiasDisponiveis() << ","; //Escreve o número de copias disponíveis do livro

        // Informação adicional específica para cada tipo
        if (LivroEducativo* livroEd = dynamic_cast<LivroEducativo*>(livro)) { //Verifica se o livro é educativo
            file << livroEd->getGrauEscolaridade(); //Escreve o grau de escolaridade do livro
        }
        else if (Revista* revista = dynamic_cast<Revista*>(livro)) { //Verifica se o livro é uma revista
            file << revista->getEdicao(); //Escreve a edição da revista
        }
        else if (Jornal* jornal = dynamic_cast<Jornal*>(livro)) { //Verifica se o livro é um jornal
            file << jornal->getDia(); //Escreve o dia do jornal
        }
        file << endl;
    }

    // Cabeçalho dos leitores
    file << "\nLEITORES" << endl;
    file << "TIPO,NOME,ID" << endl;
    for (size_t i = 0; i < Coleccao_LEITORES.size(); i++) { //Itera sobre cada leitor
        Leitor* leitor = Coleccao_LEITORES[i];
        file << leitor->getTipo() << "," //Escreve o tipo do leitor
             << leitor->getNome() << "," //Escreve o nome do leitor
             << leitor->getID() << endl; //Escreve o ID do leitor
    }

    // Salvar empréstimos
    file << "\nEMPRESTIMOS" << endl;
    file << "ISBN,ID_LEITOR,DATA_EMPRESTIMO,DATA_DEVOLUCAO" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); i++) { //Itera sobre cada empréstimo
        Emprestimo* emp = Coleccao_REQ[i]; //Pointer para o empréstimo
        char data_emp[26], data_dev[26]; //Arrays para armazenar as datas
        strftime(data_emp, sizeof(data_emp), "%Y-%m-%d %H:%M:%S", localtime(&emp->dataEmprestimo)); //Formata a data de empréstimo
        strftime(data_dev, sizeof(data_dev), "%Y-%m-%d %H:%M:%S", localtime(&emp->dataDevolucao)); //Formata a data de devolução
    
        file << emp->getLivro()->getIsbn() << "," //Escreve o ISBN do livro 
             << emp->getLeitor()->getID() << "," //Escreve o ID do leitor
             << data_emp << "," //Escreve a data de empréstimo
             << data_dev << endl; //Escreve a data de devolução
    }

    // Salvar reservas (fora do loop de livros)
    file << "\nRESERVAS" << endl;
    file << "ISBN,ID_LEITOR" << endl;
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) { //Itera sobre cada livro
        for (size_t j = 0; j < Coleccao_LIVROS[i]->reservas.size(); ++j) { //Itera sobre cada reserva
            file << Coleccao_LIVROS[i]->getIsbn() << "," //Escreve o ISBN do livro
                 << Coleccao_LIVROS[i]->reservas[j]->getID() << endl; //Escreve o ID do leitor
        }
    }

    file.close(); //Fecha o ficheiro
    cout << "Ficheiro exportado com sucesso!" << endl;
    return true;
}

/**
 * @brief Carrega os dados da biblioteca a partir de um ficheiro CSV.
 * 
 * @param nf O nome do ficheiro CSV a ser carregado.
 * @return true se o ficheiro foi carregado com sucesso, false caso contrário.
 */
bool Biblioteca::LoadFile(string nf)
{
    nf += ".csv";
    ifstream file(nf); //Abre o ficheiro para leitura
    if (!file.is_open()) { //Verifica se o ficheiro foi aberto com sucesso
        cout << "Erro ao abrir arquivo para leitura!" << endl;
        return false;
    }

    // Limpar coleções existentes
    for (size_t i = 0; i < Coleccao_LIVROS.size(); i++) delete Coleccao_LIVROS[i]; //Deleta cada livro
    for (size_t i = 0; i < Coleccao_LEITORES.size(); i++) delete Coleccao_LEITORES[i]; //Deleta cada leitor 
    for (size_t i = 0; i < Coleccao_REQ.size(); i++) delete Coleccao_REQ[i]; //Deleta cada empréstimo
    
    Coleccao_LIVROS.clear(); //Limpa a colecção de livros
    Coleccao_LEITORES.clear(); //Limpa a colecção de leitores
    Coleccao_REQ.clear(); //Limpa a colecção de empréstimos

    string line; //String para armazenar cada linha do ficheiro
    string section; //String para armazenar a seção do ficheiro

    while (getline(file, line)) { //Lê cada linha do ficheiro
        if (line.empty()) continue; //Ignora as linhas vazias

        if (line == "LIVROS" || line == "LEITORES" || line == "EMPRESTIMOS" || line == "RESERVAS") {
            section = line; //Define a seção do ficheiro
            getline(file, line); //Pula o cabeçalho
            continue;
        }

        stringstream ss(line); //Cria um stream para a linha
        
        if (section == "LIVROS") { //Se a seção é de livros
            string tipo, titulo, autor, isbn, categoria, copias_str, copias_emp_str, info;
            getline(ss, tipo, ','); //Lê o tipo do livro
            getline(ss, titulo, ','); //Lê o título do livro
            getline(ss, autor, ','); //Lê o autor do livro
            getline(ss, isbn, ','); //Lê o ISBN do livro
            getline(ss, categoria, ','); //Lê a categoria do livro
            getline(ss, copias_str, ','); //Lê o número de copias do livro
            getline(ss, copias_emp_str, ','); //Lê o número de copias emprestadas do livro
            getline(ss, info); //Lê a informação adicional do livro

            int copias = stoi(copias_str); //Converte a string para int
            Livro* livro = nullptr;

            if (tipo == "Cientifico") { //Se o tipo é científico
                livro = new LivroCientifico(titulo, autor, isbn, categoria, copias); //Cria um novo livro científico
            } 
            else if (tipo == "Educacional") { //Se o tipo é educacional
                livro = new LivroEducativo(titulo, autor, isbn, categoria, info, copias); //Cria um novo livro educacional
            } 
            else if (tipo == "Ficcao") { //Se o tipo é ficção
                livro = new LivroFiccao(titulo, autor, isbn, categoria, copias); //Cria um novo livro ficção
            } 
            else if (tipo == "Revista") { //Se o tipo é revista
                livro = new Revista(titulo, autor, isbn, categoria, stoi(info), copias); //Cria uma nova revista
            } 
            else if (tipo == "Jornal") { //Se o tipo é jornal
                livro = new Jornal(titulo, autor, isbn, categoria, stoi(info), copias); //Cria um novo jornal
            }

            if (livro) { //Se o livro foi criado com sucesso
                Coleccao_LIVROS.push_back(livro); //Adiciona o livro à colecção de livros
            }
        }
        else if (section == "LEITORES") { //Se a seção é de leitores
            string tipo, nome, id;
            getline(ss, tipo, ','); //Lê o tipo do leitor
            getline(ss, nome, ','); //Lê o nome do leitor
            getline(ss, id); //Lê o ID do leitor

            Leitor* leitor = nullptr;
            if (tipo == "Comum") leitor = new LeitorComum(nome, id); //Se o tipo é comum cria um novo leitor comum
            else if (tipo == "Estudante") leitor = new Estudante(nome, id); //Se o tipo é estudante cria um novo estudante
            else if (tipo == "Professor") leitor = new Professor(nome, id); //Se o tipo é professor cria um novo professor
            else if (tipo == "Senior") leitor = new Senior(nome, id); //Se o tipo é senior cria um novo senior

            if (leitor) Coleccao_LEITORES.push_back(leitor); //Adiciona o leitor à colecção de leitores
        }
        else if (section == "EMPRESTIMOS") { //Se a seção é de empréstimos
            string isbn, id_leitor, data_emp_str, data_dev_str;
            getline(ss, isbn, ','); //Lê o ISBN do livro
            getline(ss, id_leitor, ','); //Lê o ID do leitor
            getline(ss, data_emp_str, ','); //Lê a data de empréstimo
            getline(ss, data_dev_str); //Lê a data de devolução

            Livro* livro = nullptr; //Pointer para o livro
            Leitor* leitor = nullptr; //Pointer para o leitor

            for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) { //Itera sobre cada livro
                if (Coleccao_LIVROS[i]->getIsbn() == isbn) { //Se o ISBN do livro é igual ao ISBN do livro a procurar
                    livro = Coleccao_LIVROS[i]; //O livro é encontrado
                    break; //Sai do loop
                }
            }

            for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) { //Itera sobre cada leitor
                if (Coleccao_LEITORES[i]->getID() == id_leitor) { //Se o ID do leitor é igual ao ID do leitor a procurar
                    leitor = Coleccao_LEITORES[i]; //O leitor é encontrado
                    break; //Sai do loop
                }
            }

            if (livro && leitor) { //Se o livro e o leitor foram encontrados
                Emprestimo* emp = new Emprestimo(livro, leitor); //Cria um novo empréstimo
                struct tm tm_emp = {0}, tm_dev = {0}; //Arrays para armazenar as datas
                sscanf(data_emp_str.c_str(), "%d-%d-%d %d:%d:%d", //Formata a data de empréstimo
                    &tm_emp.tm_year, &tm_emp.tm_mon, &tm_emp.tm_mday,
                    &tm_emp.tm_hour, &tm_emp.tm_min, &tm_emp.tm_sec);
                tm_emp.tm_year -= 1900; //Subtrai 1900 à data de empréstimo (ano)
                tm_emp.tm_mon -= 1; //Subtrai 1 à data de empréstimo (mês)
                emp->dataEmprestimo = mktime(&tm_emp); //Formata a data de empréstimo

                sscanf(data_dev_str.c_str(), "%d-%d-%d %d:%d:%d", //Formata a data de devolução
                    &tm_dev.tm_year, &tm_dev.tm_mon, &tm_dev.tm_mday,
                    &tm_dev.tm_hour, &tm_dev.tm_min, &tm_dev.tm_sec);
                tm_dev.tm_year -= 1900; //Subtrai 1900 à data de devolução (ano)    
                tm_dev.tm_mon -= 1; //Subtrai 1 à data de devolução (mês)
                emp->dataDevolucao = mktime(&tm_dev); //Formata a data de devolução

                Coleccao_REQ.push_back(emp); //Adiciona o empréstimo à colecção de empréstimos
                leitor->adicionarEmprestimo(emp); //Adiciona o empréstimo ao leitor
                livro->emprestar_Copia(); //Empresta uma cópia do livro
            }
        }
        else if (section == "RESERVAS") { //Se a seção é de reservas
            string isbn, id_leitor;
            getline(ss, isbn, ','); //Lê o ISBN do livro
            getline(ss, id_leitor); //Lê o ID do leitor

            Livro* livro = nullptr; //Pointer para o livro
            Leitor* leitor = nullptr; //Pointer para o leitor

            // Encontrar o livro
            for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) { //Itera sobre cada livro
                if (Coleccao_LIVROS[i]->getIsbn() == isbn) { //Se o ISBN do livro é igual ao ISBN do livro a procurar
                    livro = Coleccao_LIVROS[i]; //O livro é encontrado
                    //cout << "Livro encontrado: " << livro->getTitulo() << endl;
                    break; //Sai do loop
                }
            }

            // Encontrar o leitor
            for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) { //Itera sobre cada leitor
                if (Coleccao_LEITORES[i]->getID() == id_leitor) { //Se o ID do leitor é igual ao ID do leitor a procurar
                    leitor = Coleccao_LEITORES[i]; //O leitor é encontrado
                    //cout << "Leitor encontrado: " << leitor->getNome() << endl;
                    break; //Sai do loop
                }
            }

            if (livro && leitor) { //Se o livro e o leitor foram encontrados
                livro->adicionar_Reserva(leitor); //Adiciona a reserva ao livro
                //cout << "Reserva carregada: " << livro->getTitulo() << " para " << leitor->getNome() << endl;
            }
        }
    }

    file.close(); //Fecha o ficheiro
    cout << "Arquivo carregado com sucesso!" << endl;
    return true;
}

/**
 * @brief Prorroga um empréstimo de um livro para um leitor específico.
 * 
 * @param id O ID do leitor que está realizando a prorrogação.
 * @param isbn O ISBN do livro que está sendo prorrogado.
 */
void Biblioteca::Prorrogacao_Emprestimos(string id, string isbn)
{
    Emprestimo *emprestimo = nullptr; //Pointer para o empréstimo

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //Itera sobre cada empréstimo
    {
        if (Coleccao_REQ[i]->getLivro()->getIsbn() == isbn && Coleccao_REQ[i]->getLeitor()->getID() == id) //Se o ISBN do empréstimo é igual ao ISBN do livro a procurar e o ID do leitor é igual ao ID do leitor a procurar
        {
            emprestimo = Coleccao_REQ[i]; //O empréstimo é encontrado
            break; //Sai do loop
        }
    }

    if (!emprestimo) //Se o empréstimo não foi encontrado
    {
        cout << "Emprestimo nao encontrado!" << endl; //Imprime uma mensagem de erro
        return; //Sai da função
    }

    if (emprestimo->getLeitor()->podeProrrogar()) //Se o leitor pode prorrogar
    {
        emprestimo->prorrogarEmprestimo(); //Prorroga o empréstimo
        cout << "Emprestimo prorrogado com sucesso!" << endl; //Imprime uma mensagem de sucesso
    }
    else
    {
        cout << "Leitor do tipo " << emprestimo->getLeitor()->getTipo() << " nao pode prorrogar emprestimos!" << endl; //Imprime uma mensagem de erro
    }
}

/**
 * @brief Envia notificações de atraso para os leitores.
 */
void Biblioteca::Sistema_Notificacoes_Atraso()
{
    cout << "=== Sistema de Notificacoes de Atraso ===" << endl;
    if (Coleccao_REQ.size() == 0) //Se o número de empréstimos é 0
    {
        cout << "Nenhum livro atrasado!" << endl; 
    }

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //Itera sobre cada empréstimo
    {
        if (Coleccao_REQ[i]->estaAtrasado()) //Se o empréstimo está atrasado
        {
            if (Coleccao_REQ[i]->getLeitor()->podeProrrogar() == true) //Se o leitor pode prorrogar
            {
                cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl; //Imprime o título do livro
                cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl; //Imprime o nome do leitor
                cout << "Data de Devolucao Prevista: " << ctime(&Coleccao_REQ[i]->dataDevolucao); //Imprime a data de devolução prevista
                cout << "ATRASADO! Multa: " << Coleccao_REQ[i]->calcularMulta() << " euros" << endl; //Imprime a multa
                cout << "AVISO: Pode prorrogar o seu emprestimo!" << endl; //Imprime um aviso
                cout << "---------------------------------" << endl; //Imprime uma linha de separação
            }
            else //Se o leitor não pode prorrogar
            {
                cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl; //Imprime o título do livro
                cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl; //Imprime o nome do leitor
                cout << "Data de Devolucao Prevista: " << ctime(&Coleccao_REQ[i]->dataDevolucao); //Imprime a data de devolução prevista
                cout << "ATRASADO! Multa: " << Coleccao_REQ[i]->calcularMulta() << " euros" << endl; //Imprime a multa
                cout << "Multa acresce em 1 euro por dia de atraso!" << endl; //Imprime uma mensagem de que a multa acresce em 1 euro por dia de atraso
                cout << "---------------------------------" << endl;
            }
        }
        else //Se o empréstimo não está atrasado
        {
            cout << "Nenhum livro atrasado!" << endl;
        }
    }
}

/**
 * @brief Lista todos os livros na coleção.
 */
void Biblioteca::Listagem_Livros()
{
    cout << "=== Listagem de Livros ===" << endl;
    if (Coleccao_LIVROS.size() == 0) //Se o número de livros é 0
    {
        cout << "Nenhum livro na colecao!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl; //Imprime o título do livro
        cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl; //Imprime o autor do livro
        cout << "Genero: " << Coleccao_LIVROS[i]->getCategoria() << endl; //Imprime o género do livro
        cout << "Tipo: " << Coleccao_LIVROS[i]->getTipo() << endl; //Imprime o tipo do livro
        cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl; //Imprime o ISBN do livro
        cout << "Numero de copias: " << Coleccao_LIVROS[i]->getNumCopias() << endl; //Imprime o número de cópias do livro   
        cout << "Numero de copias disponiveis: " << Coleccao_LIVROS[i]->getCopiasDisponiveis() << endl; //Imprime o número de cópias disponíveis do livro
        cout << "---------------------------------" << endl;
    }
}

/**
 * @brief Adiciona um leitor à coleção de leitores.
 * 
 * @param LT Ponteiro para o objeto Leitor a ser adicionado.
 * @return true se o leitor foi adicionado com sucesso, false caso contrário.
 */
bool Biblioteca::Add_Leitor(Leitor *LT)
{
    Coleccao_LEITORES.push_back(LT); // Adiciona ao final do vetor
    return true;
}

/**
 * @brief Adiciona um livro à coleção de livros.
 * 
 * @param L Ponteiro para o objeto Livro a ser adicionado.
 * @return true se o livro foi adicionado com sucesso, false caso contrário.
 */
bool Biblioteca::Add_Livro(Livro *L)
{
    // apenas as cópias podem ter o mesmo isbn
    if (Coleccao_LIVROS.size() > 0) //Se o número de livros é maior que 0
    {
        for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
        {
            if (Coleccao_LIVROS[i]->getIsbn() == L->getIsbn()) //Se o ISBN do livro é igual ao ISBN do livro a procurar
            {
                cout << "Livro com ISBN " << L->getIsbn() << " ja existe!" << endl; //Imprime uma mensagem de erro
                return false;
            }
        }
    }
    Coleccao_LIVROS.push_back(L); //Adiciona o livro à colecção de livros
    cout << "Livro adicionado com sucesso!" << endl;
    return true;
}

/**
 * @brief Adiciona um empréstimo de livro para um leitor.
 *
 * Esta função tenta adicionar um empréstimo de um livro para um leitor específico.
 * Primeiro, verifica se o livro e o leitor existem. Se o livro não tiver cópias
 * disponíveis, o usuário é perguntado se deseja realizar uma reserva. Se o empréstimo
 * for bem-sucedido, ele é adicionado à coleção de empréstimos ativos.
 *
 * @param L Ponteiro para o objeto Livro a ser emprestado.
 * @param LT Ponteiro para o objeto Leitor que está recebendo o empréstimo.
 */
void Biblioteca::Add_Emprestimo(Livro *L, Leitor *LT)
{
    if (!L) //Se o livro não foi encontrado
    {
        cout << "Livro nao encontrado!" << endl;
        return;
    }

    if (!LT) //Se o leitor não foi encontrado
    {
        cout << "Leitor nao encontrado!" << endl;
        return;
    }

    // Verificar se há cópias disponíveis
    if (!L->emprestar_Copia()) //Se não há cópias disponíveis
    {
        cout << "Nao ha copias disponiveis para o livro: " << L->getTitulo() << endl; //Imprime uma mensagem de erro
        cout << "Deseja realizar uma reserva (S/N)? "; //Imprime uma mensagem de pergunta
        string resposta;
        cin >> resposta;
        if (resposta == "S" || resposta == "s") //Se a resposta é sim
        {
            reservarLivro(L->getIsbn(), LT); //Realiza a reserva
        }
        else
        {
            cout << "Emprestimo nao realizado!" << endl; //Imprime uma mensagem de erro
        }
        return;
    }

    // Criar o empréstimo e associá-lo ao leitor e à coleção de empréstimos
    Emprestimo *emprestimo = new Emprestimo(L, LT); //Cria um novo empréstimo
    Coleccao_REQ.push_back(emprestimo); //Adiciona o empréstimo à colecção de empréstimos
    LT->adicionarEmprestimo(emprestimo); //Adiciona o empréstimo ao leitor

    cout << "Emprestimo realizado com sucesso!" << endl;
}

/**
 * @brief Devolve um livro emprestado à biblioteca.
 *
 * Esta função realiza a devolução de um livro emprestado, removendo o empréstimo
 * da coleção de empréstimos ativos da biblioteca e do leitor associado. Se o empréstimo
 * não for encontrado ou for inválido, uma mensagem de erro é exibida. Caso o livro seja
 * devolvido com atraso, uma multa é calculada e exibida.
 *
 * @param E Ponteiro para o objeto Emprestimo que representa o empréstimo a ser devolvido.
 */
void Biblioteca::Devolver_Livro(Emprestimo *E)
{
    if (!E) //Se o empréstimo não foi encontrado
    {
        cout << "Emprestimo invalido!" << endl;
        return;
    }

    Livro *livro = E->getLivro(); //Obtém o livro do empréstimo
    Leitor *leitorAtual = E->getLeitor(); //Obtém o leitor do empréstimo

    if (leitorAtual) //Se o leitor foi encontrado
    {
        leitorAtual->removerEmprestimo(E); //Remove o empréstimo do leitor
    }

    Coleccao_REQ.erase(std::remove(Coleccao_REQ.begin(), Coleccao_REQ.end(), E), Coleccao_REQ.end()); // remove o empréstimo da coleção

    livro->devolver_Copia(); //Devolve a cópia do livro

    if (livro->temReserva()) //Se o livro tem uma reserva
    {
        Leitor *proximoLeitor = livro->Proximo_Leitor_Reserva(); //Obtém o próximo leitor da reserva
        cout << "Livro reservado para o proximo leitor: " << proximoLeitor->getNome() << " com ID: " << proximoLeitor->getID() << endl; //Imprime o nome e o ID do próximo leitor
        livro->remover_Reserva(proximoLeitor); //Remove a reserva do livro
        cout << "Realizar emprestimo para o leitor " << proximoLeitor->getNome() << " com ID " << proximoLeitor->getID() << "? (S/N): "; //Imprime uma mensagem de pergunta
        string resposta;
        cin >> resposta;
        if (resposta == "S" || resposta == "s") //Se a resposta é sim
        {
            Add_Emprestimo(livro, proximoLeitor); //Realiza o empréstimo
        }
        else
        {
            cout << "Emprestimo nao realizado!" << endl;
        }
    }

    // multa
    float multa = E->calcularMulta(); //Calcula a multa
    if (multa > 0) //Se a multa é maior que 0
    {
        cout << "Livro devolvido com atraso! Multa: " << multa << " euros" << endl; //Imprime a multa
    }
    else
    {
        cout << "Livro devolvido dentro do prazo!" << endl;
    }

    delete E; //Libera a memória do empréstimo
}

/**
 * @brief Gera um relatório dos empréstimos atuais na biblioteca.
 *
 * Esta função imprime na consola um relatório detalhado dos empréstimos
 * atuais, incluindo o título do livro (ISBN), o nome do leitor e as datas de
 * empréstimo e devolução.
 *
 * O relatório é formatado com uma linha de separação entre cada empréstimo.
 */
void Biblioteca::Gerar_RelatorioEmprestimos()
{
    cout << "=== Relatorio de Emprestimos Atuais ===" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //Itera sobre cada empréstimo
    {
        cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << " (ISBN: " << Coleccao_REQ[i]->getLivro()->getIsbn() << ")" << endl; //Imprime o título do livro e o ISBN
        cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << " (ID: " << Coleccao_REQ[i]->getLeitor()->getID() << ")" << endl; //Imprime o nome do leitor e o ID
        cout << "Data de Emprestimo: " << ctime(&Coleccao_REQ[i]->dataEmprestimo); //Imprime a data de empréstimo
        cout << "Data de Devolucao: " << ctime(&Coleccao_REQ[i]->dataDevolucao); //Imprime a data de devolução
        cout << "---------------------------------" << endl;
    }
}

/**
 * @brief Edita as informações de um leitor na coleção de leitores.
 *
 * Esta função percorre a coleção de leitores (Coleccao_LEITORES) e procura
 * um leitor com o ID fornecido. Se encontrar, chama a função editarInformacoes()
 * desse leitor para permitir a edição das suas informações. Caso contrário,
 * imprime uma mensagem a indicar que o leitor não foi encontrado.
 *
 * @param id O ID do leitor cujas informações devem ser editadas.
 */
void Biblioteca::Editar_InformacoesLeitores(string id)
{
    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) //Itera sobre cada leitor
    {
        if (Coleccao_LEITORES[i]->getID() == id) //Se o ID do leitor é igual ao ID a procurar
        {
            Coleccao_LEITORES[i]->editarInformacoes(); //Edita as informações do leitor
            return;
        }
    }

    cout << "Leitor nao encontrado!" << endl;
}

/**
 * @brief Pesquisa livros na coleção pelo tipo especificado.
 *
 * Esta função exibe informações sobre todos os livros na coleção que correspondem ao tipo fornecido.
 * Se nenhum livro for encontrado, uma mensagem apropriada será exibida.
 *
 * @param tipo O tipo de livro a ser pesquisado.
 */
void Biblioteca::Pesquisar_Livro_Tipo(string tipo)
{
    cout << "=== Pesquisar livro por tipo ===" << endl;
    cout << "\nPesquisar livro por tipo: " << tipo << " ---" << endl; //Imprime a pesquisa
    bool encontrado = false; //Flag para indicar se o livro foi encontrado

    if (Coleccao_LIVROS.size() == 0) //Se o número de livros é 0
    {
        cout << "Nenhum livro encontrado!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getTipo() == tipo) //Se o tipo do livro é igual ao tipo a procurar
        {
            encontrado = true; //Indica que o livro foi encontrado
            cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl; //Imprime o título do livro
            cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl; //Imprime o autor do livro
            cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl; //Imprime o ISBN do livro
            cout << "---------------------------------" << endl; //Imprime uma linha de separação
        }
    }

    if (!encontrado) //Se o livro não foi encontrado
    {
        cout << "Nenhum livro encontrado!" << endl;
    }
}

/**
 * @brief Lista todos os livros de uma determinada categoria.
 *
 * Esta função percorre a coleção de livros e exibe as informações dos livros
 * que pertencem à categoria especificada. Se não houver livros na coleção ou
 * se nenhum livro corresponder à categoria fornecida, uma mensagem apropriada
 * será exibida.
 *
 * @param categoria A categoria dos livros a serem listados.
 */
void Biblioteca::ListarLivrosCategoria(string categoria)
{
    cout << "=== Listar livros por categoria ===" << endl;
    cout << "\nListar livros por categoria: " << categoria << " ---" << endl; //Imprime a pesquisa
    bool encontrado = false; //Flag para indicar se o livro foi encontrado

    if (Coleccao_LIVROS.size() == 0) //Se o número de livros é 0
    {
        cout << "Nenhum livro encontrado!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getCategoria() == categoria) //Se a categoria do livro é igual à categoria a procurar
        {
            encontrado = true; //Indica que o livro foi encontrado
            cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl; //Imprime o título do livro
            cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl; //Imprime o autor do livro
            cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl; //Imprime o ISBN do livro
            cout << "---------------------------------" << endl; //Imprime uma linha de separação
        }
    }

    if (!encontrado) //Se o livro não foi encontrado
    {
        cout << "Nenhum livro encontrado!" << endl;
    }
}

/**
 * @brief Edita as informações de um livro na coleção de livros.
 *
 * Esta função percorre a coleção de livros e procura um livro com o ISBN fornecido.
 * Se encontrar, chama a função editarInformacoesLivro() desse livro para permitir
 * a edição das suas informações. Caso contrário, imprime uma mensagem a indicar
 * que o livro não foi encontrado.
 *
 * @param isbn O ISBN do livro cujas informações devem ser editadas.
 */
void Biblioteca::Editar_InformacoesLivros(string isbn)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn) //Se o ISBN do livro é igual ao ISBN a procurar
        {
            cout << "A atualizar informacoes do livro: " << Coleccao_LIVROS[i]->getTitulo() << endl; //Imprime o título do livro
            Coleccao_LIVROS[i]->EditarInformacoesLivro(); //Edita as informações do livro
            return; //Sai da função
        }
    }

    cout << "Livro nao encontrado!" << endl; //Imprime uma mensagem de erro
}

/**
 * @brief Remove um leitor da coleção de leitores.
 *
 * Esta função percorre a coleção de leitores e procura um leitor com o ID fornecido.
 * Se encontrar, verifica se o leitor possui empréstimos ativos. Se não possuir, remove
 * o leitor da coleção. Caso contrário, imprime uma mensagem de erro indicando que o
 * leitor não pode ser removido devido a empréstimos pendentes.
 *
 * @param id O ID do leitor a ser removido.
 */
void Biblioteca::Remover_Leitor(string id)
{
    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) //Itera sobre cada leitor
    {
        if (Coleccao_LEITORES[i]->getID() == id) //Se o ID do leitor é igual ao ID a procurar
        {
            if (!Coleccao_LEITORES[i]->getEmprestimos().empty()) //Se o leitor possui empréstimos ativos
            {
                cout << "Erro: O leitor ainda possui empréstimos pendentes e nao pode ser removido!" << endl; //Imprime uma mensagem de erro
                return; //Sai da função
            }

            cout << "Removendo leitor: " << Coleccao_LEITORES[i]->getNome() << endl; //Imprime o nome do leitor
            delete Coleccao_LEITORES[i]; //Libera a memória do leitor
            Coleccao_LEITORES.erase(Coleccao_LEITORES.begin() + i); //Remove o leitor da coleção
            cout << "Leitor removido com sucesso!" << endl; //Imprime uma mensagem de sucesso
            return; //Sai da função
        }
    }
    cout << "Leitor com ID " << id << " nao encontrado!" << endl;
}

/**
 * @brief Remove um livro da coleção de livros.
 *
 * Esta função percorre a coleção de livros e procura um livro com o ISBN fornecido.
 * Se encontrar, verifica se o livro está associado a um empréstimo ativo. Se estiver,
 * imprime uma mensagem de erro indicando que o livro não pode ser removido devido
 * a empréstimos pendentes. Caso contrário, remove o livro da coleção.
 *
 * @param isbn O ISBN do livro a ser removido.
 */
void Biblioteca::Remover_Livro(string isbn)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn) //Se o ISBN do livro é igual ao ISBN a procurar
        {
            for (size_t j = 0; j < Coleccao_REQ.size(); ++j) //Itera sobre cada empréstimo
            {
                if (Coleccao_REQ[j]->getLivro()->getIsbn() == isbn) //Se o ISBN do livro do empréstimo é igual ao ISBN a procurar
                {
                    cout << "Erro: O livro está associado a um empréstimo ativo e não pode ser removido!" << endl; //Imprime uma mensagem de erro
                    return; //Sai da função
                }
            }

            cout << "Removendo livro: " << Coleccao_LIVROS[i]->getTitulo() << endl; //Imprime o título do livro
            delete Coleccao_LIVROS[i]; //Libera a memória do livro
            Coleccao_LIVROS.erase(Coleccao_LIVROS.begin() + i); //Remove o livro da coleção
            cout << "Livro removido com sucesso!" << endl; //Imprime uma mensagem de sucesso
            return; //Sai da função
        }
    }
    cout << "Livro com ISBN " << isbn << " nao encontrado!" << endl;
}

/**
 * @brief Realiza a reserva de um livro para um leitor.
 *
 * Esta função percorre a coleção de livros e procura um livro com o ISBN fornecido.
 * Se encontrar, verifica se o livro está associado a um empréstimo ativo. Se estiver,
 * imprime uma mensagem de erro indicando que o livro não pode ser reservado devido
 * a empréstimos pendentes. Caso contrário, reserva o livro para o leitor.
 *
 * @param isbn O ISBN do livro a ser reservado.
 * @param LT O leitor que deseja reservar o livro.
 */
void Biblioteca::reservarLivro(string isbn, Leitor *LT)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn) //Se o ISBN do livro é igual ao ISBN a procurar
        {
            Livro *livro = Coleccao_LIVROS[i]; //Obtém o livro

            bool emprestado = false; //Flag para indicar se o livro está emprestado
            for (size_t j = 0; j < Coleccao_REQ.size(); ++j) //Itera sobre cada empréstimo
            {
                if (Coleccao_REQ[j]->getLivro() == livro) //Se o livro do empréstimo é igual ao livro a procurar
                {
                    emprestado = true; //Indica que o livro está emprestado
                    break; //Sai do loop
                }
            }
            if (!emprestado) //Se o livro não está emprestado
            {
                cout << "Livro nao disponivel para reserva pois nao esta emprestado!" << endl; //Imprime uma mensagem de erro
                return; //Sai da função
            }
            else
            {
                livro->adicionar_Reserva(LT); //Adiciona a reserva ao livro 
                cout << "Livro reservado com sucesso para o leitor: " << LT->getNome() << endl; //Imprime uma mensagem de sucesso
                return; //Sai da função
            }
        }
    }
    cout << "Livro com ISBN " << isbn << " nao encontrado!" << endl;
}

/**
 * @brief Cancela a reserva de um livro para um leitor.
 *
 * Esta função percorre a coleção de livros e procura um livro com o ISBN fornecido.
 * Se encontrar, verifica se o livro está associado a uma reserva. Se estiver,
 * imprime uma mensagem de erro indicando que o livro não pode ser reservado devido
 * a empréstimos pendentes. Caso contrário, remove a reserva do livro.
 *
 * @param isbn O ISBN do livro a ser reservado.
 * @param id O ID do leitor que deseja cancelar a reserva.
 */
void Biblioteca::cancelar_reserva(string isbn, string id)
{
    Livro *livro = nullptr; //Ponteiro para o livro
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn) //Se o ISBN do livro é igual ao ISBN a procurar
        {
            livro = Coleccao_LIVROS[i]; //Obtém o livro
            break; //Sai do loop
        }
    }
    if (!livro) //Se o livro não foi encontrado
    {
        cout << "Livro com ISBN " << isbn << " e titulo " << livro->getTitulo() << " nao encontrado!" << endl; //Imprime uma mensagem de erro
        return; //Sai da função
    }
    Leitor *leitor = nullptr; //Ponteiro para o leitor
    for (size_t i = 0; i < livro->reservas.size(); ++i) //Itera sobre cada reserva
    {
        if (livro->reservas[i]->getID() == id) //Se o ID da reserva é igual ao ID a procurar
        {
            leitor = livro->reservas[i]; //Obtém o leitor
            break; //Sai do loop
        }
    }
    if (!leitor) //Se o leitor não foi encontrado
    {
        cout << "Reserva nao encontrada para o leitor: " << leitor->getNome() << endl; //Imprime uma mensagem de erro
        return; //Sai da função
    }
    livro->remover_Reserva(leitor); //Remove a reserva do livro
}

/**
 * @brief Lista todas as reservas atuais na biblioteca.
 *
 * Esta função imprime na consola um relatório detalhado das reservas atuais,
 * incluindo o título do livro (ISBN), o nome do leitor e as datas de
 * reserva.
 *
 * O relatório é formatado com uma linha de separação entre cada reserva.
 */
void Biblioteca::ListarReservas()
{
    int reservas_encontradas = 0; //Contador de reservas encontradas
    cout << "=== Lista de Reservas ===" << endl;

    // verificar se tem reservas
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) //Itera sobre cada livro
    { 
        if (Coleccao_LIVROS[i]->reservas.size() > 0) //Se o livro tem reservas
        { 
            reservas_encontradas++; //Incrementa o contador de reservas encontradas
            for (size_t j = 0; j < Coleccao_LIVROS[i]->reservas.size(); ++j) //Itera sobre cada reserva do livro
            { 
                cout << "Reserva #" << reservas_encontradas << endl; //Imprime o número da reserva
                cout << "Livro: " << Coleccao_LIVROS[i]->getTitulo() << " (ISBN: " << Coleccao_LIVROS[i]->getIsbn() << ")" << endl; // imprimir o titulo do livro
                cout << "Leitor: " << Coleccao_LIVROS[i]->reservas[j]->getNome() << " (ID: " << Coleccao_LIVROS[i]->reservas[j]->getID() << ")" << endl; // imprimir o nome do leitor
                cout << "---------------------------------" << endl;
            }
        }
    }
    if (reservas_encontradas == 0) //Se não houver reservas
    {
        cout << "Nenhuma reserva encontrada!" << endl; //Imprime uma mensagem de erro
    }
}

/**
 * @brief Gera um relatório de multas pendentes.
 *
 * Esta função imprime na consola um relatório detalhado das multas pendentes,
 * incluindo o título do livro (ISBN), o nome do leitor e as datas de
 * reserva.
 *
 * O relatório é formatado com uma linha de separação entre cada reserva.
 */
void Biblioteca::GerarRelatorioMultasPendentes()
{
    int multas_encontradas = 0; //Contador de multas encontradas
    cout << "=== Relatorio de Multas Pendentes ===" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //Itera sobre cada empréstimo
    {
        if (Coleccao_REQ[i]->estaAtrasado()) //Se o empréstimo está atrasado
        {
            int multa = Coleccao_REQ[i]->calcularMulta(); //Calcula a multa
            multas_encontradas++; //Incrementa o contador de multas encontradas
            cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << " (ISBN: " << Coleccao_REQ[i]->getLivro()->getIsbn() << ")" << endl; //Imprime o título do livro
            cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << " (ID: " << Coleccao_REQ[i]->getLeitor()->getID() << ")" << " (Tipo: " << Coleccao_REQ[i]->getLeitor()->getTipo() << ")" << endl; //Imprime o nome do leitor
            cout << "Desconto: " << Coleccao_REQ[i]->getLeitor()->getDescontoMulta() * 100 << "%" << endl; //Imprime o desconto da multa
            cout << "Data de Emprestimo: " << ctime(&Coleccao_REQ[i]->dataEmprestimo); //Imprime a data de empréstimo
            cout << "Data de Devolucao: " << ctime(&Coleccao_REQ[i]->dataDevolucao); //Imprime a data de devolução
            cout << "Multa: " << multa << " euros" << endl; //Imprime a multa
            cout << "---------------------------------" << endl;
        }
    }
    if (multas_encontradas == 0) //Se não houver multas
    {
        cout << "Nenhuma multa encontrada!" << endl;
    }
}

/**
 * @brief Gera um relatório de empréstimos por tipo de livro.
 *
 * Esta função gera um relatório detalhado das quantidades de empréstimos por tipo de livro e tipo de leitor.
 * O relatório é formatado com uma linha de separação entre cada tipo de livro.
 */
void Biblioteca::GerarRelatorioEmprestimosPorTipo()
{
    vector<string> tipo_de_livro = {"Cientifico", "Educacional", "Ficcao", "Revista", "Jornal"}; //Tipos de livros
    vector<string> tipo_de_leitor = {"Estudante", "Professor", "LeitorComum", "Senior"}; //Tipos de leitores

    int contagem_emprestimos[5][4] = {0}; // 5 tipos de livros e 4 tipos de leitores (matriz)

    //preencher a matriz com os emprestimos
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) //iterar sobre os emprestimos
    {
        Livro *livro = Coleccao_REQ[i]->getLivro(); //obter o livro do emprestimo
        Leitor *leitor = Coleccao_REQ[i]->getLeitor(); //obter o leitor do emprestimo
        if (livro && leitor) //verificar se o livro e o leitor existem
        {
            int tipo_livro_index = -1; //indice do tipo de livro
            for (size_t j = 0; j < tipo_de_livro.size(); ++j){ //iterar sobre os tipos de livros
                if (livro->getTipo() == tipo_de_livro[j]){ //verificar se o tipo do livro corresponde ao tipo de livro
                    tipo_livro_index = j; //atribuir o indice do tipo de livro
                    break;
                }
            }

            int tipo_leitor_index = -1; //indice do tipo de leitor
            for (size_t j = 0; j < tipo_de_leitor.size(); ++j){ //iterar sobre os tipos de leitores
                if (leitor->getTipo() == tipo_de_leitor[j]){ //verificar se o tipo do leitor corresponde ao tipo de leitor
                    tipo_leitor_index = j; //atribuir o indice do tipo de leitor
                    break;
                }
            }

            if (tipo_livro_index != -1 && tipo_leitor_index != -1){ //verificar se os indices nao sao -1
                contagem_emprestimos[tipo_livro_index][tipo_leitor_index]++; //incrementar o contador de emprestimos
            }
        }
    }

    //imprimir a matriz
    cout << "=== Relatorio de Emprestimos por Tipo de Livro ===" << endl;
    for (size_t i = 0; i < tipo_de_livro.size(); ++i){ //iterar sobre os tipos de livros
        cout << "Tipo de Livro: " << tipo_de_livro[i] << endl;

        //identificar o tipo de leitor que tem mais emprestimos
        int max_emprestimos = 0; //maior numero de emprestimos
        string tipo_leitor_max_emprestimos; //tipo de leitor com mais emprestimos
        for (size_t j = 0; j < tipo_de_leitor.size(); ++j){ //iterar sobre os tipos de leitores
            cout << "Tipo de Leitor: " << tipo_de_leitor[j] << " - Emprestimos: " << contagem_emprestimos[i][j] << endl;
            if (contagem_emprestimos[i][j] > max_emprestimos){ //se o numero de emprestimos do tipo de leitor e maior que o maior numero de emprestimos
                max_emprestimos = contagem_emprestimos[i][j]; //atribuir o numero de emprestimos do tipo de leitor ao maior numero de emprestimos
                tipo_leitor_max_emprestimos = tipo_de_leitor[j]; //atribuir o tipo de leitor ao tipo de leitor com mais emprestimos
            }
        }

        cout << "Tipo de Leitor com mais emprestimos: " << tipo_leitor_max_emprestimos << endl; //Imprime o tipo de leitor com mais emprestimos
        cout << "---------------------------------" << endl;
    }
}

/**
 * @brief Gera um histórico de empréstimos de um leitor.
 *
 * Esta função imprime na consola um histórico detalhado dos empréstimos de um leitor,
 * incluindo o título do livro (ISBN), o nome do leitor e as datas de
 * empréstimo e devolução.
 *
 * O relatório é formatado com uma linha de separação entre cada empréstimo.
 */
void Biblioteca::GerarHistoricoEmprestimosLeitor(Leitor *LT)
{
    //verificar se o leitor existe
    if (!LT){ //Se o leitor não foi encontrado
        cout << "Leitor nao encontrado!" << endl;
        return;
    }

    //verificar se o historico de emprestimos do leitor está vazio
    if (LT->getHistoricoEmprestimos().empty()){ //Se o historico de emprestimos do leitor está vazio
        cout << "Nenhum historico de emprestimos encontrado!" << endl;
        return;
    }

    cout << "=== Historico de Emprestimos do Leitor: " << LT->getNome() << " (ID: " << LT->getID() << ") ===" << endl; //Imprime o nome do leitor

    for (size_t i = 0; i < LT->getHistoricoEmprestimos().size(); ++i){ //iterar sobre os emprestimos
        Emprestimo *emprestimo = LT->getHistoricoEmprestimos()[i]; //obter o emprestimo
        Leitor *leitor = emprestimo->getLeitor(); //obter o leitor do emprestimo
        Livro *livro = emprestimo->getLivro(); //obter o livro do emprestimo
        cout << "Emprestimo #" << i + 1 << endl; //Imprime o numero do emprestimo
        cout << "Livro: " << livro->getTitulo() << " (ISBN: " << livro->getIsbn() << ")" << endl; //Imprime o titulo do livro
        cout << "Leitor: " << leitor->getNome() << " (ID: " << leitor->getID() << ")" << endl; //Imprime o nome do leitor
        cout << "Data de Emprestimo: " << ctime(&emprestimo->dataEmprestimo); //Imprime a data de empréstimo (ctime converte a data para o formato legivel)
        cout << "Data de Devolucao: " << ctime(&emprestimo->dataDevolucao); //Imprime a data de devolução (ctime converte a data para o formato legivel)
        if (emprestimo->estaAtrasado()){ //Se o emprestimo está atrasado
            cout << "Estado: ATRASADO" << endl; //Imprime o estado do emprestimo
            cout << "Multa: " << emprestimo->calcularMulta() << " euros" << endl; //Imprime a multa
        }else{ //Se o emprestimo não está atrasado
            cout << "Estado: DEVOLVIDO" << endl; //Imprime o estado do emprestimo
        }
        cout << "---------------------------------" << endl;
    }
}
