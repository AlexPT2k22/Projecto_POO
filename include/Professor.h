#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Leitor.h>


class Professor : public Leitor
{
    public:
        Professor(string n, string i);
        virtual ~Professor();

        int getLimiteEmprestimos() const;
        float getDescontoMulta() const;
        bool podeProrrogar() const;

    protected:

    private:
};

#endif // PROFESSOR_H
