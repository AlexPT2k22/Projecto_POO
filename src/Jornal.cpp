#include "Jornal.h"
#include "Livro.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Construtor da classe Jornal.
 *
 * @param t Titulo do jornal.
 * @param a Autor do jornal.
 * @param i Identificador do jornal.
 * @param c Categoria do jornal.
 * @param d Dia do jornal.
 * @param num_copias Numero de copias do jornal.
 */
Jornal::Jornal(string t, string a, string i, string c, int d, int num_copias) : Livro(t, a, i, c, num_copias), Dia(d){
    if (d < 1 || d > 31)    
    {
        cout << "Dia invalido!" << endl; //se o dia é menor que 1 ou maior que 31, imprimir uma mensagem de erro
    }
}

/**
 * @brief Destrutor da classe Jornal.
 */
Jornal::~Jornal()
{
}

/**
 * @brief Obtém o dia do jornal.
 *
 * @return O dia do jornal.
 */
int Jornal::getDia() const
{
    return Dia; //retornar o dia do jornal
}

/**
 * @brief Obtém o prazo de empréstimo do jornal.
 *
 * @return O prazo de empréstimo do jornal.
 */
int Jornal::getPrazoEmprestimo() const
{
    return 1; //retornar o prazo de empréstimo do jornal
}

/**
 * @brief Obtém o tipo do jornal.
 *
 * @return O tipo do jornal.
 */
string Jornal::getTipo() const
{
    return "Jornal"; //retornar o tipo do jornal
}

/**
 * @brief Define o dia do jornal.
 *
 * @param d O novo dia do jornal.
 * @return true se o dia é válido, false caso contrário.
 */
bool Jornal::setDia(int d)
{
    if (d >= 1 && d <= 31) //se o dia é maior ou igual a 1 e menor ou igual a 31
    {
        Dia = d; //atribuir o novo dia
        return true; //retornar true
    }
    else
    {
        cout << "Dia invalido!" << endl; //se o dia é menor que 1 ou maior que 31, imprimir uma mensagem de erro
        return false; //retornar false
    }
}

/**
 * @brief Edita as informações do jornal.
 */
void Jornal::EditarInformacoesLivro()
{
    int opcao;
    cout << "O que deseja editar?";
    cout << "1 - Categoria" << endl;
    cout << "2 - Autor" << endl;
    cout << "3 - Titulo" << endl;
    cout << "4 - Dia" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao){ //switch para escolher a opção de edição
        case 1:{
            string novaCategoria; //nova categoria
            cout << "Categoria Atual: " << getCategoria() << endl; //imprimir a categoria atual
            cout << "Nova Categoria: ";
            cin >> novaCategoria;
            setCategoria(novaCategoria); //atribuir a nova categoria
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 2:{
            string novoAutor; //novo autor
            cout << "Autor Atual: " << getAutor() << endl; //imprimir o autor atual
            cout << "Novo Autor: ";
            cin >> novoAutor;
            setAutor(novoAutor); //atribuir o novo autor
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 3:{
            string novoTitulo; //novo titulo
            cout << "Titulo Atual: " << getTitulo() << endl; //imprimir o titulo atual
            cout << "Novo Titulo: ";
            cin >> novoTitulo;
            setTitulo(novoTitulo); //atribuir o novo titulo
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 4:{
            int novoDia; //novo dia
            cout << "Dia Atual: " << getDia() << endl; //imprimir o dia atual
            cout << "Novo Dia: ";
            cin >> novoDia;
            if (setDia(novoDia) == true) //se o dia é válido
            {
                cout << "Informacoes atualizadas com sucesso!" << endl;
            }
            break;
        }
        default:
            cout << "Opcao invalida!" << endl; //se a opção é inválida, imprimir uma mensagem de erro
            break;
        }
}