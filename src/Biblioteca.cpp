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
 * @brief Construct a new Biblioteca object.
 *
 * This is the default constructor for the Biblioteca class.
 */
Biblioteca::Biblioteca()
{
    // constructor
}

/**
 * @brief Destructor for the Biblioteca class.
 *
 * This destructor is responsible for cleaning up dynamically allocated memory
 * associated with the Biblioteca object. It iterates through the collections
 * of books, readers, and requests, deleting each dynamically allocated object
 * and then clearing the collections.
 *
 * The collections being cleaned up are:
 * - Coleccao_LIVROS: A collection of pointers to dynamically allocated book objects.
 * - Coleccao_LEITORES: A collection of pointers to dynamically allocated reader objects.
 * - Coleccao_REQ: A collection of pointers to dynamically allocated request objects.
 */
Biblioteca::~Biblioteca()
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        delete Coleccao_LIVROS[i];
    }
    Coleccao_LIVROS.clear();

    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i)
    {
        delete Coleccao_LEITORES[i];
    }
    Coleccao_LEITORES.clear();

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i)
    {
        delete Coleccao_REQ[i];
    }
    Coleccao_REQ.clear();
}

bool Biblioteca::SaveToFile(string nf)
{
    nf += ".csv";
    ofstream file(nf);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o ficheiro para escrita!" << endl;
        return false;
    }

    // Salvar livros
    file << "LIVROS" << endl;
    file << "TIPO,TITULO,AUTOR,ISBN,CATEGORIA,COPIAS,COPIAS_EMPRESTADAS,INFO_ADICIONAL" << endl;
    for (size_t i = 0; i < Coleccao_LIVROS.size(); i++) {
        Livro* livro = Coleccao_LIVROS[i];
        file << livro->getTipo() << ","
             << livro->getTitulo() << ","
             << livro->getAutor() << ","
             << livro->getIsbn() << ","
             << livro->getCategoria() << ","
             << livro->getNumCopias() << ","
             << livro->getCopiasDisponiveis() << ",";

        // Informação adicional específica para cada tipo
        if (LivroEducativo* livroEd = dynamic_cast<LivroEducativo*>(livro)) {
            file << livroEd->getGrauEscolaridade();
        }
        else if (Revista* revista = dynamic_cast<Revista*>(livro)) {
            file << revista->getEdicao();
        }
        else if (Jornal* jornal = dynamic_cast<Jornal*>(livro)) {
            file << jornal->getDia();
        }
        file << endl;
    }

    // Cabeçalho dos leitores
    file << "\nLEITORES" << endl;
    file << "TIPO,NOME,ID" << endl;
    for (size_t i = 0; i < Coleccao_LEITORES.size(); i++) {
        Leitor* leitor = Coleccao_LEITORES[i];
        file << leitor->getTipo() << ","
             << leitor->getNome() << ","
             << leitor->getID() << endl;
    }

    // Salvar empréstimos
    file << "\nEMPRESTIMOS" << endl;
    file << "ISBN,ID_LEITOR,DATA_EMPRESTIMO,DATA_DEVOLUCAO" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); i++) {
        Emprestimo* emp = Coleccao_REQ[i];
        char data_emp[26], data_dev[26]; 
        strftime(data_emp, sizeof(data_emp), "%Y-%m-%d %H:%M:%S", localtime(&emp->dataEmprestimo)); // %Y-%m-%d %H:%M:%S
        strftime(data_dev, sizeof(data_dev), "%Y-%m-%d %H:%M:%S", localtime(&emp->dataDevolucao));    // %Y-%m-%d %H:%M:%S
    
        file << emp->getLivro()->getIsbn() << ","
                << emp->getLeitor()->getID() << ","
                << data_emp << ","
                << data_dev << endl;
    }

    // Salvar reservas (fora do loop de livros)
    file << "\nRESERVAS" << endl;
    file << "ISBN,ID_LEITOR" << endl;
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
        for (size_t j = 0; j < Coleccao_LIVROS[i]->reservas.size(); ++j) {
            file << Coleccao_LIVROS[i]->getIsbn() << "," << Coleccao_LIVROS[i]->reservas[j]->getID() << endl;
        }
    }

    file.close();
    cout << "Ficheiro exportado com sucesso!" << endl;
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    nf += ".csv";
    ifstream file(nf);
    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo para leitura!" << endl;
        return false;
    }

    // Limpar coleções existentes
    for (size_t i = 0; i < Coleccao_LIVROS.size(); i++) delete Coleccao_LIVROS[i];
    for (size_t i = 0; i < Coleccao_LEITORES.size(); i++) delete Coleccao_LEITORES[i];
    for (size_t i = 0; i < Coleccao_REQ.size(); i++) delete Coleccao_REQ[i];
    
    Coleccao_LIVROS.clear();
    Coleccao_LEITORES.clear();
    Coleccao_REQ.clear();

    string line;
    string section;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == "LIVROS" || line == "LEITORES" || line == "EMPRESTIMOS" || line == "RESERVAS") {
            section = line;
            getline(file, line); // Pular cabeçalho
            continue;
        }

        stringstream ss(line);
        
        if (section == "LIVROS") {
            string tipo, titulo, autor, isbn, categoria, copias_str, copias_emp_str, info;
            getline(ss, tipo, ',');
            getline(ss, titulo, ',');
            getline(ss, autor, ',');
            getline(ss, isbn, ',');
            getline(ss, categoria, ',');
            getline(ss, copias_str, ',');
            getline(ss, copias_emp_str, ',');
            getline(ss, info);

            int copias = stoi(copias_str); // stoi converte string para int
            Livro* livro = nullptr;

            if (tipo == "Cientifico") {
                livro = new LivroCientifico(titulo, autor, isbn, categoria, copias);
            } 
            else if (tipo == "Educacional") {
                livro = new LivroEducativo(titulo, autor, isbn, categoria, info, copias);
            } 
            else if (tipo == "Ficcao") {
                livro = new LivroFiccao(titulo, autor, isbn, categoria, copias);
            } 
            else if (tipo == "Revista") {
                livro = new Revista(titulo, autor, isbn, categoria, stoi(info), copias);
            } 
            else if (tipo == "Jornal") {
                livro = new Jornal(titulo, autor, isbn, categoria, stoi(info), copias);
            }

            if (livro) {
                Coleccao_LIVROS.push_back(livro);
            }
        }
        else if (section == "LEITORES") {
            string tipo, nome, id;
            getline(ss, tipo, ',');
            getline(ss, nome, ',');
            getline(ss, id);

            Leitor* leitor = nullptr;
            if (tipo == "Comum") leitor = new LeitorComum(nome, id);
            else if (tipo == "Estudante") leitor = new Estudante(nome, id);
            else if (tipo == "Professor") leitor = new Professor(nome, id);
            else if (tipo == "Senior") leitor = new Senior(nome, id);

            if (leitor) Coleccao_LEITORES.push_back(leitor);
        }
        else if (section == "EMPRESTIMOS") {
            string isbn, id_leitor, data_emp_str, data_dev_str;
            getline(ss, isbn, ',');
            getline(ss, id_leitor, ',');
            getline(ss, data_emp_str, ',');
            getline(ss, data_dev_str);

            Livro* livro = nullptr;
            Leitor* leitor = nullptr;

            for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
                if (Coleccao_LIVROS[i]->getIsbn() == isbn) {
                    livro = Coleccao_LIVROS[i];
                    break;
                }
            }

            for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) {
                if (Coleccao_LEITORES[i]->getID() == id_leitor) {
                    leitor = Coleccao_LEITORES[i];
                    break;
                }
            }

            if (livro && leitor) {
                Emprestimo* emp = new Emprestimo(livro, leitor);
                struct tm tm_emp = {0}, tm_dev = {0};
                sscanf(data_emp_str.c_str(), "%d-%d-%d %d:%d:%d",
                    &tm_emp.tm_year, &tm_emp.tm_mon, &tm_emp.tm_mday,
                    &tm_emp.tm_hour, &tm_emp.tm_min, &tm_emp.tm_sec);
                tm_emp.tm_year -= 1900;
                tm_emp.tm_mon -= 1;
                emp->dataEmprestimo = mktime(&tm_emp);

                sscanf(data_dev_str.c_str(), "%d-%d-%d %d:%d:%d",
                    &tm_dev.tm_year, &tm_dev.tm_mon, &tm_dev.tm_mday,
                    &tm_dev.tm_hour, &tm_dev.tm_min, &tm_dev.tm_sec);
                tm_dev.tm_year -= 1900;
                tm_dev.tm_mon -= 1;
                emp->dataDevolucao = mktime(&tm_dev);

                Coleccao_REQ.push_back(emp);
                leitor->adicionarEmprestimo(emp);
                livro->emprestar_Copia();
            }
        }
        else if (section == "RESERVAS") {
            string isbn, id_leitor;
            getline(ss, isbn, ',');
            getline(ss, id_leitor);

            Livro* livro = nullptr;
            Leitor* leitor = nullptr;

            // Encontrar o livro
            for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
                if (Coleccao_LIVROS[i]->getIsbn() == isbn) {
                    livro = Coleccao_LIVROS[i];
                    //cout << "Livro encontrado: " << livro->getTitulo() << endl;
                    break;
                }
            }

            // Encontrar o leitor
            for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) {
                if (Coleccao_LEITORES[i]->getID() == id_leitor) {
                    leitor = Coleccao_LEITORES[i];
                    //cout << "Leitor encontrado: " << leitor->getNome() << endl;
                    break;
                }
            }

            if (livro && leitor) {
                livro->adicionar_Reserva(leitor);
                //cout << "Reserva carregada: " << livro->getTitulo() << " para " << leitor->getNome() << endl;
            }
        }
    }

    file.close();
    cout << "Arquivo carregado com sucesso!" << endl;
    return true;
}

