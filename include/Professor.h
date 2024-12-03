#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Leitor.h"


class Professor : public Leitor
{
    private:
        float descontoMulta = 0.50f;
    public:
        Professor(string n, string i);
        virtual ~Professor();

        int getLimiteEmprestimos() const override;
        float getDescontoMulta() const override;
        bool podeProrrogar() const override;
        void editarInformacoes() override;

    protected:

    private:
};

#endif // PROFESSOR_H
