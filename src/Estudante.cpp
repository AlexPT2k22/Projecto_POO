#include "Estudante.h"
#include <iostream>

Estudante::Estudante(string n, string i) : Leitor(n, i) {
    //ctor
}

Estudante::~Estudante() {
    //dtor
}

int Estudante::getLimiteEmprestimos() const {
    return limiteEmprestimos; // Estudantes podem requisitar até 10 livros
}

float Estudante::getDescontoMulta() const {
    return 0.5f; // 50% de desconto
}

bool Estudante::podeProrrogar() const {
    return true; // Estudantes podem prorrogar
}

void Estudante::editarInformacoes() {
    int novolimite;
    cout << "Editar Informações de Estudante" << endl;
    cout << "Limite atual de emprestimos: " << getLimiteEmprestimos() << " livros"<< endl;
    cout << "Novo limite de emprestimos: ";
    cin >> novolimite;

    if (novolimite > 0) {
        limiteEmprestimos = novolimite;
    } else {
        cout << "Limite tem que ser maior do que 0!" << endl;
    }
}