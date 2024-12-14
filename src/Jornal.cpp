#include "Jornal.h"
#include "Livro.h"
#include <iostream>
#include <string>

using namespace std;
Jornal::Jornal(string t, string a, string i, string c, int d, int num_copias) : Livro(t, a, i, c, num_copias), Dia(d){
    if (d < 1 || d > 31)    
    {
        cout << "Dia invalido!" << endl;
    }
}

Jornal::~Jornal()
{
}

int Jornal::getDia() const
{
    return Dia;
}

int Jornal::getPrazoEmprestimo() const
{
    return 1;
}

string Jornal::getTipo() const
{
    return "Jornal";
}

bool Jornal::setDia(int d)
{
    if (d >= 1 && d <= 31)
    {
        Dia = d;
        return true;
    }
    else
    {
        cout << "Dia invalido!" << endl;
        return false;
    }
}


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

    switch (opcao){
        case 1:{
            string novaCategoria;
            cout << "Categoria Atual: " << getCategoria() << endl;
            cout << "Nova Categoria: ";
            cin >> novaCategoria;
            setCategoria(novaCategoria);
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 2:{
            string novoAutor;
            cout << "Autor Atual: " << getAutor() << endl;
            cout << "Novo Autor: ";
            cin >> novoAutor;
            setAutor(novoAutor);
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 3:{
            string novoTitulo;
            cout << "Titulo Atual: " << getTitulo() << endl;
            cout << "Novo Titulo: ";
            cin >> novoTitulo;
            setTitulo(novoTitulo);
            cout << "Informacoes atualizadas com sucesso!" << endl;
            break;
        }
        case 4:{
            int novoDia;
            cout << "Dia Atual: " << getDia() << endl;
            cout << "Novo Dia: ";
            cin >> novoDia;
            if (setDia(novoDia) == true)
            {
                cout << "Informacoes atualizadas com sucesso!" << endl;
            }
            break;
        }
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
}