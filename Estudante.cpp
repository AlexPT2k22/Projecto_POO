#include "Estudante.h"

Estudante::Estudante(string n, string i) : Leitor(n, i) {
    //ctor
}

Estudante::~Estudante() {
    //dtor
}

int Estudante::getLimiteEmprestimos() const {
    return 10; // Estudantes podem requisitar até 10 livros
}

float Estudante::getDescontoMulta() const {
    return 0.5f; // 50% de desconto
}

bool Estudante::podeProrrogar() const {
    return true; // Estudantes podem prorrogar
}