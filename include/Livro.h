#ifndef Livro_H
#define Livro_H
#include <iostream>
#include <string>
#include <vector>
#include "Leitor.h"
using namespace std;

/**
 * @brief Classe base para representar um livro na biblioteca
 * 
 * Esta classe define as características e comportamentos comuns a todos os tipos de livros
 */
class Livro
{
    protected:
        string Titulo;
        string Autor;
        string isbn;
        string categoria;
        int total_copias;
        int copias_emprestadas;
        
    public:
        Livro(string t, string a, string i, string c, int numCopias); //Construtor
        virtual ~Livro(); //Destrutor
        vector<Leitor*> reservas; //Lista de reservas
        virtual string getTipo() const = 0; //Obtém o tipo de livro
        virtual int getPrazoEmprestimo() const = 0; //Obtém o prazo de empréstimo do livro
        virtual void EditarInformacoesLivro() = 0; //Edita as informações do livro

        string getTitulo() const; //Obtém o título do livro
        void setTitulo(string titulo); //Define o título do livro
        string getAutor() const; //Obtém o autor do livro
        void setAutor(string autor); //Define o autor do livro
        string getIsbn() const; //Obtém o ISBN do livro
        void setIsbn(string isbn); //Define o ISBN do livro
        void setCategoria(string categoria); //Define a categoria do livro
        string getCategoria() const; //Obtém a categoria do livro
        void adicionar_Reserva(Leitor* LT); //Adiciona uma reserva
        void remover_Reserva(Leitor* LT); //Remove uma reserva
        Leitor* Proximo_Leitor_Reserva() const; //Obtém o próximo leitor da reserva
        bool temReserva() const; //Verifica se o livro tem reserva
        int getCopiasDisponiveis() const; //Obtém o número de cópias disponíveis
        bool emprestar_Copia(); //Empresta uma cópia
        void devolver_Copia(); //Devolve uma cópia
        int getNumCopias() const; //Obtém o número de cópias
        void setNumCopias(int numCopias); //Define o número de cópias
};

#endif // Livro_H
