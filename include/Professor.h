#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Leitor.h"


class Professor : public Leitor
{
    public:
        Professor(string n, string i);
        virtual ~Professor();

        int getLimiteEmprestimos() const override;
        float getDescontoMulta() const override;
        bool podeProrrogar() const override;
        void editarInformacoes() override;
        string getTipo() const override;
};

#endif // PROFESSOR_H
