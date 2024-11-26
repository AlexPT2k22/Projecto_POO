#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(string t, string a, string i, string g) : Livro(t, a, i), genero(g)
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


