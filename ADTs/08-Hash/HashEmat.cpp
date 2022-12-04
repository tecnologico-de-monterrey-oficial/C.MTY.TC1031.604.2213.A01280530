#include <iostream>
#include <fstream>
using namespace std;

#include "HashEMat.h"

int main()
{
    HashEMat mat;
    fstream file("matriculas.txt");
    string matricula;
    while(file>>matricula){
        mat.addMatricula(matricula);
    }
    mat.print();

    return 0;
}
