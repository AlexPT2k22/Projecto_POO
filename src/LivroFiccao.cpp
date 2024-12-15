#include "LivroFiccao.h"

/**
 * @brief Construtor da classe LivroFiccao.
 * 
 * @param t O título do livro.
 * @param a O autor do livro.
 * @param i O ISBN do livro.
 * @param c A categoria do livro.
 * @param numCopias O número de cópias do livro.
 */
LivroFiccao::LivroFiccao(string t, string a, string i, string c, int numCopias) : Livro(t, a, i, c, numCopias)
{
    //ctor
}

/**
 * @brief Destrutor da classe LivroFiccao.
 */
LivroFiccao::~LivroFiccao()
{
    //dtor
}

/**
 * @brief Obtém o tipo do livro.
 * 
 * @return O tipo do livro.
 */
string LivroFiccao::getTipo() const
{
    return "Ficcao"; //retornar o tipo do livro
}

/**
 * @brief Obtém o prazo de empréstimo do livro.
 * 
 * @return O prazo de empréstimo do livro.
 */
int LivroFiccao::getPrazoEmprestimo() const
{
    return 7; //retornar o prazo de empréstimo (7 dias)
}

/**
 * @brief Edita as informações do livro.
 */
void LivroFiccao::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Categoria" << endl;
    cout << "2 - Autor" << endl;
    cout << "3 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao) //switch para escolher a opcao de edicao
    {
    case 1:{
        string novaCategoria; //nova categoria
        cout << "Categoria Atual: " << getCategoria() << endl; //categoria atual
        cout << "Nova Categoria: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novaCategoria); //ler a nova categoria
        setCategoria(novaCategoria); //atribuir a nova categoria
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
        break;
    }
    case 2:{
        string novoAutor; //novo autor
        cout << "Autor Atual: " << getAutor() << endl; //autor atual
        cout << "Novo Autor: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novoAutor); //ler o novo autor
        setAutor(novoAutor); //atribuir o novo autor
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
        break;
    }
    case 3:{
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
