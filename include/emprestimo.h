#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <ctime>
#include "Leitor.h"
#include "Livro.h"
using namespace std;
/**
 * @brief Classe que representa um empréstimo de livro na biblioteca
 * 
 * Esta classe gere os empréstimos de livros, incluindo:
 * - Cálculo de datas de devolução
 * - Verificação de atrasos
 * - Cálculo de multas
 * - Prorrogação de empréstimos
 * - Gestão da relação entre leitor e livro
 */
class Emprestimo {
    private:
        Leitor* leitor;
        Livro* livro;
    protected:


    public:
        Emprestimo(Livro *L, Leitor *LT);
        virtual ~Emprestimo(); 
        void calcularDataDevolucao(); //Calcula a data de devolução do livro
        bool estaAtrasado(); //Verifica se o empréstimo está atrasado
        float calcularMulta(); //Calcula a multa por atraso na devolução do livro
        Livro* getLivro() const; //Obtém o livro emprestado
        Leitor* getLeitor() const; //Obtém o leitor que realizou o empréstimo
        void prorrogarEmprestimo(); //Prorroga a data de devolução do empréstimo
        void simularAtraso(int dias); //Simula um atraso na devolução do livro
        time_t dataEmprestimo; //Data em que o empréstimo foi realizado
        time_t dataDevolucao; //Data prevista para devolução do livro
};

#endif // EMPRESTIMO_H