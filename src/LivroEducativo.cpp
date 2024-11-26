#include "LivroEducativo.h"

LivroEducativo::LivroEducativo(string t, string a, string i, string g) : Livro(t, a, i), grau_escolaridade(g)
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

string LivroEducativo::getTipo() const
{
    return "Educativo";
}

int LivroEducativo::getPrazoEmprestimo() const
{
    return 10;
}