void Biblioteca::Prorrogacao_Emprestimos(string id, string isbn)
{
    Emprestimo *emprestimo = nullptr;

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i)
    {
        if (Coleccao_REQ[i]->getLivro()->getIsbn() == isbn && Coleccao_REQ[i]->getLeitor()->getID() == id)
        {
            emprestimo = Coleccao_REQ[i];
            break;
        }
    }

    if (!emprestimo)
    {
        cout << "Emprestimo nao encontrado!" << endl;
        return;
    }

    if (emprestimo->getLeitor()->podeProrrogar())
    {
        emprestimo->prorrogarEmprestimo();
        cout << "Emprestimo prorrogado com sucesso!" << endl;
    }
    else
    {
        cout << "Leitor do tipo " << emprestimo->getLeitor()->getTipo() << " nao pode prorrogar emprestimos!" << endl;
    }
}


void Biblioteca::Sistema_Notificacoes_Atraso()
{
    cout << "=== Sistema de Notificacoes de Atraso ===" << endl;
    if (Coleccao_REQ.size() == 0)
    {
        cout << "Nenhum livro atrasado!" << endl;
    }

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i)
    {
        if (Coleccao_REQ[i]->estaAtrasado())
        {
            if (Coleccao_REQ[i]->getLeitor()->podeProrrogar() == true)
            {
                cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl;
                cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl;
                cout << "Data de Devolucao Prevista: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
                cout << "ATRASADO! Multa: " << Coleccao_REQ[i]->calcularMulta() << " euros" << endl;
                cout << "AVISO: Pode prorrogar o seu emprestimo!" << endl;
                cout << "---------------------------------" << endl;
            }else{
                cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl;
                cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl;
                cout << "Data de Devolucao Prevista: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
                cout << "ATRASADO! Multa: " << Coleccao_REQ[i]->calcularMulta() << " euros" << endl;
                cout << "Multa acresce em 1 euro por dia de atraso!" << endl;
                cout << "---------------------------------" << endl;
            }
        }else{
            cout << "Nenhum livro atrasado!" << endl;
        }
    }
}


