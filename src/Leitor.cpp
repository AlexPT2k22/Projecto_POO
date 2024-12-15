#include "Leitor.h"

/**
 * @brief Construtor da classe Leitor.
 * 
 * @param n O nome do leitor.
 * @param i O ID do leitor.
 */
Leitor::Leitor(string n, string i) : nome(n), id(i) {
    //ctor
}

/**
 * @brief Destrutor da classe Leitor.
 * 
 * Este destrutor é responsável por limpar qualquer recurso
 * que o objeto Leitor possa ter adquirido durante sua vida.
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

/**
 * @brief Obtém o histórico de empréstimos do leitor.
 * 
 * @return Um vetor de ponteiros para objetos Emprestimo.
 */
vector<Emprestimo*> Leitor::getHistoricoEmprestimos() const {
    return historico_emprestimos; //retornar o histórico de empréstimos
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
 * @brief Obtém o ID do objeto Leitor.
 * 
 * @return Uma string representando o ID do Leitor.
 */
string Leitor::getID() const {
    return id; //retornar o ID do leitor
}

/**
 * @brief Obtém o nome do leitor.
 * 
 * @return Uma string contendo o nome do leitor.
 */
string Leitor::getNome() const {
    return nome; //retornar o nome do leitor
}

list<Emprestimo*> Leitor::getEmprestimos() const {
    return emprestimos; //retornar a lista de empréstimos
}