#include "Professor.h"
#include <iostream>

/**
 * @brief Construtor da classe Professor.
 * 
 * @param n O nome do professor.
 * @param i O ID do professor.
 */
Professor::Professor(string n, string i) : Leitor(n, i)
{
    //ctor
}

/**
 * @brief Destrutor da classe Professor.
 */
Professor::~Professor()
{
    //dtor
}

/**
 * @brief Obtém o limite de empréstimos do professor.
 * 
 * @return O limite de empréstimos do professor.
 */
int Professor::getLimiteEmprestimos() const
{
    return 20; // Professores podem requisitar até 20 livros
}

/**
 * @brief Obtém o desconto de multa do professor.
 * 
 * @return O desconto de multa do professor.
 */
float Professor::getDescontoMulta() const
{
    return descontoMulta; //retornar o desconto de multa referido na classe professor
}

/**
 * @brief Verifica se o professor pode prorrogar o empréstimo.
 * 
 * @return true se o professor pode prorrogar, false caso contrário.
 */
bool Professor::podeProrrogar() const
{
    return true; //professores podem prorrogar
}

/**
 * @brief Edita as informações do professor.
 */
void Professor::editarInformacoes()
{
     float novoDesconto; //novo desconto
    cout << "Editar Informacoes de Professor" << endl;
    cout << "Desconto atual em multas: " << getDescontoMulta() * 100 << "%" << endl; //desconto atual em multas
    cout << "Novo desconto (em %): ";
    cin >> novoDesconto;

    if (novoDesconto >= 0 && novoDesconto <= 100) //verificar se o desconto é valido
    {
        descontoMulta = novoDesconto / 100.0f; // Converter para decimal
    }
    else
    {
        cout << "Desconto tem que ser entre 0 e 100%!" << endl; //desconto invalido
    }
}

/**
 * @brief Obtém o tipo do professor.
 * 
 * @return O tipo do professor.
 */
string Professor::getTipo() const {
    return "Professor"; //retornar o tipo do professor
}

