#include <iostream>
#include <string>
#include "Biblioteca.h"
#include "LeitorComum.h"
#include "Estudante.h"
#include "Professor.h"
#include "Senior.h"
#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroFiccao.h"
#include "Revista.h"

using namespace std;

/**
 * @file main.cpp
 * @brief Programa principal para gerenciamento de uma biblioteca.
 *
 * Este programa permite ao usuário realizar diversas operações em uma biblioteca,
 * como adicionar livros, leitores, empréstimos, devolver livros, gerar relatórios,
 * listar livros por categoria, prorrogar empréstimos, e muito mais.
 *
 * As opções disponíveis no menu são:
 * 1. Adicionar Livro: Adiciona um novo livro à biblioteca.
 * 2. Adicionar Leitor: Adiciona um novo leitor à biblioteca.
 * 3. Adicionar Empréstimo: Realiza um empréstimo de um livro para um leitor.
 * 4. Devolver Livro: Devolve um livro emprestado.
 * 5. Pesquisar Livro: Pesquisa um livro pelo ISBN.
 * 6. Gerar Relatório de Empréstimos: Gera um relatório de empréstimos por tipo de livro.
 * 7. Listagem por Categoria: Lista livros por categoria.
 * 8. Prorrogar Empréstimos: Prorroga os empréstimos.
 * 9. Sistema de Notificações de Atraso: Notifica leitores sobre atrasos.
 * 10. Listagem de Livros: Lista todos os livros da biblioteca.
 * 11. Editar Informações de Leitores: Edita informações dos leitores.
 * 12. Editar Informações de Livros: Edita informações dos livros.
 * 13. Importar Ficheiro: Importa dados de um ficheiro.
 * 14. Exportar Ficheiro: Exporta dados para um ficheiro.
 * 15. Remover Leitor: Remove um leitor da biblioteca.
 * 16. Remover Livro: Remove um livro da biblioteca.
 * 0. Sair: Encerra o programa.
 *
 * @return int Retorna 0 ao finalizar o programa.
 */
