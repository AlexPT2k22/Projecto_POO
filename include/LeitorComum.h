#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include <Leitor.h>

/**
 * @brief Classe que representa um leitor comum na biblioteca
 * 
 * Esta classe herda de Leitor e adiciona funcionalidades específicas para leitores comuns
 */
class LeitorComum : public Leitor
{
    public:
        LeitorComum(string n, string i);
        virtual ~LeitorComum();

        int getLimiteEmprestimos() const override; //Obtém o limite de empréstimos do leitor comum
        float getDescontoMulta() const override; //Obtém o desconto de multa do leitor comum
        bool podeProrrogar() const override; //Verifica se o leitor comum pode prorrogar o empréstimo
        void editarInformacoes() override; //Edita as informações do leitor comum
        string getTipo() const override; //Obtém o tipo de leitor
};

#endif // LEITORCOMUM_H
