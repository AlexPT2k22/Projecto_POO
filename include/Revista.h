#ifndef REVISTA_H
#define REVISTA_H

#include <Livro.h>


class Revista : public Livro
{
    public:
        Revista(string t, string a, string i, int e);
        virtual ~Revista();

        int getEdicao() const;
        int getPrazoEmprestimo() const;

    protected:

    private:
        int edicao;
};

#endif // REVISTA_H
