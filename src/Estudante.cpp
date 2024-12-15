#include "Estudante.h"
#include <iostream>

/**
 * @brief Construtor da classe Estudante.
 *
 * @param n Nome do estudante.
 * @param i Identificador do estudante.
 */
Estudante::Estudante(string n, string i) : Leitor(n, i) {
    //ctor 
}

/**
 * @brief Destrutor da classe Estudante.
 */
Estudante::~Estudante() {
    //dtor 
}

/**
 * @brief Obtém o limite de empréstimos do estudante.
 *
 * @return O limite de empréstimos.
 */
int Estudante::getLimiteEmprestimos() const {
    return limiteEmprestimos; // Estudantes podem requisitar até 10 livros
}

/**
 * @brief Obtém o desconto da multa do estudante.
 *
 * @return O desconto da multa.
 */
float Estudante::getDescontoMulta() const {
    return 0.35f; // 35% de desconto
}

/**
 * @brief Verifica se o estudante pode prorrogar o empréstimo.
 *
 * @return true se o estudante pode prorrogar, false caso contrário.
 */
bool Estudante::podeProrrogar() const {
    return true; // Estudantes podem prorrogar
}

/**
 * @brief Edita as informações do estudante.
 */
void Estudante::editarInformacoes() {
    int novolimite; //novo limite de empréstimos
    cout << "Editar Informações de Estudante" << endl;
    cout << "Limite atual de emprestimos: " << getLimiteEmprestimos() << " livros"<< endl; //imprimir o limite atual de empréstimos
    cout << "Novo limite de emprestimos: ";
    cin >> novolimite;

    if (novolimite > 0) { //se o novo limite é maior que 0
        limiteEmprestimos = novolimite; //atribuir o novo limite
    } else {
        cout << "Limite tem que ser maior do que 0!" << endl; //se o novo limite é menor ou igual a 0, imprimir uma mensagem de erro
    }
}

/**
 * @brief Obtém o tipo do leitor.
 *
 * @return O tipo do leitor.
 */
string Estudante::getTipo() const {
    return "Estudante"; //retornar o tipo do leitor
}
