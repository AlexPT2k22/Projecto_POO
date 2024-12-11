#include "Revista.h"

Revista::Revista(string t, string a, string i, string c, string e, int numCopias) : Livro(t, a, i, c, numCopias), edicao(e)
{
    //ctor
}

Revista::~Revista()
{
    //dtor
}

string Revista::getEdicao() const
{
    return edicao;
}

int Revista::getPrazoEmprestimo() const
{
    return 5;
}

string Revista::getTipo() const {
    return "Revista";
}

void Revista::setEdicao(string e) {
    edicao = e;
}

void Revista::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Edicao" << endl;
    cout << "2 - Categoria" << endl;
    cout << "3 - Autor" << endl;
    cout << "4 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:{
        string novaEdicao;
        cout << "Edicao Atual: " << edicao << endl;
        cout << "Nova Edicao: ";
        cin.ignore();
        getline(cin, novaEdicao);
        setEdicao(novaEdicao);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 2:{
        string novaCategoria;
        cout << "Categoria Atual: " << getCategoria() << endl;
        cout << "Nova Categoria: ";
        cin.ignore();
        getline(cin, novaCategoria);
        setCategoria(novaCategoria);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 3:{
        string novoAutor;
        cout << "Autor Atual: " << getAutor() << endl;
        cout << "Novo Autor: ";
        cin.ignore();
        getline(cin, novoAutor);
        setAutor(novoAutor);
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