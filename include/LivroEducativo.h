#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Livro.h"
using namespace std;

class LivroEducativo : public Livro
{
    public:
        LivroEducativo(string t, string a, string i, string c, string g);
        virtual ~LivroEducativo();

        string getTipo() const override;
        int getPrazoEmprestimo() const override;
        string getGrauEscolaridade() const;
        void setGrauEscolaridade(string g);

    protected:

    private:
        string grau_escolaridade;
};


#endif // LIVROEDUCATIVO_H