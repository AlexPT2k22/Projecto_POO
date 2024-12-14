#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Livro.h"
using namespace std; 

/**
 * @brief Classe que representa um livro educativo na biblioteca
 * 
 * Esta classe herda de Livro e adiciona funcionalidades específicas para livros educativos,
 * incluindo o grau de escolaridade a que se destina
 */
class LivroEducativo : public Livro
{
    public:
        LivroEducativo(string t, string a, string i, string c, string g, int numCopias); //Construtor
        virtual ~LivroEducativo(); //Destrutor

        string getTipo() const override; //Obtém o tipo de livro
        int getPrazoEmprestimo() const override; //Obtém o prazo de empréstimo do livro
        string getGrauEscolaridade() const; //Obtém o grau de escolaridade do livro
        void setGrauEscolaridade(string g); //Define o grau de escolaridade do livro
        void EditarInformacoesLivro() override; //Edita as informações do livro

    private:
        string grau_escolaridade; //Grau de escolaridade do livro
};


#endif // LIVROEDUCATIVO_H