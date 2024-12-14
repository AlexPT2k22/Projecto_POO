#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Leitor.h"

/**
 * @brief Classe que representa um professor na biblioteca
 * 
 * Esta classe herda de Leitor e adiciona funcionalidades específicas para professores,
 * incluindo o desconto na multa e o limite de empréstimos
 */
class Professor : public Leitor
{
    private:
        float descontoMulta = 0.50f; //Desconto na multa do professor
    public:
        Professor(string n, string i); //Construtor
        virtual ~Professor(); //Destrutor

        int getLimiteEmprestimos() const override; //Obtém o limite de empréstimos do professor
        float getDescontoMulta() const override; //Obtém o desconto na multa do professor
        bool podeProrrogar() const override; //Verifica se o professor pode prorrogar o empréstimo
        void editarInformacoes() override; //Edita as informações do professor
        string getTipo() const override; //Obtém o tipo de leitor
};

#endif // PROFESSOR_H
