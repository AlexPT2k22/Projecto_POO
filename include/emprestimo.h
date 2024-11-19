#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <ctime>
#include "Leitor.h"
#include "Livro.h"
using namespace std;

class Emprestimo {
    private:
        Leitor* leitor;
        Livro* livro;
        time_t dataEmprestimo;
        time_t dataDevolucao;
    protected:

    public:
        Emprestimo(Livro *L, Leitor *LT);
        void calcularDataDevolucao();
        bool estaAtrasado();
        float calcularMulta();
        Livro* getLivro() const;
        Leitor* getLeitor() const;
};

#endif // EMPRESTIMO_H