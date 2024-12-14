#include "Professor.h"
#include <iostream>

Professor::Professor(string n, string i) : Leitor(n, i)
{
    //ctor
}

Professor::~Professor()
{
    //dtor
}

int Professor::getLimiteEmprestimos() const
{
    return 20; // Professores podem requisitar até 20 livros
}

float Professor::getDescontoMulta() const
{
    return descontoMulta; // 50% de desconto
}

bool Professor::podeProrrogar() const
{
    return true; // Professores podem prorrogar
}

void Professor::editarInformacoes()
{
     float novoDesconto;
    cout << "Editar Informacoes de Professor" << endl;
    cout << "Desconto atual em multas: " << getDescontoMulta() * 100 << "%" << endl;
    cout << "Novo desconto (em %): ";
    cin >> novoDesconto;

    if (novoDesconto >= 0 && novoDesconto <= 100)
    {
        descontoMulta = novoDesconto / 100.0f; // Converter para decimal
    }
    else
    {
        cout << "Desconto tem que ser entre 0 e 100%!" << endl;
    }
}

string Professor::getTipo() const {
    return "Professor";
}