void Biblioteca::Listagem_Livros()
{
    cout << "=== Listagem de Livros ===" << endl;
    if (Coleccao_LIVROS.size() == 0)
    {
        cout << "Nenhum livro na colecao!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl;
        cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl;
        cout << "Genero: " << Coleccao_LIVROS[i]->getCategoria() << endl;
        cout << "Tipo: " << Coleccao_LIVROS[i]->getTipo() << endl;
        cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl;
        cout << "Numero de copias: " << Coleccao_LIVROS[i]->getNumCopias() << endl;
        cout << "Numero de copias disponiveis: " << Coleccao_LIVROS[i]->getCopiasDisponiveis() << endl;
        cout << "---------------------------------" << endl;
    }
}


bool Biblioteca::Add_Leitor(Leitor *LT)
{
    Coleccao_LEITORES.push_back(LT); // Adiciona ao final do vetor
    return true;
}


bool Biblioteca::Add_Livro(Livro *L)
{
    // apenas as cópias podem ter o mesmo isbn
    if (Coleccao_LIVROS.size() > 0)
    {
        for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
        {
            if (Coleccao_LIVROS[i]->getIsbn() == L->getIsbn())
            {
                cout << "Livro com ISBN " << L->getIsbn() << " ja existe!" << endl;
                return false;
            }
        }
    }
    Coleccao_LIVROS.push_back(L);
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
    if (!L)
    {
        cout << "Livro nao encontrado!" << endl;
        return;
    }

    if (!LT)
    {
        cout << "Leitor nao encontrado!" << endl;
        return;
    }

    // Verificar se há cópias disponíveis
    if (!L->emprestar_Copia())
    {
        cout << "Nao ha copias disponiveis para o livro: " << L->getTitulo() << endl;
        cout << "Deseja realizar uma reserva (S/N)? ";
        string resposta;
        cin >> resposta;
        if (resposta == "S" || resposta == "s")
        {
            reservarLivro(L->getIsbn(), LT);
        }
        else
        {
            cout << "Emprestimo nao realizado!" << endl;
        }
        return;
    }

    // Criar o empréstimo e associá-lo ao leitor e à coleção de empréstimos
    Emprestimo *emprestimo = new Emprestimo(L, LT);
    Coleccao_REQ.push_back(emprestimo);
    LT->adicionarEmprestimo(emprestimo);

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
    if (!E)
    {
        cout << "Emprestimo invalido!" << endl;
        return;
    }

    Livro *livro = E->getLivro();
    Leitor *leitorAtual = E->getLeitor();

    if (leitorAtual)
    {
        leitorAtual->removerEmprestimo(E);
    }

    Coleccao_REQ.erase(std::remove(Coleccao_REQ.begin(), Coleccao_REQ.end(), E), Coleccao_REQ.end()); // remove o empréstimo da coleção

    livro->devolver_Copia();

    if (livro->temReserva())
    {
        Leitor *proximoLeitor = livro->Proximo_Leitor_Reserva();
        cout << "Livro reservado para o proximo leitor: " << proximoLeitor->getNome() << " com ID: " << proximoLeitor->getID() << endl;
        livro->remover_Reserva(proximoLeitor);
        cout << "Realizar emprestimo para o leitor " << proximoLeitor->getNome() << " com ID " << proximoLeitor->getID() << "? (S/N): ";
        string resposta;
        cin >> resposta;
        if (resposta == "S" || resposta == "s")
        {
            Add_Emprestimo(livro, proximoLeitor);
        }
        else
        {
            cout << "Emprestimo nao realizado!" << endl;
        }
    }

    // multa
    float multa = E->calcularMulta();
    if (multa > 0)
    {
        cout << "Livro devolvido com atraso! Multa: " << multa << " euros" << endl;
    }
    else
    {
        cout << "Livro devolvido dentro do prazo!" << endl;
    }

    delete E;
}

