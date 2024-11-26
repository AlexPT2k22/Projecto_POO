#ifndef Estudante_H
#define Estudante_H

#include "Leitor.h"

class Estudante : public Leitor {
    public:
        Estudante(string n, string i);
        virtual ~Estudante();

        int getLimiteEmprestimos() const override;
        float getDescontoMulta() const override;
        bool podeProrrogar() const override;
};


#endif // ESTUDANTE_H