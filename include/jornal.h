#ifndef JORNAL_H
#define JORNAL_H

#include "Livro.h"

//jornal vai ser tratado como um livro
/**
 * @brief Classe que representa um jornal na biblioteca
 * 
 * Esta classe herda de Livro e adiciona funcionalidades específicas para jornais
 */
class Jornal : public Livro
{
    public:
        Jornal(string t, string a, string i, string c, int d, int num_copias);
        virtual ~Jornal();

        int getDia() const; //Obtém o dia do jornal
        int getPrazoEmprestimo() const; //Obtém o prazo de empréstimo do jornal
        string getTipo() const override; //Obtém o tipo de livro
        void EditarInformacoesLivro() override; //Edita as informações do jornal
        bool setDia(int d); //Define o dia do jornal

    private:
        int Dia;
};

#endif // REVISTA_H