/**
 * @brief Gera um relatório dos empréstimos atuais na biblioteca.
 *
 * Esta função imprime no console um relatório detalhado dos empréstimos
 * atuais, incluindo o título do livro, o nome do leitor, a data de
 * empréstimo e a data de devolução.
 *
 * O relatório é formatado com uma linha de separação entre cada empréstimo.
 */
void Biblioteca::Gerar_RelatorioEmprestimos()
{
    cout << "=== Relatorio de Emprestimos Atuais ===" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i)
    {
        cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << " (ISBN: " << Coleccao_REQ[i]->getLivro()->getIsbn() << ")" << endl;
        cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << " (ID: " << Coleccao_REQ[i]->getLeitor()->getID() << ")" << endl;
        cout << "Data de Emprestimo: " << ctime(&Coleccao_REQ[i]->dataEmprestimo);
        cout << "Data de Devolucao: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
        cout << "---------------------------------" << endl;
    }
}

/**
 * @brief Edita as informações de um leitor na coleção de leitores.
 *
 * Esta função percorre a coleção de leitores (Coleccao_LEITORES) e procura
 * um leitor com o ID fornecido. Se encontrar, chama a função editarInformacoes()
 * desse leitor para permitir a edição das suas informações. Caso contrário,
 * imprime uma mensagem indicando que o leitor não foi encontrado.
 *
 * @param id O ID do leitor cujas informações devem ser editadas.
 */
void Biblioteca::Editar_InformacoesLeitores(string id)
{
    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i)
    {
        if (Coleccao_LEITORES[i]->getID() == id)
        {
            Coleccao_LEITORES[i]->editarInformacoes();
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
    cout << "\nPesquisar livro por tipo: " << tipo << " ---" << endl;
    bool encontrado = false;

    if (Coleccao_LIVROS.size() == 0)
    {
        cout << "Nenhum livro encontrado!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getTipo() == tipo)
        {
            encontrado = true;
            cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl;
            cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl;
            cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl;
            cout << "---------------------------------" << endl;
        }
    }

    if (!encontrado)
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
    cout << "\nListar livros por categoria: " << categoria << " ---" << endl;
    bool encontrado = false;

    if (Coleccao_LIVROS.size() == 0)
    {
        cout << "Nenhum livro encontrado!" << endl;
    }

    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getCategoria() == categoria)
        {
            encontrado = true;
            cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl;
            cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl;
            cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl;
            cout << "---------------------------------" << endl;
        }
    }

    if (!encontrado)
    {
        cout << "Nenhum livro encontrado!" << endl;
    }
}

