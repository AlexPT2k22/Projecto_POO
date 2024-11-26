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
    protected:


    public:
        Emprestimo(Livro *L, Leitor *LT);
        virtual ~Emprestimo(); 
        void calcularDataDevolucao();
        bool estaAtrasado();
        float calcularMulta();
        Livro* getLivro() const;
        Leitor* getLeitor() const;
        time_t dataEmprestimo;
        time_t dataDevolucao;
};

#endif // EMPRESTIMO_H