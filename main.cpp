#include <iostream>

using namespace std;

#include "Biblioteca.h"

int main()
{
    //cout << "Hello world!" << endl;
    Biblioteca *BIB = new Biblioteca();


    BIB->LoadFile("dados.txt");




    delete BIB;
    return 0;
}
