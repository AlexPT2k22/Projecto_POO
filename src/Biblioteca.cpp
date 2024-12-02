#include "Biblioteca.h"

/**
 * @brief Construct a new Biblioteca object.
 * 
 * This is the default constructor for the Biblioteca class.
 */
Biblioteca::Biblioteca()
{
    //constructor
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
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
        delete Coleccao_LIVROS[i];
    }
    Coleccao_LIVROS.clear();

    for (size_t i = 0; i < Coleccao_LEITORES.size(); ++i) {
        delete Coleccao_LEITORES[i];
    }
    Coleccao_LEITORES.clear();

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) {
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

/**
 * @brief Generates a report of books in the specified category.
 * 
 * This function iterates through the collection of books and prints the details
 * of each book that matches the specified category. The details include the title,
 * author, genre, type, and ISBN of the book.
 * 
 * @param categoria The category of books to generate the report for.
 */
void Biblioteca::RelatorioCategoria(string categoria)
{
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
        if (Coleccao_LIVROS[i]->getTipo() == categoria) {
            cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl;
            cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl;
            cout << "Genero: " << Coleccao_LIVROS[i]->getTipo() << endl;
            cout << "Tipo: " << Coleccao_LIVROS[i]->getTipo() << endl;
            cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl;
            cout << "---------------------------------" << endl;
        }
    }
}

void Biblioteca::Prorrogacao_Emprestimos()
{
    
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
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) {
        if (Coleccao_REQ[i]->estaAtrasado()) {
            cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl;
            cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl;
            cout << "Data de Devolução Prevista: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
            cout << "ATRASADO! Multa: " << Coleccao_REQ[i]->calcularMulta() << "€" << endl;
            cout << "---------------------------------" << endl;
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
    for (size_t i = 0; i < Coleccao_LIVROS.size(); ++i) {
        cout << "Titulo: " << Coleccao_LIVROS[i]->getTitulo() << endl;
        cout << "Autor: " << Coleccao_LIVROS[i]->getAutor() << endl;
        cout << "Genero: " << Coleccao_LIVROS[i]->getTipo() << endl;
        cout << "Tipo: " << Coleccao_LIVROS[i]->getTipo() << endl;
        cout << "ISBN: " << Coleccao_LIVROS[i]->getIsbn() << endl;
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
bool Biblioteca::Add_Livro(Livro *L){
    Coleccao_LIVROS.push_back(L); // Usar push_back para adicionar no final
    return true;
}

/**
 * @brief Adds a new loan (Emprestimo) to the collection.
 * 
 * This function creates a new loan (Emprestimo) object using the provided
 * book (Livro) and reader (Leitor) pointers, and then adds it to the 
 * collection of loans (Coleccao_REQ).
 * 
 * @param L Pointer to the book (Livro) that is being loaned.
 * @param LT Pointer to the reader (Leitor) who is borrowing the book.
 */
void Biblioteca::Add_Emprestimo(Livro *L, Leitor *LT)
{
    Emprestimo* emprestimo = new Emprestimo(L, LT);
    Coleccao_REQ.push_back(emprestimo);
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
    if (!E) {
        cout << "Emprestimo invalido!" << endl;
        return;
    }

    Leitor* leitor = E->getLeitor();
    if (leitor) {
        leitor->removerEmprestimo(E);
    }

    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) {
        if (Coleccao_REQ[i] == E) {
            Coleccao_REQ.erase(Coleccao_REQ.begin() + i);
            break;
        }
    }

    float multa = E->calcularMulta();
    if (multa > 0) {
        cout << "Livro devolvido com atraso! Multa: " << multa << "€" << endl;
    } else {
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
    cout << "=== Relatório de Empréstimos Atuais ===" << endl;
    for (size_t i = 0; i < Coleccao_REQ.size(); ++i) {
        cout << "Livro: " << Coleccao_REQ[i]->getLivro()->getTitulo() << endl;
        cout << "Leitor: " << Coleccao_REQ[i]->getLeitor()->getNome() << endl;
        cout << "Data de Empréstimo: " << ctime(&Coleccao_REQ[i]->dataEmprestimo);
        cout << "Data de Devolução: " << ctime(&Coleccao_REQ[i]->dataDevolucao);
        cout << "---------------------------------" << endl;
    }
}