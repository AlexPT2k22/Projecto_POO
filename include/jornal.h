#ifndef JORNAL_H
#define JORNAL_H

#include "Livro.h"

//jornal vai ser tratado como um livro
class Jornal : public Livro
{
    public:
        Jornal(string t, string a, string i, string c, int d, int num_copias);
        virtual ~Jornal();

        int getDia() const;
        int getPrazoEmprestimo() const;
        string getTipo() const override;
        void EditarInformacoesLivro() override;
        bool setDia(int d);


    protected:

    private:
        int Dia;
};

#endif // REVISTA_H