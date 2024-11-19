#include "Leitor.h"

Leitor::Leitor(string n, string i) : nome(n), id(i) {
    //ctor
}

Leitor::~Leitor() {
    //dtor
}

void Leitor::adicionarEmprestimo(Emprestimo* e) {
    emprestimos.push_back(e);
}

void Leitor::removerEmprestimo(Emprestimo* e) {
    emprestimos.remove(e);
}

void Leitor::LimparTodosEmprestimos(Emprestimo* e) {
    for (list<Emprestimo*>::iterator it = emprestimos.begin(); it != emprestimos.end(); it++) {
        if (*it == e) {
            emprestimos.erase(it);
            break;
        }
    }
}