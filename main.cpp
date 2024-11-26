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

int main() {
    // Criando a biblioteca
    Biblioteca *bib = new Biblioteca();

    int opcao;
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "1 - Adicionar Livro\n";
        cout << "2 - Adicionar Leitor\n";
        cout << "3 - Adicionar Emprestimo\n";
        cout << "4 - Devolver Livro\n";
        cout << "5 - Pesquisar Livros\n";
        cout << "6 - Gerar Relatorio de Emprestimos\n";
        cout << "7 - Relatório por Categoria\n";
        cout << "8 - Prorrogar Emprestimos\n";
        cout << "9 - Sistema de Notificacoes de Atraso\n";
        cout << "10 - Listagem de Livros\n";
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

                // Procura pelo livro
                for (auto &l : bib->Coleccao_LIVROS) {
                    if (l->getIsbn() == isbn) {
                        livro = l;
                        break;
                    }
                }

                // Procura pelo leitor
                for (auto &l : bib->Coleccao_LEITORES) {
                    if (l->getID() == id) {
                        leitor = l;
                        break;
                    }
                }

                if (livro && leitor) {
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

                for (Emprestimo* e : bib->Coleccao_REQ) {
                    if (e->getLivro()->getIsbn() == isbn && e->getLeitor()->getID() == id) {
                        emprestimoDevolver = e;
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
