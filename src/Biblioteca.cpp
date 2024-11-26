#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //constructor

}

Biblioteca::~Biblioteca()
{
    for (list<Livro*>::iterator it = Coleccao_LIVROS.begin(); it != Coleccao_LIVROS.end(); it++)
    {
        delete *it;
    }
    for (list<Leitor*>::iterator it = Coleccao_LEITORES.begin(); it != Coleccao_LEITORES.end(); it++)
    {
        delete *it;
    }
    for (list<Emprestimo*>::iterator it = Coleccao_REQ.begin(); it != Coleccao_REQ.end(); it++)
    {
        delete *it;
    }
}

bool Biblioteca::SaveToFile(string nf)
{
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    return true;
}
void Biblioteca::RelatorioCategoria(string cat)
{
    for (list<Livro*>::iterator it = Coleccao_LIVROS.begin(); it != Coleccao_LIVROS.end(); it++)
    {
        if ((*it)->getTipo() == cat)
        {
            cout << "Titulo: " << (*it)->getTitulo() << endl;
            cout << "Autor: " << (*it)->getAutor() << endl;
            cout << "Genero: " << (*it)->getTipo() << endl;
            cout << "Tipo: " << (*it)->getTipo() << endl;
            cout << "ISBN: " << (*it)->getIsbn() << endl;
            cout << "---------------------------------" << endl;
        }
    }
}
void Biblioteca::Prorrogacao_Emprestimos()
{
    
}

void Biblioteca::Sistema_Notificacoes_Atraso()
{
    for (list<Emprestimo*>::iterator it = Coleccao_REQ.begin(); it != Coleccao_REQ.end(); it++)
    {
        if ((*it)->estaAtrasado())
        {
            cout << "Livro: " << (*it)->getLivro()->getTitulo() << " (Leitor: " << (*it)->getLeitor()->getNome() << ") está atrasado!" << endl;
        }
    }
}

void Biblioteca::Listagem_Livros()
{
    for (list<Livro*>::iterator it = Coleccao_LIVROS.begin(); it != Coleccao_LIVROS.end(); it++)
    {
        cout << "Titulo: " << (*it)->getTitulo() << endl;
        cout << "Autor: " << (*it)->getAutor() << endl;
        cout << "Genero: " << (*it)->getTipo() << endl;
        cout << "Tipo: " << (*it)->getTipo() << endl;
        cout << "ISBN: " << (*it)->getIsbn() << endl;
        cout << "---------------------------------" << endl;
    }
}

bool Biblioteca::Add_Leitor(Leitor *LT)
{
    for (list<Leitor*>::iterator it = Coleccao_LEITORES.begin(); it != Coleccao_LEITORES.end(); it++)
    {
        if ((*it)->getID() == LT->getID())
        {
            return false;
        }
    }
    Coleccao_LEITORES.push_back(LT);
    return true;
}

bool Biblioteca::Add_Livro(Livro *L){
    for (list<Livro*>::iterator it = Coleccao_LIVROS.begin(); it != Coleccao_LIVROS.end(); it++)
    {
        if ((*it)->getIsbn() == L->getIsbn())
        {
            return false;
        }
    }
    Coleccao_LIVROS.push_back(L);
    return true;
}

void Biblioteca::Add_Emprestimo(Livro *L, Leitor *LT)
{
    Emprestimo* emprestimo = new Emprestimo(L, LT);
    Coleccao_REQ.push_back(emprestimo);
}

void Biblioteca::Devolver_Livro(Emprestimo *E)
{
    if (!E) {
        cout << "Emprestimo invalido!" << endl;
        return;
    }

    // Remove o empréstimo da lista de empréstimos do leitor
    Leitor* leitor = E->getLeitor();
    if (leitor) {
        leitor->removerEmprestimo(E);
    }

    // Remove o empréstimo da lista geral da biblioteca
    Coleccao_REQ.remove(E);

    // Mensagem de multa, se aplicável
    float multa = E->calcularMulta();
    if (multa > 0) {
        cout << "Livro devolvido com atraso! Multa: " << multa << "€" << endl;
    } else {
        cout << "Livro devolvido dentro do prazo!" << endl;
    }

    // Libera a memória do objeto Emprestimo
    delete E;
}

void Biblioteca::Gerar_RelatorioEmprestimos()
{
    cout << "=== Relatório de Empréstimos Atuais ===" << endl;
    for (list<Emprestimo*>::iterator it = Coleccao_REQ.begin(); it != Coleccao_REQ.end(); it++)
    {
        cout << "Livro: " << (*it)->getLivro()->getTitulo() << endl;
        cout << "Leitor: " << (*it)->getLeitor()->getNome() << endl;
        cout << "Data de Devolução Prevista: " << ctime(&(*it)->dataDevolucao);
        if ((*it)->estaAtrasado()) {
            cout << "ATRASADO! Multa: " << (*it)->calcularMulta() << "€" << endl;
        }
        cout << "---------------------------------" << endl;
    }
}