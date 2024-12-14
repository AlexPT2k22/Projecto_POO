#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Livro.h"

/**
 * @brief Classe que representa um livro científico na biblioteca
 * 
 * Esta classe herda de Livro e adiciona funcionalidades específicas para livros científicos
 */
class LivroCientifico : public Livro
{
    public:
        LivroCientifico(string t, string a, string i, string c, int numCopias); //Construtor
        virtual ~LivroCientifico(); //Destrutor

        string getTipo() const override; //Obtém o tipo de livro
        int getPrazoEmprestimo() const override; //Obtém o prazo de empréstimo do livro
        void EditarInformacoesLivro() override; //Edita as informações do livro

};

#endif // LIVROCIENTIFICO_H
