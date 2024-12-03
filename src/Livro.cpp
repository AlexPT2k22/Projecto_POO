#include "Livro.h"

Livro::Livro(string t, string a, string i, string c): Titulo(t), Autor(a), isbn(i), categoria(c), Disponivel(true)
{
    //constructor
}


Livro::~Livro()
{
    //destructor
}

bool Livro::estaDisponivel() const {return Disponivel;}

void Livro::setDisponivel(bool d) {Disponivel = d;}

string Livro::getTitulo() const {return Titulo;}

string Livro::getAutor() const {return Autor;}

string Livro::getIsbn() const {return isbn;}

string Livro::getCategoria() const {return categoria;}

void Livro::setCategoria(string c) {
    categoria = c;
}