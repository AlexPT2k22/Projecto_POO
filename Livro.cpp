#include "Livro.h"

Livro::Livro(string t, string a, string i): Titulo(t), Autor(a), isbn(i), Disponivel(true)
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