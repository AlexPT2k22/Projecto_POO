#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include <Leitor.h>


class LeitorComum : public Leitor
{
    public:
        LeitorComum(string n, string i);
        virtual ~LeitorComum();

        int getLimiteEmprestimos() const {return 3;}
        float getDescontoMulta() const {return 0.0;}
        bool podeProrrogar() const {return false;}

    protected:

    private:
};

#endif // LEITORCOMUM_H
