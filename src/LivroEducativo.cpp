#include "LivroEducativo.h"

/**
 * @brief Construtor da classe LivroEducativo.
 * 
 * @param t O título do livro.
 * @param a O autor do livro.
 * @param i O ISBN do livro.
 * @param c A categoria do livro.
 * @param g O grau de escolaridade do livro.
 * @param numCopias O número de cópias do livro.
 */
LivroEducativo::LivroEducativo(string t, string a, string i, string c, string g, int numCopias) : Livro(t, a, i, c, numCopias), grau_escolaridade(g)
{
    //ctor
}

/**
 * @brief Destrutor da classe LivroEducativo.
 */
LivroEducativo::~LivroEducativo()
{
    //dtor
}

/**
 * @brief Obtém o tipo do livro.
 * 
 * @return O tipo do livro.
 */
string LivroEducativo::getTipo() const
{
    return "Educacional"; //retornar o tipo do livro
}

/**
 * @brief Obtém o prazo de empréstimo do livro.
 * 
 * @return O prazo de empréstimo do livro.
 */
int LivroEducativo::getPrazoEmprestimo() const
{
    return 10; //retornar o prazo de empréstimo (10 dias)
}

/**
 * @brief Obtém o grau de escolaridade do livro.
 * 
 * @return O grau de escolaridade do livro.
 */
string LivroEducativo::getGrauEscolaridade() const {
    return grau_escolaridade; //retornar o grau de escolaridade
}

/**
 * @brief Define o grau de escolaridade do livro.
 * 
 * @param g O grau de escolaridade do livro.
 */
void LivroEducativo::setGrauEscolaridade(string g) {
    grau_escolaridade = g; //atribuir o grau de escolaridade
}

/**
 * @brief Edita as informações do livro.
 */
void LivroEducativo::EditarInformacoesLivro(){
    int opcao;

    cout << "O que deseja editar?" << endl;
    cout << "1 - Grau de Escolaridade" << endl;
    cout << "2 - Categoria" << endl;
    cout << "3 - Autor" << endl;
    cout << "4 - Titulo" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    switch (opcao) //switch para escolher a opcao de edicao
    {
    case 1:{
        string novoGrau; //novo grau de escolaridade
        cout << "Grau de Escolaridade Atual: " << grau_escolaridade << endl; //grau de escolaridade atual
        cout << "Novo Grau de Escolaridade: ";
        cin.ignore(); //limpar o buffer do teclado
        getline(cin, novoGrau); //ler o novo grau de escolaridade
        setGrauEscolaridade(novoGrau); //atribuir o novo grau de escolaridade
        cout << "Informacoes atualizadas com sucesso!" << endl; //informar que as informacoes foram atualizadas com sucesso
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