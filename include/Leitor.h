#ifndef Leitor_H
#define Leitor_H
#include <string>
#include <list>
#include <vector>
using namespace std;

class Emprestimo; //Declaração antecipada da classe Emprestimo

/**
 * @brief Classe base para representar um leitor na biblioteca
 * 
 * Esta classe define as características e comportamentos comuns a todos os tipos de leitores
 */
class Leitor {
    protected:
        string nome;
        string id;
        list<Emprestimo*> emprestimos; //Lista de empréstimos ativos
        vector<Emprestimo*> historico_emprestimos; //Histórico de empréstimos

    public:
        
        Leitor(string n, string i); //nome e ID
        virtual ~Leitor();
        list<Emprestimo*> getEmprestimos() const;

        virtual int getLimiteEmprestimos() const = 0; //Limite de empréstimos
        virtual float getDescontoMulta() const = 0; //Desconto de multa
        virtual bool podeProrrogar() const = 0; //Verifica se o leitor pode prorrogar o empréstimo
        virtual void editarInformacoes() = 0; //Edita as informações do leitor

        string getNome() const; //Obtém o nome do leitor
        void adicionarEmprestimo(Emprestimo* e); //Adiciona um empréstimo à lista de empréstimos ativos
        void removerEmprestimo(Emprestimo* e); //Remove um empréstimo da lista de empréstimos ativos
        void LimparTodosEmprestimos(); //Limpa todos os empréstimos
        string getID() const; //Obtém o ID do leitor
        virtual string getTipo() const = 0; //Obtém o tipo de leitor
        vector<Emprestimo*> getHistoricoEmprestimos() const; //Obtém o histórico de empréstimos
};

#endif // LEITOR_H