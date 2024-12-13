#include "Jornal.h"

Jornal::Jornal(string t, string a, string i, string d, int num_copias) : Livro(t, a, i, d, num_copias), Dia(d)
{
}

Jornal::~Jornal()
{
}

string Jornal::getDia() const
{
    return Dia;
}

int Jornal::getPrazoEmprestimo() const
{
    return 1;
}

string Jornal::getTipo() const
{
    return "Jornal";
}

void Jornal::setDia(string d)
{
    Dia = d;
}

void Jornal::EditarInformacoesLivro()
{
    Livro::EditarInformacoesLivro();
    cout << "Dia: ";
    cin >> Dia;
}
