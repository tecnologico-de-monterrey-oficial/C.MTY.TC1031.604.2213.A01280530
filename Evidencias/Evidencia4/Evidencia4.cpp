#include <iostream>
#include <fstream>


using namespace std;

#include "Graph.h"


int main()
{
    
    ifstream file;

    bool done = false;
    string name;
    //Pedimos el nombre del archivo y revisamos si existe
    /*while(!done){
        cout<<"Inserte el nombre del archivo con su terminación '.txt'"<<endl;
        cout<<"Escriba 'EXIT' para salir"<<endl;
        cin>>name;
        if(name == "EXIT"){
            cout<<"Saliendo..."<<endl;
            return 0;
        }
        ifstream file(name);
        if(file.good()){
            done = true;
        }else{
            cout<<"Nombre de archivo no válido, intentarlo de nuevo"<<endl;
        }
    }*/

    file.open("canalsuez3.txt");



    
    return 0;
}
