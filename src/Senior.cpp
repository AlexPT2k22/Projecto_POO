#include "Senior.h"
#include <iostream>

/**
 * @brief Construtor da classe Senior.
 * 
 * @param nome O nome do sênior.
 * @param id O ID do sênior.
 */
Senior::Senior(string nome, string id) : Leitor(nome, id) {}

/**
 * @brief Destrutor da classe Senior.
 */
Senior::~Senior() {
    //dtor
}

/**
 * @brief Obtém o limite de empréstimos do sênior.
 * 
 * @return O limite de empréstimos do sênior.
 */
int Senior::getLimiteEmprestimos() const {
    return 8;  // Sêniores podem emprestar até 8 livros
}

/**
 * @brief Obtém o desconto da multa do sênior.
 * 
 * @return O desconto da multa do sênior.
 */
float Senior::getDescontoMulta() const {
    return 0.8f;  // Sêniores têm 80% de desconto na multa
}

/**
 * @brief Verifica se o sênior pode prorrogar o empréstimo.
 * 
 * @return true se o sênior pode prorrogar, false caso contrário.
 */
bool Senior::podeProrrogar() const {
    return false;  // Sêniores nao podem prorrogar
}

/**
 * @brief Exibe uma mensagem a indicar que os usuários sêniores não podem editar as suas informações.
 * 
 * Este método implementa a interface editarInformacoes(), mas restringe os sêniores
 * de modificar suas informações de conta exibindo uma mensagem.
 */
void Senior::editarInformacoes() {
    cout << "Seniores nao podem editar informacoes!" << endl; //mensagem de erro
}

/**
 * @brief Obtém o tipo do sênior.
 * 
 * @return O tipo do sênior.
 */
string Senior::getTipo() const {
    return "Senior"; //retornar o tipo do sênior
}

