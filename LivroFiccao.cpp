#include "LivroFiccao.h"

LivroFiccao::LivroFiccao(string t, string a, string i, string g) : Livro(t, a, i), genero(g)
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
