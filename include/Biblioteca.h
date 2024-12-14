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
#include <fstream>
#include <sstream>

/**
 * @brief Classe que representa uma biblioteca e gerencia as suas operações
 * 
 * Esta classe implementa as funcionalidades principais de uma biblioteca, incluindo:
 * - Gerenciamento de livros, leitores e empréstimos
 * - Persistência de dados em arquivos
 * - Sistema de notificações e multas
 * - Geração de relatórios
 * - Reservas de livros
 * - Edição de informações cadastrais
 */
class Biblioteca
{

    public:
        Biblioteca();
        virtual ~Biblioteca();

        vector<Livro*> Coleccao_LIVROS; //Coleção de livros
        vector<Leitor*> Coleccao_LEITORES; //Coleção de leitores
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
        void cancelar_reserva(string isbn, string id);
        void ListarReservas();
        void GerarRelatorioMultasPendentes();
        void GerarRelatorioEmprestimosPorTipo();
        void GerarHistoricoEmprestimosLeitor(Leitor *LT);

};

#endif // BIBLIOTECA_H
