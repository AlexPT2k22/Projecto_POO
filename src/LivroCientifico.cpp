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


