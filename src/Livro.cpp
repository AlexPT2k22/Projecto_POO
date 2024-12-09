#include "Livro.h"

Livro::Livro(string t, string a, string i, string c): Titulo(t), Autor(a), isbn(i), categoria(c)
{
    //constructor
}


Livro::~Livro()
{
    //destructor
}

string Livro::getTitulo() const {return Titulo;}

string Livro::getAutor() const {return Autor;}

string Livro::getIsbn() const {return isbn;}

string Livro::getCategoria() const {return categoria;}

void Livro::setCategoria(string c) {
    categoria = c;
}

void Livro::setTitulo(string t) {
    Titulo = t;
}

void Livro::setAutor(string a) {
    Autor = a;
}

void Livro::setIsbn(string i) {
    isbn = i;
}

void Livro::adicionar_Reserva(Leitor* LT){
    reservas.push_back(LT);
}

void Livro::remover_Reserva(Leitor* LT){
    for (size_t i = 0; i < reservas.size(); ++i) {
        if (reservas[i] == LT) {
            reservas.erase(reservas.begin() + i);
            return;
        }
    }
}

Leitor* Livro::Proximo_Leitor_Reserva() const{
    if (!reservas.empty()) {
        return reservas.front(); //retorna o primeiro leitor da lista
    }
    return nullptr;
}

bool Livro::temReserva() const{
    return !reservas.empty();
}


