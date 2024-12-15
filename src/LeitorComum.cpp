#include "LeitorComum.h"
#include <iostream>

/**
 * @brief Construtor da classe LeitorComum.
 * 
 * @param n O nome do leitor.
 * @param i O ID do leitor.
 */
LeitorComum::LeitorComum(string n, string i) : Leitor(n, i)
{
    //ctor
}

/**
 * @brief Destrutor da classe LeitorComum.
 */
LeitorComum::~LeitorComum()
{
    //dtor
}

/**
 * @brief Obtém o limite de empréstimos do leitor.
 * 
 * @return O limite de empréstimos.
 */
int LeitorComum::getLimiteEmprestimos() const {
    return 3; //retornar o limite de empréstimos
}

/**
 * @brief Obtém o desconto da multa do leitor.
 * 
 * @return O desconto da multa.
 */
float LeitorComum::getDescontoMulta() const {
    return 0.0f; //retornar o desconto da multa
}

/**
 * @brief Verifica se o leitor pode prorrogar o empréstimo.
 * 
 * @return true se pode prorrogar, false caso contrário.
 */
bool LeitorComum::podeProrrogar() const {
    return false; //retornar false, pois o leitor comum não pode prorrogar
}

/**
 * @brief Edita as informações do leitor.
 */
void LeitorComum::editarInformacoes() {
    cout << "Leitor Comum nao pode editar informacoes!" << endl;
}

/**
 * @brief Obtém o tipo do leitor.
 * 
 * @return O tipo do leitor.
 */
string LeitorComum::getTipo() const {
    return "Comum"; //retornar o tipo do leitor
}
