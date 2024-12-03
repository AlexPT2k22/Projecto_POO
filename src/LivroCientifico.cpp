#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(string t, string a, string i, string c) : Livro(t, a, i, c)
{
    //ctor
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

string LivroCientifico::getTipo() const
{
    return "Cientifico";
}

int LivroCientifico::getPrazoEmprestimo() const
{
    return 15;
}

void LivroCientifico::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Categoria" << endl;
    cout << "2 - Autor" << endl;
    cout << "3 - ISBN" << endl;
    cout << "4 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:{
        string novaCategoria;
        cout << "Categoria Atual: " << getCategoria() << endl;
        cout << "Nova Categoria: ";
        cin.ignore();
        getline(cin, novaCategoria);
        setCategoria(novaCategoria);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 2:{
        string novoAutor;
        cout << "Autor Atual: " << getAutor() << endl;
        cout << "Novo Autor: ";
        cin.ignore();
        getline(cin, novoAutor);
        setAutor(novoAutor);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 3:{
        string novoIsbn;
        cout << "ISBN Atual: " << getIsbn() << endl;
        cout << "Novo ISBN: ";
        cin.ignore();
        getline(cin, novoIsbn);
        setIsbn(novoIsbn);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 4:{
        string novoTitulo;
        cout << "Titulo Atual: " << getTitulo() << endl;
        cout << "Novo Titulo: ";
        cin.ignore();
        getline(cin, novoTitulo);
        setTitulo(novoTitulo);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    default:
        cout << "Opcao invalida!" << endl;
        break;
    }
}