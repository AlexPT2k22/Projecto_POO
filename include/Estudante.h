#ifndef Estudante_H
#define Estudante_H

#include "Leitor.h"

/**
 * @brief Classe que representa um estudante na biblioteca
 * 
 * Esta classe herda de Leitor e adiciona funcionalidades específicas para estudantes
 */
class Estudante : public Leitor {

    private:
        int limiteEmprestimos = 10;
    public:
        Estudante(string n, string i);
        virtual ~Estudante();

        int getLimiteEmprestimos() const override; //Obtém o limite de empréstimos do estudante
        float getDescontoMulta() const override; //Obtém o desconto de multa do estudante
        bool podeProrrogar() const override; //Verifica se o estudante pode prorrogar o empréstimo
        void editarInformacoes() override; //Edita as informações do estudante
        string getTipo() const override; //Obtém o tipo de leitor
};


#endif // ESTUDANTE_H