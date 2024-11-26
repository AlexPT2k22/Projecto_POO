#include "Professor.h"

Professor::Professor(string n, string i) : Leitor(n, i)
{
    //ctor
}

Professor::~Professor()
{
    //dtor
}

int Professor::getLimiteEmprestimos() const
{
    return 20; // Professores podem requisitar até 20 livros
}

float Professor::getDescontoMulta() const
{
    return 0.25f; // 25% de desconto
}

bool Professor::podeProrrogar() const
{
    return true; // Professores podem prorrogar
}
