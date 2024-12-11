#ifndef Estudante_H
#define Estudante_H

#include "Leitor.h"

class Estudante : public Leitor {

    private:
        int limiteEmprestimos = 10;
    public:
        Estudante(string n, string i);
        virtual ~Estudante();

        int getLimiteEmprestimos() const override;
        float getDescontoMulta() const override;
        bool podeProrrogar() const override;
        void editarInformacoes() override;
        string getTipo() const override;
};


#endif // ESTUDANTE_H