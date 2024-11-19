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
    public:
        Livro(string t, string a, string i);
        virtual ~Livro();

        virtual string getTipo() const = 0;
        virtual int getPrazoEmprestimo() const = 0;

        bool estaDisponivel() const;
        void setDisponivel(bool d);
        string getTitulo() const;
        string getAutor() const;
        string getIsbn() const;
};

#endif // Livro_H
