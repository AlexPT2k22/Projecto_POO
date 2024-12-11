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

/**
 * @brief Displays a message indicating that senior users cannot edit their information
 * 
 * This method implements the editarInformacoes interface but restricts seniors
 * from modifying their account details by displaying a message.
 */
void Senior::editarInformacoes() {
    cout << "Seniores nao podem editar informacoes!" << endl;
}

string Senior::getTipo() const {
    return "Senior";
}

