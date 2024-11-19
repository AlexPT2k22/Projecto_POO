#include "Revista.h"

Revista::Revista(string t, string a, string i, int e) : Livro(t, a, i), edicao(e)
{
    //ctor
}

Revista::~Revista()
{
    //dtor
}

int Revista::getEdicao() const
{
    return edicao;
}

int Revista::getPrazoEmprestimo() const
{
    return 2;
}
