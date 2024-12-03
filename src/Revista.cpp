#include "Revista.h"

Revista::Revista(string t, string a, string i, string c, string e) : Livro(t, a, i, c), edicao(e)
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