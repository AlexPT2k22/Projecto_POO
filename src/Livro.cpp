#include "Livro.h"
#include "LivroEducativo.h"
#include "Estudante.h"

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

/**
 * @brief Adiciona uma reserva para um leitor.
 * 
 * Esta função adiciona um leitor à lista de reservas do livro. Se o livro for educativo
 * e o leitor for um estudante, a reserva é adicionada no início da lista, dando prioridade
 * aos estudantes para livros educativos. Caso contrário, a reserva é adicionada ao final
 * da lista.
 * 
 * @param LT Ponteiro para o leitor que deseja fazer a reserva.
 */
void Livro::adicionar_Reserva(Leitor* LT){
    if (dynamic_cast<LivroEducativo*>(this) && dynamic_cast<Estudante*>(LT)) {
        reservas.insert(reservas.begin(), LT); //adiciona o leitor no inicio da lista para livros educativos
    } else {
        reservas.push_back(LT);
    }
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


