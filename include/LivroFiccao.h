#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Livro.h"

/**
 * @brief Classe que representa um livro de ficção na biblioteca
 * 
 * Esta classe herda de Livro e adiciona funcionalidades específicas para livros de ficção,
 * incluindo o género literário
 */
class LivroFiccao : public Livro
{
    public:
        LivroFiccao(string t, string a, string i, string g, int numCopias); //Construtor
        virtual ~LivroFiccao(); //Destrutor

        string getTipo() const override; //Obtém o tipo de livro
        int getPrazoEmprestimo() const override; //Obtém o prazo de empréstimo do livro
        void EditarInformacoesLivro() override; //Edita as informações do livro

    private:
        string genero; //ou categoria
};

#endif // LIVROFICCAO_H
