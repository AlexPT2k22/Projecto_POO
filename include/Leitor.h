#ifndef Leitor_H
#define Leitor_H
#include <string>
#include <list>
#include <vector>
using namespace std;

class Emprestimo;

class Leitor {
    protected:
        string nome;
        string id;
        list<Emprestimo*> emprestimos;
        vector<Emprestimo*> historico_emprestimos;

    public:
        
        Leitor(string n, string i); //nome e ID
        virtual ~Leitor();
        list<Emprestimo*> getEmprestimos() const;

        virtual int getLimiteEmprestimos() const = 0;
        virtual float getDescontoMulta() const = 0;
        virtual bool podeProrrogar() const = 0;
        virtual void editarInformacoes() = 0;

        string getNome() const;
        void adicionarEmprestimo(Emprestimo* e);
        void removerEmprestimo(Emprestimo* e);
        void LimparTodosEmprestimos();
        string getID() const;
        virtual string getTipo() const = 0;
        vector<Emprestimo*> getHistoricoEmprestimos() const;
};

#endif // LEITOR_H