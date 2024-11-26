#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Livro.h"


class LivroFiccao : public Livro
{
    public:
        LivroFiccao(string t, string a, string i, string g);
        virtual ~LivroFiccao();

        string getTipo() const override;
        int getPrazoEmprestimo() const override;

    protected:

    private:
        string genero; //ou categoria
};

#endif // LIVROFICCAO_H
