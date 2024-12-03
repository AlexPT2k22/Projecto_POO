#ifndef REVISTA_H
#define REVISTA_H

#include "Livro.h"


class Revista : public Livro
{
    public:
        Revista(string t, string a, string i, string c, string e);
        virtual ~Revista();

        string getEdicao() const;
        int getPrazoEmprestimo() const;
        string getTipo() const override;

    protected:

    private:
        string edicao;
};

#endif // REVISTA_H
