#ifndef REVISTA_H
#define REVISTA_H

#include "Livro.h"

/**
 * @brief Classe que representa uma revista na biblioteca
 * 
 * Esta classe herda de Livro e adiciona funcionalidades específicas para revistas,
 * incluindo a edição
 */
class Revista : public Livro
{
    public:
        Revista(string t, string a, string i, string c, int e, int numCopias); //Construtor
        virtual ~Revista(); //Destrutor

        int getEdicao() const; //Obtém a edição da revista
        int getPrazoEmprestimo() const; //Obtém o prazo de empréstimo da revista
        string getTipo() const override; //Obtém o tipo de livro
        void setEdicao(int e); //Define a edição da revista
        void EditarInformacoesLivro() override; //Edita as informações da revista
    private:
        int edicao; //Edição da revista
};

#endif // REVISTA_H
