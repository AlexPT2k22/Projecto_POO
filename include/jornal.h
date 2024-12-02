#ifndef JORNAL_H
#define JORNAL_H

#include "Livro.h"


class Jornal : public Livro
{
    public:
        Jornal(string t, string a, string i, string d);
        virtual ~Jornal();

        string getDia() const;
        int getPrazoEmprestimo() const;
        string getTipo() const override;

    protected:

    private:
        string Dia;
};

#endif // REVISTA_H