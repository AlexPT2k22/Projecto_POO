#include "Leitor.h"

/**
 * @brief Constructs a new Leitor object with the given name and id.
 * 
 * @param n The name of the Leitor.
 * @param i The id of the Leitor.
 */
Leitor::Leitor(string n, string i) : nome(n), id(i) {
    //ctor
}

/**
 * @brief Destructor for the Leitor class.
 * 
 * This destructor is responsible for cleaning up any resources
 * that the Leitor object may have acquired during its lifetime.
 */
Leitor::~Leitor() {
    //dtor
}

/**
 * @brief Adiciona um empréstimo à lista de empréstimos do leitor.
 * 
 * @param e Ponteiro para o objeto Emprestimo a ser adicionado.
 */
void Leitor::adicionarEmprestimo(Emprestimo* e) {
    emprestimos.push_back(e);  // Adiciona um empréstimo à lista
    historico_emprestimos.push_back(e); // Adiciona o empréstimo ao histórico
}

vector<Emprestimo*> Leitor::getHistoricoEmprestimos() const {
    return historico_emprestimos;
}

/**
 * @brief Remove um empréstimo da lista de empréstimos.
 * 
 * @param e Ponteiro para o objeto Emprestimo a ser removido.
 */
void Leitor::removerEmprestimo(Emprestimo* e) {
    emprestimos.remove(e);  // Remove o empréstimo da lista
}

/**
 * @brief Limpa todos os empréstimos.
 * 
 * Esta função remove todos os elementos do vetor de empréstimos,
 * efetivamente limpando todos os registros de empréstimos.
 */
void Leitor::LimparTodosEmprestimos() {
    emprestimos.clear();  // Limpa todos os empréstimos
}

/**
 * @brief Retrieves the ID of the Leitor object.
 * 
 * @return A string representing the ID of the Leitor.
 */
string Leitor::getID() const {
    return id;
}

/**
 * @brief Retrieves the name of the Leitor.
 * 
 * @return A string containing the name of the Leitor.
 */
string Leitor::getNome() const {
    return nome;
}

list<Emprestimo*> Leitor::getEmprestimos() const {
    return emprestimos;
}