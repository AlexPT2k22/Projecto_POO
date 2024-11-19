#include "emprestimo.h"

Emprestimo::Emprestimo(Livro *L, Leitor *LT) : livro(L), leitor(LT) {
    dataEmprestimo = time(nullptr);
    calcularDataDevolucao();
}

Emprestimo::~Emprestimo() {
    //dtor
}

void Emprestimo::calcularDataDevolucao() {
    dataDevolucao = dataEmprestimo + (livro->getPrazoEmprestimo() * 24 * 60 * 60);
}

bool Emprestimo::estaAtrasado() {
    return time(nullptr) > dataDevolucao;
}

float Emprestimo::calcularMulta() {
    if (estaAtrasado()) {
        int dias_de_atraso = (time(nullptr) - dataDevolucao) / (24 * 60 * 60);
        return dias_de_atraso * 1.0; // 1€ por dia de atraso
    }
    return 0;
}

Livro* Emprestimo::getLivro() const {
    return livro;
}

Leitor* Emprestimo::getLeitor() const {
    return leitor;
}