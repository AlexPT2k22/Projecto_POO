#include <iostream>
#include <string>
#include "Biblioteca.h"
#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroFiccao.h"
#include "Revista.h"

using namespace std;

int main() {
    Biblioteca *BIB = new Biblioteca();

    int opcao;
    do {
        cout << "==== Biblioteca ====" << endl;
        cout << "1 - Adicionar Livro" << endl;
        cout << "2 - Adicionar Leitor" << endl;
        cout << "3 - Adicionar Emprestimo" << endl;
        cout << "4 - Devolver Livro" << endl;
        cout << "5 - Pesquisar Livros" << endl;
        cout << "6 - Gerar Relatorio de Emprestimos" << endl;
        cout << "7 - Relatorio por Categoria" << endl;
        cout << "8 - Prorrogar Emprestimos" << endl;
        cout << "9 - Sistema de Notificacoes de Atraso" << endl;
        cout << "10 - Listagem de Livros" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1: // Adicionar Livro
            {
                int tipoLivro;
                cout << "Selecione o tipo de livro:" << endl;
                cout << "1 - Científico" << endl;
                cout << "2 - Educacional" << endl;
                cout << "3 - Ficção" << endl;
                cout << "4 - Revista" << endl;
                cout << "Opção: ";
                cin >> tipoLivro;

                string titulo, autor, isbn, genero, edicao;
                cin.ignore(); // Limpa o buffer de entrada
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Genero: ";
                cin >> genero;

                Livro *L = nullptr;

                switch (tipoLivro) {
                    case 1:
                        L = new LivroCientifico(titulo, autor, isbn, genero);
                        break;
                    case 2:
                        L = new LivroEducativo(titulo, autor, isbn, genero);
                        break;
                    case 3:
                        L = new LivroFiccao(titulo, autor, isbn, genero);
                        break;
                    case 4:
                        cout << "Número da edição: ";
                        cin >> edicao;
                        L = new Revista(titulo, autor, isbn, edicao);
                        break;
                    default:
                        cout << "Tipo inválido!" << endl;
                        break;
                }

                if (L) {
                    BIB->Add_Livro(L);
                    cout << "Livro adicionado com sucesso!" << endl;
                }
            }
            break;

        case 2: // Adicionar Leitor
            {
                string nome, id;
                cout << "Nome do leitor: ";
                cin.ignore();
                getline(cin, nome);
                cout << "ID do leitor: ";
                cin >> id;
                Leitor *LT = new Leitor(nome, id);
                if (BIB->Add_Leitor(LT)) {
                    cout << "Leitor adicionado com sucesso!" << endl;
                } else {
                    cout << "Erro ao adicionar leitor!" << endl;
                }
            }
            break;

        case 3: // Adicionar Empréstimo
            {
                string isbn, id;
                cout << "ISBN do livro: ";
                cin >> isbn;
                cout << "ID do leitor: ";
                cin >> id;

                Livro *L = nullptr;
                Leitor *LT = nullptr;

                for (Livro *livro : BIB->Coleccao_LIVROS) {
                    if (livro->getIsbn() == isbn) {
                        L = livro;
                        break;
                    }
                }

                for (Leitor *leitor : BIB->Coleccao_LEITORES) {
                    if (leitor->getID() == id) {
                        LT = leitor;
                        break;
                    }
                }

                if (L && LT) {
                    BIB->Add_Emprestimo(L, LT);
                    cout << "Empréstimo adicionado com sucesso!" << endl;
                } else {
                    cout << "Livro ou Leitor não encontrado!" << endl;
                }
            }
            break;

        case 4: // Devolver Livro
            cout << "Função de devolução de livros ainda não implementada." << endl;
            break;

        case 5: // Pesquisar Livros
            {
                string genero;
                cout << "Digite o gênero do livro: ";
                cin >> genero;
                BIB->Pesquisar_Livros(genero);
            }
            break;

        case 6: // Gerar Relatório de Empréstimos
            BIB->Gerar_RelatorioEmprestimos();
            break;

        case 7: // Relatório por Categoria
            {
                string tipo;
                cout << "Digite o tipo de livro (Científico, Educacional, Ficção, Revista): ";
                cin >> tipo;
                BIB->RelatorioCategoria(tipo);
            }
            break;

        case 8: // Prorrogar Empréstimos
            BIB->Prorrogacao_Emprestimos();
            break;

        case 9: // Sistema de Notificações de Atraso
            BIB->Sistema_Notificacoes_Atraso();
            break;

        case 10: // Listagem de Livros
            BIB->Listagem_Livros();
            break;

        case 0: // Sair
            cout << "Saindo do sistema..." << endl;
            break;

        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 0);

    delete BIB;
    return 0;
}