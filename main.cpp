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
#include "Emprestimo.h"
#include "Jornal.h"


/* TODO:
    - Relatório de Empréstimos por Tipo de Livro
    - Histórico de Empréstimos por Leitor
    - Relatório de Multas pendentes
    - Gravar e Carregar Ficheiros
    - Adicionar Jornal
*/

using namespace std;

int main()
{
    // Criando a biblioteca
    Biblioteca *bib = new Biblioteca();

    int opcao;
    do
    {
        cout << "\nEscolha uma opcao:\n";
        cout << "1 - Adicionar Livro\n";                                    // Adicionar livro por ISBN
        cout << "2 - Adicionar Leitor\n";                                   // Adicionar leitor por ID
        cout << "3 - Adicionar Emprestimo\n";                               // Adicionar empréstimo por ISBN e ID
        cout << "4 - Devolver Livro\n";                                     // Devolver livro por ISBN e ID (remover empréstimo)
        cout << "5 - Pesquisar Livro por Tipo\n";                           // Pesquisar livro por tipo
        cout << "6 - Gerar Relatorio de Emprestimos\n";                     // Gerar relatório de empréstimos ativos
        cout << "7 - Prorrogar Emprestimos\n";                              // Prorrogar empréstimos
        cout << "8 - Sistema de Notificacoes de Atraso\n";                  // Sistema de notificações de atraso
        cout << "9 - Listagem de Livros\n";                                // Listagem de todos os livros
        cout << "10 - Editar Informacoes Leitores\n";                       // Editar informações de leitores
        cout << "11 - Editar Informacoes Livros\n";                         // Editar informações de livros
        cout << "12 - Importar Ficheiro\n";                                 // Importar ficheiro
        cout << "13 - Exportar Ficheiro\n";                                 // Exportar ficheiro
        cout << "14 - Remover Leitor\n";                                    // Remover leitor por ID
        cout << "15 - Remover Livro\n";                                     // Remover livro por ISBN
        cout << "16 - Reservar Livro\n";                                    // Reservar livro por ISBN
        cout << "17 - Listar Reservas\n";                                   // Listar reservas
        cout << "18 - Cancelar Reserva\n";                                  // Cancelar reserva por ISBN e ID
        cout << "19 - Gerar Relatorio de Multas Pendentes\n";               // Gerar relatório de multas pendentes
        cout << "20 - Gerar Relatorio de Emprestimos por Tipo de Livro\n";  // Gerar relatório de empréstimos por tipo de livro
        cout << "21 - Gerar Relatorio de Emprestimos por Leitor\n";         // Gerar relatório de empréstimos por leitor  
        cout << "22 - Listagem de Livros por Categoria\n";                  // Listagem de livros por categoria
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            string titulo, autor, isbn, tipo, edicao, categoria, numCopias, dia;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "Titulo: ";
            getline(cin, titulo);
            cout << "Autor: ";
            getline(cin, autor);
            cout << "ISBN: ";
            cin >> isbn;
            cout << "Tipo de Livro (Cientifico, Educacional, Ficcao, Revista, Jornal): ";
            cin >> tipo;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "Categoria: ";
            getline(cin, categoria);
            cout << "Numero de copias: ";
            cin >> numCopias;


            Livro *livro = nullptr;
            if (tipo == "Cientifico" || tipo == "cientifico")
            {
                livro = new LivroCientifico(titulo, autor, isbn, categoria, stoi(numCopias));
            }
            else if (tipo == "Educacional" || tipo == "educacional")
            {
                string grau;
                cout << "Grau de escolaridade: ";
                cin.ignore();
                getline(cin, grau);
                livro = new LivroEducativo(titulo, autor, isbn, categoria, grau, stoi(numCopias));
            }
            else if (tipo == "Ficcao" || tipo == "ficcao")
            {
                livro = new LivroFiccao(titulo, autor, isbn, categoria, stoi(numCopias));
            }
            else if (tipo == "Revista" || tipo == "revista")
            {
                cout << "Edicao: ";
                cin >> edicao;
                livro = new Revista(titulo, autor, isbn, categoria, edicao, stoi(numCopias));
            }
            else if (tipo == "Jornal" || tipo == "jornal")
            {
                cout << "Dia: ";
                cin >> dia;
                livro = new Jornal(titulo, autor, isbn, dia, stoi(numCopias));
            }


            if (livro)
            {
                bib->Add_Livro(livro);
            }
            else
            {
                cout << "Tipo de livro invalido!" << endl;
            }
            break;
        }

        case 2:
        {
            string nome, id, tipoLeitor;
            cout << "Nome: ";
            cin >> nome;
            cout << "ID: ";
            cin >> id;
            cout << "Tipo de Leitor (Comum, Estudante, Professor, Senior): ";
            cin >> tipoLeitor;

            Leitor *leitor = nullptr;
            if (tipoLeitor == "Comum" || tipoLeitor == "comum")
            {
                leitor = new LeitorComum(nome, id);
            }
            else if (tipoLeitor == "Estudante" || tipoLeitor == "estudante")
            {
                leitor = new Estudante(nome, id);
            }
            else if (tipoLeitor == "Professor" || tipoLeitor == "professor")
            {
                leitor = new Professor(nome, id);
            }
            else if (tipoLeitor == "Senior" || tipoLeitor == "senior")
            {
                leitor = new Senior(nome, id);
            }

            if (leitor)
            {
                bib->Add_Leitor(leitor);
                cout << "Leitor adicionado com sucesso!" << endl;
            }
            else
            {
                cout << "Tipo de leitor invalido!" << endl;
            }
            break;
        }

        case 3:
        { // Adicionar empréstimo
            string isbn, id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;

            Livro *livro = nullptr;
            Leitor *leitor = nullptr;

            for (size_t i = 0; i < bib->Coleccao_LIVROS.size(); ++i)
            {
                if (bib->Coleccao_LIVROS[i]->getIsbn() == isbn)
                {
                    livro = bib->Coleccao_LIVROS[i];
                    break;
                }
            }

            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i)
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id)
                {
                    leitor = bib->Coleccao_LEITORES[i];
                    break;
                }
            }

            if (livro && leitor)
            { // Se ambos foram encontrados
                bib->Add_Emprestimo(livro, leitor);
            }
            else
            {
                cout << "Livro ou Leitor nao encontrado!" << endl;
            }
            break;
        }

        case 4:
        { // Devolver Livro
            string isbn, id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;

            Emprestimo *emprestimoDevolver = nullptr;

            for (size_t i = 0; i < bib->Coleccao_REQ.size(); ++i)
            {
                if (bib->Coleccao_REQ[i]->getLivro()->getIsbn() == isbn &&
                    bib->Coleccao_REQ[i]->getLeitor()->getID() == id)
                {
                    emprestimoDevolver = bib->Coleccao_REQ[i];
                    break;
                }
            }

            if (emprestimoDevolver)
            {
                bib->Devolver_Livro(emprestimoDevolver);
            }
            else
            {
                cout << "Emprestimo não encontrado!" << endl;
            }
            break;
        }

        case 5:
        {
            string tipo;
            cout << "Tipo de Livro (Cientifico, Educacional, Ficcao, Revista): ";
            cin >> tipo;
            bib->Pesquisar_Livro_Tipo(tipo);
            break;
        }

        case 6:
        {
            bib->Gerar_RelatorioEmprestimos();
            break;
        }

        case 7:
        {
            string id, isbn;
            cout << "ID do leitor: ";
            cin >> id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Prorrogacao_Emprestimos(id, isbn);
            break;
        }

        case 8:
        {
            bib->Sistema_Notificacoes_Atraso();
            break;
        }

        case 9:
        {
            bib->Listagem_Livros();
            break;
        }

        case 10:
        {
            string id;
            cout << "ID do leitor: ";
            cin >> id;
            bib->Editar_InformacoesLeitores(id);
            break;
        }

        case 11: // Editar Informacoes Livros (categoria de um tipo de livro, ediçao de revista, etc)
        {
            string isbn;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Editar_InformacoesLivros(isbn);
            break;
        }

        case 12:
        {
            string nomeFicheiro;
            cout << "Digite o nome do ficheiro para importar: ";
            cin >> nomeFicheiro;
            if (bib->LoadFile(nomeFicheiro)) //TODO:
            {
                cout << "Ficheiro importado com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao importar ficheiro!" << endl;
            }
            break;
        }

        case 13:
        {
            string nomeFicheiro;
            cout << "Digite o nome do ficheiro para exportar: ";
            cin >> nomeFicheiro;
            if (bib->SaveToFile(nomeFicheiro)) //TODO:
            {
                cout << "Ficheiro exportado com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao exportar ficheiro!" << endl;
            }
            break;
        }

        case 14:
        {
            string id;
            cout << "ID do leitor: ";
            cin >> id;
            bib->Remover_Leitor(id);
            break; 
        }

        case 15:
        {   
            string isbn;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Remover_Livro(isbn);
            break;
        }

        case 16:
        {
            string isbn, id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;
            Leitor *leitor = nullptr;
            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) {
                if (bib->Coleccao_LEITORES[i]->getID() == id) {
                    leitor = bib->Coleccao_LEITORES[i];
                    break;
                }
            }
            if (!leitor){
                cout << "Leitor nao encontrado!" << endl;
            }else{
                bib->reservarLivro(isbn, leitor);
            }
            break;
        }

        case 17:
        {
            bib->ListarReservas();
            break;
        }

        case 18:
        {
            string isbn, id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;
            bib->cancelar_reserva(isbn, id);
            break;
        }

        case 19:
        {
            //bib->GerarRelatorioMultasPendentes(); //TODO: multas pendentes
            break;
        }

        case 20:
        {
            //bib->GerarRelatorioEmprestimosPorTipo(); //TODO: empréstimos por tipo de livro
            break;
        }

        case 21:
        {
            //bib->GerarRelatorioEmprestimosPorLeitor(); //TODO: historico de emprestimos por leitor
            break;
        }

        case 22:
        {
            string categoria;
            cout << "Categoria: ";
            cin >> categoria;
            bib->ListarLivrosCategoria(categoria);
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
