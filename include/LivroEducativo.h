#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include <Livro.h>
using namespace std;

class LivroEducativo : public Livro
{
    public:
        LivroEducativo(string t, string a, string i, string g);
        virtual ~LivroEducativo();

        string getTipo() const;
        int getPrazoEmprestimo() const;
        

    protected:

    private:
        string grau_escolaridade; //ou categoria
};


#endif // LIVROEDUCATIVO_H