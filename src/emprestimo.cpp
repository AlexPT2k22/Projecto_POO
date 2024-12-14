#include "emprestimo.h"

Emprestimo::Emprestimo(Livro *L, Leitor *LT) : livro(L), leitor(LT) {
    dataEmprestimo = time(nullptr);
    calcularDataDevolucao();
}

Emprestimo::~Emprestimo() {
    //dtor
}

void Emprestimo::prorrogarEmprestimo(){
    dataDevolucao = dataEmprestimo + (livro->getPrazoEmprestimo() * 24 * 60 * 60);
    cout << "Nova data de devolucao: " << ctime(&dataDevolucao);
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
        float multa = dias_de_atraso * 1.0f; // 1€ por dia de atraso
        float desconto = multa * leitor->getDescontoMulta();
        return multa -= desconto;
    }
    return 0.0f;
}

Livro* Emprestimo::getLivro() const {
    return livro;
}

Leitor* Emprestimo::getLeitor() const {
    return leitor;
}

void Emprestimo::simularAtraso(int dias) {
    dataDevolucao -= (dias * 24 * 60 * 60); //subtrair dias a data de devolucao
}

