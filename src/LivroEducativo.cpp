#include "LivroEducativo.h"

LivroEducativo::LivroEducativo(string t, string a, string i, string c, string g) : Livro(t, a, i, c), grau_escolaridade(g)
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

string LivroEducativo::getTipo() const
{
    return "Educacional";
}

int LivroEducativo::getPrazoEmprestimo() const
{
    return 10;
}

string LivroEducativo::getGrauEscolaridade() const {
    return grau_escolaridade;
}

void LivroEducativo::setGrauEscolaridade(string g) {
    grau_escolaridade = g;
}

void LivroEducativo::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Grau de Escolaridade" << endl;
    cout << "2 - Categoria" << endl;
    cout << "3 - Autor" << endl;
    cout << "4 - ISBN" << endl;
    cout << "5 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:{
        string novoGrau;
        cout << "Grau de Escolaridade Atual: " << grau_escolaridade << endl;
        cout << "Novo Grau de Escolaridade: ";
        cin.ignore();
        getline(cin, novoGrau);
        setGrauEscolaridade(novoGrau);
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
        string novoIsbn;
        cout << "ISBN Atual: " << getIsbn() << endl;
        cout << "Novo ISBN: ";
        cin.ignore();
        getline(cin, novoIsbn);
        setIsbn(novoIsbn);
        cout << "Informacoes atualizadas com sucesso!" << endl;
        break;
    }
    case 5:{
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