int main() {
    // Criando a biblioteca
    Biblioteca *bib = new Biblioteca();

    int opcao;
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "1 - Adicionar Livro\n"; //Adicionar livro por ISBN
        cout << "2 - Adicionar Leitor\n"; //Adicionar leitor por ID
        cout << "3 - Adicionar Emprestimo\n"; //Adicionar empréstimo por ISBN e ID
        cout << "4 - Devolver Livro\n"; //Devolver livro por ISBN e ID (remover empréstimo)
        cout << "5 - Pesquisar Livro\n"; //Pesquisar livro por ISBN
        cout << "6 - Gerar Relatorio de Emprestimos (Por tipo de livro)\n"; //Gerar relatório de empréstimos por tipo de livro
        cout << "7 - Listagem por Categoria\n"; //Gerar Lista de livros por categoria
        cout << "8 - Prorrogar Emprestimos\n"; //Prorrogar empréstimos 
        cout << "9 - Sistema de Notificacoes de Atraso\n"; //Sistema de notificações de atraso
        cout << "10 - Listagem de Livros\n"; //Listagem de todos os livros
        cout << "11 - Editar Informacoes Leitores\n"; //Editar informações de leitores
        cout << "12 - Editar Informacoes Livros\n"; //Editar informações de livros
        cout << "13 - Importar Ficheiro\n"; //Importar ficheiro
        cout << "14 - Exportar Ficheiro\n"; //Exportar ficheiro
        cout << "15 - Remover Leitor\n"; //Remover leitor por ID
        cout << "16 - Remover Livro\n"; //Remover livro por ISBN
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string titulo, autor, isbn, tipo, edicao;
                cout << "Titulo: ";
                cin >> titulo;
                cout << "Autor: ";
                cin >> autor;
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Tipo de Livro (Cientifico, Educacional, Ficcao, Revista): ";
                cin >> tipo;

                Livro *livro = nullptr;
                if (tipo == "Cientifico") {
                    livro = new LivroCientifico(titulo, autor, isbn, "Cientifico");
                } else if (tipo == "Educacional") {
                    livro = new LivroEducativo(titulo, autor, isbn, "Educational");
                } else if (tipo == "Ficção") {
                    livro = new LivroFiccao(titulo, autor, isbn, "Ficcao");
                } else if (tipo == "Revista") {
                    cout << "Edicao: ";
                    cin >> edicao;
                    livro = new Revista(titulo, autor, isbn, edicao);
                }

                if (livro) {
                    bib->Add_Livro(livro);
                    cout << "Livro adicionado com sucesso!" << endl;
                } else {
                    cout << "Tipo de livro invalido!" << endl;
                }
                break;
            }

            case 2: {
                string nome, id, tipoLeitor;
                cout << "Nome: ";
                cin >> nome;
                cout << "ID: ";
                cin >> id;
                cout << "Tipo de Leitor (Comum, Estudante, Professor, Senior): ";
                cin >> tipoLeitor;

                Leitor *leitor = nullptr;
                if (tipoLeitor == "Comum") {
                    leitor = new LeitorComum(nome, id);
                } else if (tipoLeitor == "Estudante") {
                    leitor = new Estudante(nome, id);
                } else if (tipoLeitor == "Professor") {
                    leitor = new Professor(nome, id);
                } else if (tipoLeitor == "Senior") {
                    leitor = new Senior(nome, id);
                }

                if (leitor) {
                    bib->Add_Leitor(leitor);
                    cout << "Leitor adicionado com sucesso!" << endl;
                } else {
                    cout << "Tipo de leitor invalido!" << endl;
                }
                break;
            }

            case 3: { // Adicionar empréstimo
                string isbn, id;
                cout << "ISBN do livro: ";
                cin >> isbn;
                cout << "ID do leitor: ";
                cin >> id;

                Livro *livro = nullptr;
                Leitor *leitor = nullptr;

                for (size_t i = 0; i < bib->Coleccao_LIVROS.size(); ++i) {
                    if (bib->Coleccao_LIVROS[i]->getIsbn() == isbn) {
                        livro = bib->Coleccao_LIVROS[i];
                        break;
                    }
                }

                for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) {
                    if (bib->Coleccao_LEITORES[i]->getID() == id) {
                        leitor = bib->Coleccao_LEITORES[i];
                        break;
                    }
                }

                if (livro && leitor) { // Se ambos foram encontrados
                    bib->Add_Emprestimo(livro, leitor);
                    cout << "Emprestimo realizado com sucesso!" << endl;
                } else {
                    cout << "Livro ou Leitor nao encontrado!" << endl;
                }
                break;
            }

            case 4: { // Devolver Livro
                string isbn, id;
                cout << "ISBN do livro: ";
                cin >> isbn;
                cout << "ID do leitor: ";
                cin >> id;

                Emprestimo* emprestimoDevolver = nullptr;

                for (size_t i = 0; i < bib->Coleccao_REQ.size(); ++i) {
                    if (bib->Coleccao_REQ[i]->getLivro()->getIsbn() == isbn &&
                        bib->Coleccao_REQ[i]->getLeitor()->getID() == id) {
                        emprestimoDevolver = bib->Coleccao_REQ[i];
                        break;
                    }
                }

                if (emprestimoDevolver) {
                    bib->Devolver_Livro(emprestimoDevolver);
                } else {
                    cout << "Emprestimo não encontrado!" << endl;
                }
                break;
            }

            case 5: {
                break;
            }

            case 6: {
                bib->Gerar_RelatorioEmprestimos();
                break;
            }

            case 7: {
                string categoria;
                cout << "Digite a categoria para o relatorio: ";
                cin >> categoria;
                bib->RelatorioCategoria(categoria);
                break;
            }

            case 8: {
                bib->Prorrogacao_Emprestimos();
                break;
            }

            case 9: {
                bib->Sistema_Notificacoes_Atraso();
                break;
            }

            case 10: {
                bib->Listagem_Livros();
                break;
            }

            case 11: {
                break;
            }

            case 12: {
                break;
            }

            case 13: {
                string nomeFicheiro;
                cout << "Digite o nome do ficheiro para importar: ";
                cin >> nomeFicheiro;
                if (bib->LoadFile(nomeFicheiro)) {
                    cout << "Ficheiro importado com sucesso!" << endl;
                } else {
                    cout << "Erro ao importar ficheiro!" << endl;
                }
                break;
            }

            case 14: {
                string nomeFicheiro;
                cout << "Digite o nome do ficheiro para exportar: ";
                cin >> nomeFicheiro;
                if (bib->SaveToFile(nomeFicheiro)) {
                    cout << "Ficheiro exportado com sucesso!" << endl;
                } else {
                    cout << "Erro ao exportar ficheiro!" << endl;
                }
                break;
            }

            case 15: {
                break;
            }

            case 16: {
                break;
            }

            case 0:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while (opcao != 0);

    delete bib;
    return 0;
}
