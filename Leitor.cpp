#include "Leitor.h"

Leitor::Leitor(string n, string i) : nome(n), id(i) {
    //ctor
}

Leitor::~Leitor() {
    //dtor
}

void Leitor::adicionarEmprestimo(Emprestimo* e) {
    emprestimos.push_back(e);  // Adiciona um empréstimo à lista
}

void Leitor::removerEmprestimo(Emprestimo* e) {
    emprestimos.remove(e);  // Remove o empréstimo da lista
}

void Leitor::LimparTodosEmprestimos() {
    emprestimos.clear();  // Limpa todos os empréstimos
}

string Leitor::getID() const {
    return id;
}

string Leitor::getNome() const {
    return nome;
}