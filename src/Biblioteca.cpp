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
    cout << "Empréstimo realizado com sucesso!" << endl;
}

void Biblioteca::Devolver_Livro(Emprestimo *E)
{
    for (list<Emprestimo*>::iterator it = Coleccao_REQ.begin(); it != Coleccao_REQ.end(); it++)
    {
        if ((*it) == E)
        {
            Coleccao_REQ.erase(it);
            cout << "Livro devolvido com sucesso!" << endl;
            return;
        }
    }
    cout << "Livro não encontrado!" << endl;
}

void Biblioteca::Gerar_RelatorioEmprestimos()
{
    for (list<Emprestimo*>::iterator it = Coleccao_REQ.begin(); it != Coleccao_REQ.end(); it++)
    {
        cout << "Livro: " << (*it)->getLivro()->getTitulo() << " (Leitor: " << (*it)->getLeitor()->getNome() << ")" << endl;
        cout << "Data de empréstimo: " << ctime(&(*it)->dataEmprestimo);
        cout << "Data de devolução: " << ctime(&(*it)->dataDevolucao);
        cout << "---------------------------------" << endl;
    }
}