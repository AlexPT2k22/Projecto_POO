#include "Senior.h"
#include <iostream>

Senior::Senior(string nome, string id) : Leitor(nome, id) {}

Senior::~Senior() {}

int Senior::getLimiteEmprestimos() const {
    return 8;  // Sêniores podem emprestar até 8 livros
}

float Senior::getDescontoMulta() const {
    return 0.8f;  // Sêniores têm 80% de desconto na multa
}

bool Senior::podeProrrogar() const {
    return false;  // Sêniores podem prorrogar
}

void Senior::editarInformacoes() {
    cout << "Seniores nao podem editar informacoes!" << endl;
}
