#ifndef Livro_H
#define Livro_H
#include <iostream>
#include <string>
using namespace std;

class Livro
{
    protected:
        string Titulo;
        string Autor;
        string isbn;
        bool Disponivel;
        string categoria;
    public:
        Livro(string t, string a, string i, string c);
        virtual ~Livro();

        virtual string getTipo() const = 0;
        virtual int getPrazoEmprestimo() const = 0;
        virtual void EditarInformacoesLivro() = 0;

        bool estaDisponivel() const;
        void setDisponivel(bool d);
        string getTitulo() const;
        void setTitulo(string titulo);
        string getAutor() const;
        void setAutor(string autor);
        string getIsbn() const;
        void setIsbn(string isbn);
        void setCategoria(string categoria);
        string getCategoria() const;
};

#endif // Livro_H
