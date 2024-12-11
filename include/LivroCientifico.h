#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Livro.h"


class LivroCientifico : public Livro
{
    public:
        LivroCientifico(string t, string a, string i, string c, int numCopias);
        virtual ~LivroCientifico();

        string getTipo() const override;
        int getPrazoEmprestimo() const override;
        void EditarInformacoesLivro() override;
    protected:

    private:

};

#endif // LIVROCIENTIFICO_H
