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

using namespace std;

/**
 * @brief Função principal do programa.
 * 
 * @return 0
 */
int main()
{

    Biblioteca *bib = new Biblioteca(); //criar a biblioteca

    /*
    // Adicionar Livros
    bib->Add_Livro(new LivroFiccao("O Senhor dos Aneis", "J.R.R. Tolkien", "1234567890", "Fantasia", 3));
    bib->Add_Livro(new LivroEducativo("Calculo Vol 1", "James Stewart", "2345678901", "Matematica", "Superior", 5));
    bib->Add_Livro(new LivroCientifico("Fisica Quantica", "Richard Feynman", "3456789012", "Fisica", 2));
    bib->Add_Livro(new Revista("National Geographic", "National Geographic", "4567890123", "Ciencia", 156, 10));
    bib->Add_Livro(new Jornal("Publico", "Publico", "5678901234", "Noticias", 15, 20));

    // Adicionar Leitores
    bib->Add_Leitor(new LeitorComum("Ana Silva", "L001"));
    bib->Add_Leitor(new Estudante("Pedro Santos", "L002"));
    bib->Add_Leitor(new Professor("Maria Oliveira", "L003"));
    bib->Add_Leitor(new Senior("Jose Pereira", "L004"));

    // Criar alguns empréstimos
    Livro* livro1 = bib->Coleccao_LIVROS[0];  // Senhor dos Aneis
    Livro* livro2 = bib->Coleccao_LIVROS[1];  // Calculo
    Leitor* leitor1 = bib->Coleccao_LEITORES[0];  // Ana
    Leitor* leitor2 = bib->Coleccao_LEITORES[1];  // Pedro

    bib->Add_Emprestimo(livro1, leitor1); //adicionar um emprestimo
    bib->Add_Emprestimo(livro2, leitor2); //adicionar um emprestimo

    // Criar algumas reservas
    bib->reservarLivro("1234567890", bib->Coleccao_LEITORES[2]);  // Maria reserva Senhor dos Aneis
    bib->reservarLivro("2345678901", bib->Coleccao_LEITORES[3]);  // Jose reserva Calculo
    */

    int opcao;
    do
    {
        cout << "\n=== Biblioteca ===\n";
        cout << "Escolha uma opcao:\n";
        cout << "1 - Adicionar Livro\n";                                    // Adicionar livro por ISBN
        cout << "2 - Adicionar Leitor\n";                                   // Adicionar leitor por ID
        cout << "3 - Adicionar Emprestimo\n";                               // Adicionar empréstimo por ISBN e ID
        cout << "4 - Devolver Livro\n";                                     // Devolver livro por ISBN e ID (remover empréstimo)
        cout << "5 - Pesquisar Livro por Tipo\n";                           // Pesquisar livro por tipo
        cout << "6 - Gerar Relatorio de Emprestimos\n";                     // Gerar relatório de empréstimos ativos
        cout << "7 - Prorrogar Emprestimos\n";                              // Prorrogar empréstimos
        cout << "8 - Sistema de Notificacoes de Atraso\n";                  // Sistema de notificações de atraso
        cout << "9 - Listagem de Livros\n";                                 // Listagem de todos os livros
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

        switch (opcao) //switch para escolher a opcao
        {
        case 1: //adicionar livro
        {
            string titulo, autor, isbn, tipo, categoria;
            int dia, numCopias, edicao;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Adicionar Livro ===" << endl;
            cout << "Titulo: ";
            getline(cin, titulo); //ler o titulo
            cout << "Autor: ";
            getline(cin, autor); //ler o autor
            cout << "ISBN: ";
            cin >> isbn; //ler o isbn
            cout << "Tipo de Livro (Cientifico, Educacional, Ficcao, Revista, Jornal): ";
            cin >> tipo; //ler o tipo
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "Categoria: ";
            getline(cin, categoria); //ler a categoria
            cout << "Numero de copias: ";
            cin >> numCopias; //ler o numero de copias


            Livro *livro = nullptr; //livro a ser adicionado
            if (tipo == "Cientifico" || tipo == "cientifico") //se o tipo for cientifico
            {
                livro = new LivroCientifico(titulo, autor, isbn, categoria, numCopias); //criar um novo livro cientifico
            }
            else if (tipo == "Educacional" || tipo == "educacional") //se o tipo for educacional
            {
                string grau; //grau de escolaridade
                cout << "Grau de escolaridade: ";
                cin.ignore();
                getline(cin, grau);
                livro = new LivroEducativo(titulo, autor, isbn, categoria, grau, numCopias); //criar um novo livro educacional
            }
            else if (tipo == "Ficcao" || tipo == "ficcao") //se o tipo for ficcao
            {
                livro = new LivroFiccao(titulo, autor, isbn, categoria, numCopias); //criar um novo livro ficcao
            }
            else if (tipo == "Revista" || tipo == "revista") //se o tipo for revista
            {
                cout << "Edicao: ";
                cin >> edicao;
                livro = new Revista(titulo, autor, isbn, categoria, edicao, numCopias); //criar uma nova revista
            }
            else if (tipo == "Jornal" || tipo == "jornal") //se o tipo for jornal
            {
                cout << "Dia: ";
                cin >> dia;
                livro = new Jornal(titulo, autor, isbn, categoria, dia, numCopias); //criar um novo jornal
            }


            if (livro) //se o livro foi criado
            {
                bib->Add_Livro(livro); //adicionar o livro a biblioteca
            }
            else
            {
                cout << "Tipo de livro invalido!" << endl; //tipo de livro invalido
            }
            break;
        }
        case 2: //adicionar leitor
        {
            string nome, id, tipoLeitor;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Adicionar Leitor ===" << endl;
            cout << "Nome: ";
            getline(cin, nome); //ler o nome
            cout << "ID: ";
            cin >> id; //ler o id
            cout << "Tipo de Leitor (Comum, Estudante, Professor, Senior): ";
            cin >> tipoLeitor; //ler o tipo de leitor

            Leitor *leitor = nullptr; //leitor a ser adicionado
            if (tipoLeitor == "Comum" || tipoLeitor == "comum") //se o tipo de leitor for comum
            {
                leitor = new LeitorComum(nome, id); //criar um novo leitor comum
            }
            else if (tipoLeitor == "Estudante" || tipoLeitor == "estudante") //se o tipo de leitor for estudante
            {
                leitor = new Estudante(nome, id); //criar um novo estudante
            }
            else if (tipoLeitor == "Professor" || tipoLeitor == "professor") //se o tipo de leitor for professor
            {
                leitor = new Professor(nome, id); //criar um novo professor
            }
            else if (tipoLeitor == "Senior" || tipoLeitor == "senior") //se o tipo de leitor for senior
            {
                leitor = new Senior(nome, id); //criar um novo senior
            }

            if (leitor) //se o leitor foi criado
            {
                bib->Add_Leitor(leitor); //adicionar o leitor a biblioteca
                cout << "Leitor adicionado com sucesso!" << endl; //informar que o leitor foi adicionado com sucesso
            }
            else
            {
                cout << "Tipo de leitor invalido!" << endl; //tipo de leitor invalido
            }
            break;
        }
        case 3:
        { // Adicionar empréstimo
            string isbn, id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Adicionar Emprestimo ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;

            Livro *livro = nullptr; //livro a ser emprestado
            Leitor *leitor = nullptr; //leitor a ser emprestado

            for (size_t i = 0; i < bib->Coleccao_LIVROS.size(); ++i) //procurar o livro a ser emprestado
            {
                if (bib->Coleccao_LIVROS[i]->getIsbn() == isbn) //se o isbn do livro for igual ao isbn do livro a ser emprestado
                {
                    livro = bib->Coleccao_LIVROS[i]; //atribuir o livro a ser emprestado
                    break;
                }
            }

            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) //procurar o leitor a ser emprestado
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id) //se o id do leitor for igual ao id do leitor a ser emprestado
                {
                    leitor = bib->Coleccao_LEITORES[i];
                    break;
                }
            }

            if (livro && leitor) //se o livro e o leitor foram encontrados  
            {
                bib->Add_Emprestimo(livro, leitor); //adicionar o emprestimo a biblioteca
            }
            else
            {
                cout << "Livro ou Leitor nao encontrado!" << endl; //livro ou leitor nao encontrado
            }
            break;
        }
        case 4:
        { // Devolver Livro
            string isbn, id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Devolver Livro ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;

            Emprestimo *emprestimoDevolver = nullptr; //emprestimo a ser devolvido

            for (size_t i = 0; i < bib->Coleccao_REQ.size(); ++i) //procurar o emprestimo a ser devolvido
            {
                if (bib->Coleccao_REQ[i]->getLivro()->getIsbn() == isbn && //se o isbn do livro for igual ao isbn do livro do emprestimo a ser devolvido
                    bib->Coleccao_REQ[i]->getLeitor()->getID() == id) //se o id do leitor for igual ao id do leitor do emprestimo a ser devolvido
                {
                    emprestimoDevolver = bib->Coleccao_REQ[i]; //atribuir o emprestimo a ser devolvido
                    break;
                }
            }

            if (emprestimoDevolver) //se o emprestimo foi encontrado
            {
                bib->Devolver_Livro(emprestimoDevolver); //devolver o livro
            }
            else
            {
                cout << "Emprestimo não encontrado!" << endl; //emprestimo nao encontrado
            }
            break;
        }
        case 5: //pesquisar livro por tipo
        {
            string tipo;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Pesquisar Livro por Tipo ===" << endl;
            cout << "Tipo de Livro (Cientifico, Educacional, Ficcao, Revista, Jornal): ";
            cin >> tipo;
            bib->Pesquisar_Livro_Tipo(tipo); //pesquisar o livro por tipo
            break;
        }
        case 6: //gerar relatorio de emprestimos
        {
            bib->Gerar_RelatorioEmprestimos(); //gerar o relatorio de emprestimos
            break;
        }
        case 7: //prorrogar emprestimos
        {
            string id, isbn;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Prorrogar Emprestimos ===" << endl;
            cout << "ID do leitor: ";
            cin >> id;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Prorrogacao_Emprestimos(id, isbn); //prorrogar o emprestimo
            break;
        }
        case 8: //sistema de notificacoes de atraso
        {
            bib->Sistema_Notificacoes_Atraso(); //sistema de notificacoes de atraso
            break;
        }
        case 9: //listagem de livros
        {
            bib->Listagem_Livros(); //listar os livros
            break;
        }
        case 10: //editar informacoes de leitores
        {
            string id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Editar Informacoes Leitores ===" << endl;
            cout << "ID do leitor: ";
            cin >> id;
            bib->Editar_InformacoesLeitores(id); //editar as informacoes do leitor
            break;
        }
        case 11: //editar informacoes de livros
        {
            string isbn;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Editar Informacoes Livros ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Editar_InformacoesLivros(isbn); //editar as informacoes do livro
            break;
        }
        case 12: //importar ficheiro
        {
            string nomeFicheiro;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Importar Ficheiro ===" << endl;
            cout << "Digite o nome do ficheiro para importar (.csv): "; //nome do ficheiro a ser importado
            cin >> nomeFicheiro;
            bib->LoadFile(nomeFicheiro); //importar o ficheiro
            break;
        }
        case 13: //exportar ficheiro
        {
            string nomeFicheiro;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Exportar Ficheiro ===" << endl;
            cout << "Digite o nome do ficheiro para exportar (.csv): "; //nome do ficheiro a ser exportado
            cin >> nomeFicheiro;
            bib->SaveToFile(nomeFicheiro); //exportar o ficheiro
            break;
        }
        case 14: //remover leitor
        {
            string id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Remover Leitor ===" << endl;
            cout << "ID do leitor: ";
            cin >> id;
            Leitor *leitor = nullptr; //leitor a ser removido
            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) //procurar o leitor a ser removido
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id) //se o id do leitor for igual ao id do leitor a ser removido
                {
                    leitor = bib->Coleccao_LEITORES[i]; //atribuir o leitor a ser removido
                    break;
                }
            }
            if (!leitor){ //se o leitor nao foi encontrado
                cout << "Leitor nao encontrado!" << endl; //leitor nao encontrado
            }else{
                bib->Remover_Leitor(id); //remover o leitor
            }
            break; 
        }
        case 15: //remover livro
        {   
            string isbn;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Remover Livro ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            bib->Remover_Livro(isbn); //remover o livro
            break;
        }
        case 16: //reservar livro
        {
            string isbn, id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Reservar Livro ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;
            Leitor *leitor = nullptr; //leitor a ser reservado
            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) //procurar o leitor a ser reservado
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id) //se o id do leitor for igual ao id do leitor a ser reservado
                {
                    leitor = bib->Coleccao_LEITORES[i]; //atribuir o leitor a ser reservado
                    break;
                }
            }
            if (!leitor){ //se o leitor nao foi encontrado
                cout << "Leitor nao encontrado!" << endl; //leitor nao encontrado
            }else{
                bib->reservarLivro(isbn, leitor); //reservar o livro
            }
            break;
        }
        case 17: //listar reservas
        {
            bib->ListarReservas(); //listar as reservas
            break;
        }
        case 18: //cancelar reserva
        {
            string isbn, id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Cancelar Reserva ===" << endl;
            cout << "ISBN do livro: ";
            cin >> isbn;
            cout << "ID do leitor: ";
            cin >> id;
            Leitor *leitor = nullptr; //leitor a ser cancelado
            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) //procurar o leitor a ser cancelado
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id) //se o id do leitor for igual ao id do leitor a ser cancelado
                {
                    leitor = bib->Coleccao_LEITORES[i]; //atribuir o leitor a ser cancelado
                    break;
                }
            }
            if (!leitor){ //se o leitor nao foi encontrado
                cout << "Leitor nao encontrado!" << endl; //leitor nao encontrado
            }else{
                bib->cancelar_reserva(isbn, id); //cancelar a reserva
            }
            break;
        }
        case 19: //gerar relatorio de multas pendentes
        {
            bib->GerarRelatorioMultasPendentes(); //gerar o relatorio de multas pendentes
            break;
        }
        case 20: //gerar relatorio de emprestimos por tipo
        {
            bib->GerarRelatorioEmprestimosPorTipo(); //gerar o relatorio de emprestimos por tipo
            break;
        }
        case 21: //gerar historico de emprestimos por leitor
        {
            string id;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Gerar Historico de Emprestimos por Leitor ===" << endl;
            cout << "ID do leitor: ";
            cin >> id;
            Leitor *leitor = nullptr; //leitor a ser procurado
            for (size_t i = 0; i < bib->Coleccao_LEITORES.size(); ++i) //procurar o leitor a ser procurado
            {
                if (bib->Coleccao_LEITORES[i]->getID() == id) //se o id do leitor for igual ao id do leitor a ser procurado
                {
                    leitor = bib->Coleccao_LEITORES[i]; //atribuir o leitor a ser procurado
                    break;
                }
            }
            if (!leitor){ //se o leitor nao foi encontrado
                cout << "Leitor nao encontrado!" << endl; //leitor nao encontrado
            }else{
                bib->GerarHistoricoEmprestimosLeitor(leitor); //gerar o historico de emprestimos do leitor
            }
            break;
        }
        case 22: //listar livros por categoria
        {
            string categoria;
            cin.ignore(); // Limpar buffer do enter da opcao
            cout << "=== Listar Livros por Categoria ===" << endl;
            cout << "Categoria: ";
            cin >> categoria;
            bib->ListarLivrosCategoria(categoria); //listar os livros por categoria
            break;
        }
        case 0: //sair
            cout << "A sair..." << endl;
            break;

        default: //opcao invalida
            cout << "Opcao invalida!" << endl; //opcao invalida
            break;
        }
    } while (opcao != 0); //sair do loop

    delete bib; //deletar a biblioteca
    return 0;
}
