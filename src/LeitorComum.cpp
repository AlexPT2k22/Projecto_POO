#include "LeitorComum.h"
#include <iostream>

LeitorComum::LeitorComum(string n, string i) : Leitor(n, i)
{
    //ctor
}

LeitorComum::~LeitorComum()
{
    //dtor
}

int LeitorComum::getLimiteEmprestimos() const {
    return 3;
}

float LeitorComum::getDescontoMulta() const {
    return 0;
}

bool LeitorComum::podeProrrogar() const {
    return false;
}

void LeitorComum::editarInformacoes() {
    cout << "Leitor Comum nao pode editar informacoes!" << endl;
}

string LeitorComum::getTipo() const {
    return "Comum";
}
