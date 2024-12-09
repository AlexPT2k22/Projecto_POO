#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <vector>
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

    public:
        Biblioteca();
        virtual ~Biblioteca();

        vector<Livro*> Coleccao_LIVROS;
        vector<Leitor*> Coleccao_LEITORES;
        vector<Emprestimo*> Coleccao_REQ; //Requesicões

        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void Prorrogacao_Emprestimos(string id, string isbn);
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        bool Add_Leitor(Leitor *LT);
        bool Add_Livro(Livro *L);
        void Add_Emprestimo(Livro *L, Leitor *LT);
        void Devolver_Livro(Emprestimo *E);
        void Gerar_RelatorioEmprestimos();
        void Editar_InformacoesLeitores(string id);
        void Editar_InformacoesLivros(string isbn);
        void Pesquisar_Livro_Tipo(string tipo);
        void ListarLivrosCategoria(string categoria);
        void Remover_Leitor(string id);
        void Remover_Livro(string isbn);
        void reservarLivro(string isbn, Leitor *LT);


};

#endif // BIBLIOTECA_H
