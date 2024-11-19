#ifndef Estudante_H
#define Estudante_H

#include "Leitor.h"

class Estudante : public Leitor {
    public:
        Estudante(string n, string i);
        virtual ~Estudante();

        int getLimiteEmprestimos() const;
        float getDescontoMulta() const;
        bool podeProrrogar() const;
};


#endif // ESTUDANTE_H