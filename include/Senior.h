#ifndef SENIOR_H
#define SENIOR_H

#include "Leitor.h"

class Senior : public Leitor {
public:
    Senior(string nome, string id);  
    virtual ~Senior();               

    int getLimiteEmprestimos() const override;
    float getDescontoMulta() const override;
    bool podeProrrogar() const override;
    void editarInformacoes() override;
};

#endif // SENIOR_H
