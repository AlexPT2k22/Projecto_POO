#include "emprestimo.h"
/**
 * @brief Construtor da classe Emprestimo.
 *
 * @param L Ponteiro para o livro emprestado.
 * @param LT Ponteiro para o leitor que fez o empréstimo.
 */
Emprestimo::Emprestimo(Livro *L, Leitor *LT) : livro(L), leitor(LT) {
    dataEmprestimo = time(nullptr); //obter a data atual
    calcularDataDevolucao(); //calcular a data de devolução
}

/**
 * @brief Destrutor da classe Emprestimo.
 */
Emprestimo::~Emprestimo() {
    //dtor 
}

/**
 * @brief Prorroga o prazo de devolução do empréstimo.
 */
void Emprestimo::prorrogarEmprestimo(){
    dataDevolucao = dataEmprestimo + (livro->getPrazoEmprestimo() * 24 * 60 * 60); //adicionar o prazo de devolução ao prazo de empréstimo (24 horas * 60 minutos * 60 segundos)
    cout << "Nova data de devolucao: " << ctime(&dataDevolucao); //imprimir a nova data de devolução
}

/**
 * @brief Calcula a data de devolução do empréstimo.
 */
void Emprestimo::calcularDataDevolucao() {
    dataDevolucao = dataEmprestimo + (livro->getPrazoEmprestimo() * 24 * 60 * 60); //adicionar o prazo de devolução ao prazo de empréstimo (24 horas * 60 minutos * 60 segundos)
}

/**
 * @brief Verifica se o empréstimo está atrasado.
 *
 * @return true se o empréstimo está atrasado, false caso contrário.
 */
bool Emprestimo::estaAtrasado() {
    return time(nullptr) > dataDevolucao; //verificar se a data atual é maior que a data de devolução
}

/**
 * @brief Calcula a multa do empréstimo.
 *
 * @return A multa do empréstimo.
 */
float Emprestimo::calcularMulta() {
    if (estaAtrasado()) { //se o empréstimo está atrasado
        int dias_de_atraso = (time(nullptr) - dataDevolucao) / (24 * 60 * 60); //calcular o numero de dias de atraso (24 horas * 60 minutos * 60 segundos)
        float multa = dias_de_atraso * 1.0f; // 1€ por dia de atraso
        float desconto = multa * leitor->getDescontoMulta(); //calcular o desconto da multa
        return multa -= desconto; //subtrair o desconto da multa
    }
    return 0.0f; //se o empréstimo não está atrasado, a multa é 0€
}

/**
 * @brief Obtém o livro emprestado.
 *
 * @return Ponteiro para o livro emprestado.
 */
Livro* Emprestimo::getLivro() const {
    return livro; //retornar o livro emprestado
}

/**
 * @brief Obtém o leitor que fez o empréstimo.
 *
 * @return Ponteiro para o leitor.
 */
Leitor* Emprestimo::getLeitor() const {
    return leitor;
}

/**
 * @brief Simula um atraso no empréstimo.
 *
 * @param dias O número de dias de atraso.
 */
void Emprestimo::simularAtraso(int dias) {
    dataDevolucao -= (dias * 24 * 60 * 60); //subtrair dias a data de devolucao
}

