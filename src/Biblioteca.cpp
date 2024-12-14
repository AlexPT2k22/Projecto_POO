#include "Biblioteca.h"
#include "Livro.h"
#include <algorithm>
#include <vector>

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
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
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

/**
 * @brief Sistema de Notificações de Atraso
 *
 * Este método percorre a coleção de requisições (Coleccao_REQ) e verifica se algum livro está atrasado.
 * Para cada livro atrasado, imprime no console as seguintes informações:
 * - Título do livro
 * - Nome do leitor
 * - Data de devolução prevista
 * - Mensagem de atraso e a multa correspondente
 *
 * A estrutura da saída é a seguinte:
 * Livro: [Título do Livro]
 * Leitor: [Nome do Leitor]
 * Data de Devolução Prevista: [Data de Devolução]
 * ATRASADO! Multa: [Valor da Multa]€
 * ---------------------------------
 */
void Biblioteca::Sistema_Notificacoes_Atraso()
{
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
        }
    }
}

/**
 * @brief Lists all the books in the library collection.
 *
 * This function iterates through the collection of books (Coleccao_LIVROS)
 * and prints the details of each book, including the title, author, genre,
 * type, and ISBN. Each book's details are separated by a line of dashes.
 */
void Biblioteca::Listagem_Livros()
{
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

/**
 * @brief Adds a new reader to the library's collection.
 *
 * This function adds a new reader (Leitor) to the end of the library's collection of readers.
 *
 * @param LT A pointer to the Leitor object to be added.
 * @return true Always returns true after adding the reader.
 */
bool Biblioteca::Add_Leitor(Leitor *LT)
{
    Coleccao_LEITORES.push_back(LT); // Adiciona ao final do vetor
    return true;
}

/**
 * @brief Adds a book to the library collection.
 *
 * This function adds a pointer to a Livro object to the Coleccao_LIVROS vector.
 * It uses the push_back method to add the book to the end of the collection.
 *
 * @param L A pointer to the Livro object to be added to the collection.
 * @return true Always returns true.
 */
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
        cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl;
        cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl;
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
    cout << "\n--- Pesquisar livro por tipo: " << tipo << " ---" << endl;
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
    cout << "\n--- Listar livros por categoria: " << categoria << " ---" << endl;
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
                cout << "Reserva #" << j + 1 << endl;
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
