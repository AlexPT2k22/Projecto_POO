#include "LivroFiccao.h"

LivroFiccao::LivroFiccao(string t, string a, string i, string c) : Livro(t, a, i, c)
{
    //ctor
}

LivroFiccao::~LivroFiccao()
{
    //dtor
}

string LivroFiccao::getTipo() const
{
    return "Ficcao";
}

int LivroFiccao::getPrazoEmprestimo() const
{
    return 7;
}