void Biblioteca::Editar_InformacoesLivros(string isbn)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn)
        {
            cout << "A atualizar informacoes do livro: " << Coleccao_LIVROS[i]->getTitulo() << endl;
            Coleccao_LIVROS[i]->EditarInformacoesLivro();
            return;
        }
    }

    cout << "Livro nao encontrado!" << endl;
}

void Biblioteca::Remover_Leitor(string id)
{
    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i)
    {
        if (Coleccao_LEITORES[i]->getID() == id)
        {
            if (!Coleccao_LEITORES[i]->getEmprestimos().empty())
            {
                cout << "Erro: O leitor ainda possui empréstimos pendentes e nao pode ser removido!" << endl;
                return;
            }

            cout << "Removendo leitor: " << Coleccao_LEITORES[i]->getNome() << endl;
            delete Coleccao_LEITORES[i];
            Coleccao_LEITORES.erase(Coleccao_LEITORES.begin() + i);
            cout << "Leitor removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Leitor com ID " << id << " nao encontrado!" << endl;
}

void Biblioteca::Remover_Livro(string isbn)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn)
        {
            for (size_t j = 0; j < Coleccao_REQ.size(); ++j)
            {
                if (Coleccao_REQ[j]->getLivro()->getIsbn() == isbn)
                {
                    cout << "Erro: O livro está associado a um empréstimo ativo e não pode ser removido!" << endl;
                    return;
                }
            }

            cout << "Removendo livro: " << Coleccao_LIVROS[i]->getTitulo() << endl;
            delete Coleccao_LIVROS[i];                          // Libera a memória do livro
            Coleccao_LIVROS.erase(Coleccao_LIVROS.begin() + i); // Remove do vetor
            cout << "Livro removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Livro com ISBN " << isbn << " nao encontrado!" << endl;
}

void Biblioteca::reservarLivro(string isbn, Leitor *LT)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn)
        {
            Livro *livro = Coleccao_LIVROS[i];

            bool emprestado = false;
            for (size_t j = 0; j < Coleccao_REQ.size(); ++j)
            {
                if (Coleccao_REQ[j]->getLivro() == livro)
                {
                    emprestado = true;
                    break;
                }
            }
            if (!emprestado)
            {
                cout << "Livro nao disponivel para reserva pois nao esta emprestado!" << endl;
                return;
            }
            else
            {
                livro->adicionar_Reserva(LT);
                cout << "Livro reservado com sucesso para o leitor: " << LT->getNome() << endl;
                return;
            }
        }
    }
    cout << "Livro com ISBN " << isbn << " nao encontrado!" << endl;
}

void Biblioteca::cancelar_reserva(string isbn, string id)
{
    Livro *livro = nullptr;
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i)
    {
        if (Coleccao_LIVROS[i]->getIsbn() == isbn)
        {
            livro = Coleccao_LIVROS[i];
            break;
        }
    }
    if (!livro)
    {
        cout << "Livro com ISBN " << isbn << " e titulo " << livro->getTitulo() << " nao encontrado!" << endl;
        return;
    }
    Leitor *leitor = nullptr;
    for (size_t i = 0; i < livro->reservas.size(); ++i)
    {
        if (livro->reservas[i]->getID() == id)
        {
            leitor = livro->reservas[i];
            break;
        }
    }
    if (!leitor)
    {
        cout << "Reserva nao encontrada para o leitor: " << leitor->getNome() << endl;
        return;
    }
    livro->remover_Reserva(leitor);
}

