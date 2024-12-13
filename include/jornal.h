#ifndef JORNAL_H
#define JORNAL_H

#include "Livro.h"

//jornal vai ser tratado como um livro
class Jornal : public Livro
{
    public:
        Jornal(string t, string a, string i, string d, int num_copias);
        virtual ~Jornal();

        string getDia() const;
        int getPrazoEmprestimo() const;
        string getTipo() const override;
        void EditarInformacoesLivro() override;
        void setDia(string d);

    protected:

    private:
        string Dia;
};

#endif // REVISTA_H