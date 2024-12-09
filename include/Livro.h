#ifndef Livro_H
#define Livro_H
#include <iostream>
#include <string>
#include <vector>
#include "Leitor.h"
using namespace std;

class Livro
{
    protected:
        string Titulo;
        string Autor;
        string isbn;
        string categoria;
        vector<Leitor*> reservas;
    public:
        Livro(string t, string a, string i, string c);
        virtual ~Livro();

        virtual string getTipo() const = 0;
        virtual int getPrazoEmprestimo() const = 0;
        virtual void EditarInformacoesLivro() = 0;

        string getTitulo() const;
        void setTitulo(string titulo);
        string getAutor() const;
        void setAutor(string autor);
        string getIsbn() const;
        void setIsbn(string isbn);
        void setCategoria(string categoria);
        string getCategoria() const;
        void adicionar_Reserva(Leitor* LT);
        void remover_Reserva(Leitor* LT);
        Leitor* Proximo_Leitor_Reserva() const;
        bool temReserva() const;
};

#endif // Livro_H
