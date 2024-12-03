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