#include "Livro.h"
#include "LivroEducativo.h"
#include "Estudante.h"

/**
 * @brief Construtor da classe Livro.
 * 
 * @param t O título do livro.
 * @param a O autor do livro.
 * @param i O ISBN do livro.
 * @param c A categoria do livro.
 * @param numCopias O número de cópias do livro.
 */
Livro::Livro(string t, string a, string i, string c, int numCopias): Titulo(t), Autor(a), isbn(i), categoria(c), total_copias(numCopias), copias_emprestadas(0)
{
    //constructor
}

/**
 * @brief Destrutor da classe Livro.
 */
Livro::~Livro()
{
    //destructor
}

/**
 * @brief Obtém o número de cópias do livro.
 * 
 * @return O número de cópias do livro.
 */
int Livro::getNumCopias() const{
    return total_copias; //retornar o número de cópias
}

/**
 * @brief Define o número de cópias do livro.
 * 
 * @param numCopias O número de cópias do livro.
 */
void Livro::setNumCopias(int numCopias){
    total_copias = numCopias; //atribuir o número de cópias
}

/**
 * @brief Obtém o número de cópias disponíveis do livro.
 * 
 * @return O número de cópias disponíveis do livro.
 */
int Livro::getCopiasDisponiveis() const{
    return total_copias - copias_emprestadas; //retornar o número de cópias disponíveis
}

/**
 * @brief Empresta uma cópia do livro.
 * 
 * @return true se a cópia foi emprestada com sucesso, false caso contrário.
 */
bool Livro::emprestar_Copia(){
    if (getCopiasDisponiveis() > 0){ //se tem cópias disponíveis
        copias_emprestadas++; //incrementar o número de cópias emprestadas
        return true; //retornar true
    }
    return false; //nao tem copias disponiveis
}

/**
 * @brief Devolve uma cópia do livro.
 */
void Livro::devolver_Copia(){
    if (copias_emprestadas > 0){ //se tem cópias emprestadas
        copias_emprestadas--; //decrementar o número de cópias emprestadas
    }
}

/**
 * @brief Obtém o título do livro.
 * 
 * @return O título do livro.
 */
string Livro::getTitulo() const {
    return Titulo; //retornar o título do livro
}

/**
 * @brief Obtém o autor do livro.
 * 
 * @return O autor do livro.
 */
string Livro::getAutor() const {
    return Autor; //retornar o autor do livro
}

/**
 * @brief Obtém o ISBN do livro.
 * 
 * @return O ISBN do livro.
 */
string Livro::getIsbn() const {
    return isbn; //retornar o ISBN do livro
}

/**
 * @brief Obtém a categoria do livro.
 * 
 * @return A categoria do livro.
 */
string Livro::getCategoria() const {
    return categoria; //retornar a categoria do livro
}

/**
 * @brief Define a categoria do livro.
 * 
 * @param c A categoria do livro.
 */
void Livro::setCategoria(string c) {
    categoria = c; //atribuir a categoria
}

/**
 * @brief Define o título do livro.
 * 
 * @param t O título do livro.
 */
void Livro::setTitulo(string t) {
    Titulo = t; //atribuir o título
}

/**
 * @brief Define o autor do livro.
 * 
 * @param a O autor do livro.
 */
void Livro::setAutor(string a) {
    Autor = a; //atribuir o autor
}

/**
 * @brief Define o ISBN do livro.
 * 
 * @param i O ISBN do livro.
 */
void Livro::setIsbn(string i) {
    isbn = i; //atribuir o ISBN
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
    if (dynamic_cast<LivroEducativo*>(this) && dynamic_cast<Estudante*>(LT)) { //se o livro é educativo e o leitor é estudante (dynamic_cast é uma função que verifica se o leitor é estudante)
        reservas.insert(reservas.begin(), LT); //adiciona o leitor no inicio da lista para livros educativos
    } else {
        reservas.push_back(LT); //adiciona o leitor no final da lista para livros nao educativos
    }
}

/**
 * @brief Remove uma reserva de um leitor.
 * 
 * @param LT Ponteiro para o leitor que deseja remover a reserva.
 */
void Livro::remover_Reserva(Leitor* LT){
    for (size_t i = 0; i < reservas.size(); ++i) { //para cada leitor na lista de reservas
        if (reservas[i] == LT) { //se o leitor é o mesmo que o leitor que deseja remover a reserva
            reservas.erase(reservas.begin() + i); //remove o leitor da lista
            cout << "Reserva removida com sucesso para o leitor: " << LT->getNome() << " com ID " << LT->getID() << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada para o leitor: " << LT->getNome() << " com ID " << LT->getID() << endl; //se o leitor nao foi encontrado na lista de reservas
}

/**
 * @brief Obtém o próximo leitor na lista de reservas.
 * 
 * @return Ponteiro para o leitor que está na frente na lista de reservas.
 */
Leitor* Livro::Proximo_Leitor_Reserva() const{
    if (!reservas.empty()) { //se a lista de reservas nao esta vazia
        return reservas.front(); //retorna o primeiro leitor da lista
    }
    return nullptr; //se a lista de reservas esta vazia
}

/**
 * @brief Verifica se o livro tem reservas.
 * 
 * @return true se o livro tem reservas, false caso contrário.
 */
bool Livro::temReserva() const{
    return !reservas.empty(); //retorna true se a lista de reservas nao esta vazia
}


