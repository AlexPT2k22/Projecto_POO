#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include <Leitor.h>


class LeitorComum : public Leitor
{
    public:
        LeitorComum(string n, string i);
        virtual ~LeitorComum();

        int getLimiteEmprestimos() const override;
        float getDescontoMulta() const override;
        bool podeProrrogar() const override;

    protected:

    private:
};

#endif // LEITORCOMUM_H
