#ifndef REVISTA_H
#define REVISTA_H

#include "Livro.h"


class Revista : public Livro
{
    public:
        Revista(string t, string a, string i, string c, int e, int numCopias);
        virtual ~Revista();

        int getEdicao() const;
        int getPrazoEmprestimo() const;
        string getTipo() const override;
        void setEdicao(int e);
        void EditarInformacoesLivro() override;

    protected:

    private:
        int edicao;
};

#endif // REVISTA_H
