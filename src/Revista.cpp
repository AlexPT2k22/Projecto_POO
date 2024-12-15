#include "Revista.h"

/**
 * @brief Construtor da classe Revista.
 * 
 * @param t O título da revista.
 * @param a O autor da revista.
 * @param i O ISBN da revista.
 * @param c A categoria da revista.
 * @param e A edição da revista.
 * @param numCopias O número de cópias da revista.
 */
Revista::Revista(string t, string a, string i, string c, int e, int numCopias) : Livro(t, a, i, c, numCopias), edicao(e)
{
    //ctor
}

/**
 * @brief Destrutor da classe Revista.
 */
Revista::~Revista()
{
    //dtor
}

/**
 * @brief Obtém a edição da revista.
 * 
 * @return A edição da revista.
 */
int Revista::getEdicao() const
{
    return edicao; //retornar a edicao da revista
}

/**
 * @brief Obtém o prazo de empréstimo da revista.
 * 
 * @return O prazo de empréstimo da revista.
 */
int Revista::getPrazoEmprestimo() const
{
    return 5; //prazo de empréstimo da revista (5 dias)
}

/**
 * @brief Obtém o tipo da revista.
 * 
 * @return O tipo da revista.
 */
string Revista::getTipo() const {
    return "Revista"; //retornar o tipo da revista
}

/**
 * @brief Define a edição da revista.
 * 
 * @param e A edição da revista.
 */
void Revista::setEdicao(int e) {
    if (e > 0) { //verificar se a edicao é valida
        edicao = e; //atribuir a edicao
        cout << "Edicao atualizada com sucesso!" << endl; //informar que a edicao foi atualizada com sucesso
    } else {
        cout << "Edicao invalida!" << endl; //edicao invalida
    }
}

/**
 * @brief Edita as informações da revista.
 */
void Revista::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Edicao" << endl;
    cout << "2 - Categoria" << endl;
    cout << "3 - Autor" << endl;
    cout << "4 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao) //switch para escolher o que deseja editar
    {
    case 1:{
        int novaEdicao; //nova edicao
        cout << "Edicao Atual: " << edicao << endl; //edicao atual
        cout << "Nova Edicao: ";
        cin.ignore(); //limpar o buffer do teclado
        cin >> novaEdicao; //ler a nova edicao
        setEdicao(novaEdicao); //atribuir a nova edicao
        break;
    }
    case 2:{
        string novaCategoria; //nova categoria
        cout << "Categoria Atual: " << getCategoria() << endl; //categoria atual
        cout << "Nova Categoria: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novaCategoria); //ler a nova categoria
        setCategoria(novaCategoria); //atribuir a nova categoria
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
        break;
    }
    case 3:{
        string novoAutor; //novo autor
        cout << "Autor Atual: " << getAutor() << endl; //autor atual
        cout << "Novo Autor: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novoAutor); //ler o novo autor
        setAutor(novoAutor); //atribuir o novo autor
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
        break;
    }
    case 4:{
        string novoTitulo; //novo titulo
        cout << "Titulo Atual: " << getTitulo() << endl; //titulo atual
        cout << "Novo Titulo: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novoTitulo); //ler o novo titulo
        setTitulo(novoTitulo); //atribuir o novo titulo
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
        break;
    }
    default:
        cout << "Opcao invalida!" << endl; //opcao invalida
        break;
    }
}