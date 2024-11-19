#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include <Livro.h>


class LivroCientifico : public Livro
{
    public:
        LivroCientifico(string t, string a, string i, string g);
        virtual ~LivroCientifico();

        string getTipo() const;
        int getPrazoEmprestimo() const;
        

    protected:

    private:
        string genero; //ou categoria
};

#endif // LIVROCIENTIFICO_H
