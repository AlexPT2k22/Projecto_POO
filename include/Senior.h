#ifndef SENIOR_H
#define SENIOR_H

#include "Leitor.h"

/**
 * @brief Classe que representa um leitor senior na biblioteca
 * 
 * Esta classe herda de Leitor e adiciona funcionalidades específicas para leitores senior,
 * incluindo o limite de empréstimos e o desconto na multa
 */
class Senior : public Leitor {
public:
    Senior(string nome, string id); //Construtor
    virtual ~Senior(); //Destrutor

    int getLimiteEmprestimos() const override; //Obtém o limite de empréstimos do leitor senior
    float getDescontoMulta() const override; //Obtém o desconto na multa do leitor senior
    bool podeProrrogar() const override; //Verifica se o leitor senior pode prorrogar o empréstimo
    void editarInformacoes() override; //Edita as informações do leitor senior
    string getTipo() const override; //Obtém o tipo de leitor
};

#endif // SENIOR_H
