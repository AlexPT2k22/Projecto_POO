#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include "Leitor.h"
#include "Livro.h"
#include "Emprestimo.h"
#include "Estudante.h"
#include "Professor.h"


class Biblioteca
{
   // list, vector, map Coleccao_LIVROS;
   // list, vector, map Coleccao_REQ;
    protected:
        list<Livro*> Coleccao_LIVROS;
        list<Leitor*> Coleccao_LEITORES;
        list<Emprestimo*> Coleccao_REQ; //Requesicões

    public:
        Biblioteca();
        virtual ~Biblioteca();
        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void RelatorioCategoria(string cat);
        void Prorrogacao_Emprestimos();
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        //bool Add_Leitores(); TODO
        bool Add_Leitor(Leitor *LT);
        bool Add_Livro(Livro *L);
        void Add_Emprestimo(Livro *L, Leitor *LT);
        void Devolver_Livro(Emprestimo *E);
        void Pesquisar_Livros(string genero);//Pesquisar livros pelo genero
        void Gerar_RelatorioEmprestimos();

};

#endif // BIBLIOTECA_H
