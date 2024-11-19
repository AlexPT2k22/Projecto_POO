#ifndef Leitor_H
#define Leitor_H
#include <string>
#include <list>
using namespace std;

class Emprestimo;

class Leitor {
protected:
    string nome;
    string id;
    list<Emprestimo*> emprestimos;

public:
    
    Leitor(string n, string i);
    virtual ~Leitor();

    virtual int getLimiteEmprestimos() const = 0;
    virtual float getDescontoMulta() const = 0;
    virtual bool podeProrrogar() const = 0;

    string getNome() const { return nome; }
    void adicionarEmprestimo(Emprestimo* e);
    void removerEmprestimo(Emprestimo* e);
    void LimparTodosEmprestimos(Emprestimo* e);
};

#endif // LEITOR_H