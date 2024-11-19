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
    
}
void Biblioteca::Prorrogacao_Emprestimos()
{
    
}
void Biblioteca::Sistema_Notificacoes_Atraso()
{
    
}
void Biblioteca::Listagem_Livros()
{
    
}
/*bool Biblioteca::Add_Leitores()
{
    
    return true;
} TODO */
bool Biblioteca::Add_Leitor(Leitor *LT)
{
    
    return true;
}
