#include "Senior.h"

Senior::Senior(string nome, string id) : Leitor(nome, id) {}

Senior::~Senior() {}

int Senior::getLimiteEmprestimos() const {
    return 8;  // Sêniores podem emprestar até 8 livros
}

float Senior::getDescontoMulta() const {
    return 0.8f;  // Sêniores têm 80% de desconto na multa
}

bool Senior::podeProrrogar() const {
    return true;  // Sêniores podem prorrogar
}