void Biblioteca::ListarReservas()
{
    int reservas_encontradas = 0;
    cout << "=== Lista de Reservas ===" << endl;

    // verificar se tem reservas
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) // iterar sobre os livros
    { 
        if (Coleccao_LIVROS[i]->reservas.size() > 0) // verificar se o livro tem reservas
        { 
            reservas_encontradas++;
            for (size_t j = 0; j < Coleccao_LIVROS[i]->reservas.size(); ++j) // iterar sobre as reservas do livro
            { 
                cout << "Reserva #" << reservas_encontradas << endl;
                cout << "Livro: " << Coleccao_LIVROS[i]->getTitulo() << " (ISBN: " << Coleccao_LIVROS[i]->getIsbn() << ")" << endl; // imprimir o titulo do livro
                cout << "Leitor: " << Coleccao_LIVROS[i]->reservas[j]->getNome() << " (ID: " << Coleccao_LIVROS[i]->reservas[j]->getID() << ")" << endl; // imprimir o nome do leitor
                cout << "---------------------------------" << endl;
            }
        }
    }
    if (reservas_encontradas == 0)
    {
        cout << "Nenhuma reserva encontrada!" << endl;
    }
}

void Biblioteca::GerarRelatorioMultasPendentes()
{
    int multas_encontradas = 0;
    cout << "=== Relatorio de Multas Pendentes ===" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i)
    {
        if (Coleccao_REQ[i]->estaAtrasado())
        {
            int multa = Coleccao_REQ[i]->calcularMulta();
            multas_encontradas++;
            cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << " (ISBN: " << Coleccao_REQ[i]->getLivro()->getIsbn() << ")" << endl;
            cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << " (ID: " << Coleccao_REQ[i]->getLeitor()->getID() << ")" << " (Tipo: " << Coleccao_REQ[i]->getLeitor()->getTipo() << ")" << endl;
            cout << "Desconto: " << Coleccao_REQ[i]->getLeitor()->getDescontoMulta() * 100 << "%" << endl;
            cout << "Data de Emprestimo: " << ctime(&Coleccao_REQ[i]->dataEmprestimo);
            cout << "Data de Devolucao: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
            cout << "Multa: " << multa << " euros" << endl;
            cout << "---------------------------------" << endl;
        }
    }
    if (multas_encontradas == 0)
    {
        cout << "Nenhuma multa encontrada!" << endl;
    }
}

void Biblioteca::GerarRelatorioEmprestimosPorTipo()
{
    vector<string> tipo_de_livro = {"Cientifico", "Educacional", "Ficcao", "Revista", "Jornal"};
    vector<string> tipo_de_leitor = {"Estudante", "Professor", "LeitorComum", "Senior"};

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
        int max_emprestimos = 0;
        string tipo_leitor_max_emprestimos;
        for (size_t j = 0; j < tipo_de_leitor.size(); ++j){
            cout << "Tipo de Leitor: " << tipo_de_leitor[j] << " - Emprestimos: " << contagem_emprestimos[i][j] << endl;
            if (contagem_emprestimos[i][j] > max_emprestimos){
                max_emprestimos = contagem_emprestimos[i][j];
                tipo_leitor_max_emprestimos = tipo_de_leitor[j];
            }
        }

        cout << "Tipo de Leitor com mais emprestimos: " << tipo_leitor_max_emprestimos << endl;
        cout << "---------------------------------" << endl;
    }
}

void Biblioteca::GerarHistoricoEmprestimosLeitor(Leitor *LT)
{
    if (!LT){
        cout << "Leitor nao encontrado!" << endl;
        return;
    }

    if (LT->getHistoricoEmprestimos().empty()){
        cout << "Nenhum historico de emprestimos encontrado!" << endl;
        return;
    }

    cout << "=== Historico de Emprestimos do Leitor: " << LT->getNome() << " (ID: " << LT->getID() << ") ===" << endl;

    for (size_t i = 0; i < LT->getHistoricoEmprestimos().size(); ++i){
        Emprestimo *emprestimo = LT->getHistoricoEmprestimos()[i];
        Leitor *leitor = emprestimo->getLeitor();
        Livro *livro = emprestimo->getLivro();
        cout << "Emprestimo #" << i + 1 << endl;
        cout << "Livro: " << livro->getTitulo() << " (ISBN: " << livro->getIsbn() << ")" << endl;
        cout << "Leitor: " << leitor->getNome() << " (ID: " << leitor->getID() << ")" << endl;
        cout << "Data de Emprestimo: " << ctime(&emprestimo->dataEmprestimo);
        cout << "Data de Devolucao: " << ctime(&emprestimo->dataDevolucao);
        if (emprestimo->estaAtrasado()){
            cout << "Estado: ATRASADO" << endl;
            cout << "Multa: " << emprestimo->calcularMulta() << " euros" << endl;
        }else{
            cout << "Estado: DEVOLVIDO" << endl;
        }
        cout << "---------------------------------" << endl;
    }
}
