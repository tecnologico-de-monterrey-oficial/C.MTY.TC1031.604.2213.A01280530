#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BinaryTree.h"

void printLogs(vector<Log> logs) {
    for (auto log : logs) {
        cout << log << endl;
    }
}

template<class T>
void HeapSortD(vector<T>& list) {
    // Creamos un heap en base a la lista
    Heap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

template<class T>
void HeapSortA(vector<T>& list) {
    // Creamos un heap en base a la lista
    MinHeap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}



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

    // Abrimos el archivo de texto
    file.open("canalsuez3.txt");
    
    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logM;
    vector<Log> logR;
    
    vector<Log> aux;

    BinaryTree<Log> tree;

    while (file >> date >> time >> entry >> ubi) {
        Log log(date, time, entry, ubi);
        
        if(entry == "M"){
            logM.push_back(log);
        }else{
            logR.push_back(log);
        }
        tree.insert(log);
    }

    done = false;
    string ID =" ";
    int choose;
    while(!done){
        cout<<"Seleccione lo que usted quisiera hacer"<<endl;
        cout<<"1.-Ordenar Mar Mediterráneo"<<endl;
        cout<<"2.-Ordenar Mar Rojo"<<endl;
        cout<<"3.-Buscar UBI"<<endl;
        cout<<"4.-Salir"<<endl;
        cin>>choose;
        switch (choose)
        {
        case 1:
                aux = logM;
                while(!done){
                    
                    cout<<"Seleccione lo que quiera hacer para el mar mediterráneo"<<endl;
                    cout<<"1.-De menor a mayor (Ascendente)"<<endl;
                    cout<<"2.-De mayor a menor (Descenciente)"<<endl;
                    cin>>choose;
                    switch (choose)
                    {
                    case 1:
                        done = true;
                        HeapSortA(aux);
                        printLogs(aux);
                        break;
                    case 2:
                        done = true;
                        HeapSortD(aux);
                        printLogs(aux);
                        break;
                    default:
                        cout<<"valor no válido, intente de nuevo"<<endl;
                        break;
                    }
                }
                done = false;
            break;
        case 2:
            aux = logR;
            while(!done){
                    
                cout<<"Seleccione lo que quiera hacer para el mar Rojo"<<endl;
                cout<<"1.-De menor a mayor (Ascendente)"<<endl;
                cout<<"2.-De mayor a menor (Descenciente)"<<endl;
                cin>>choose;
                switch (choose)
                {
                    case 1:
                        done = true;
                        HeapSortA(aux);
                        printLogs(aux);
                        break;
                    case 2:
                        done = true;
                        HeapSortD(aux);
                        printLogs(aux);
                        break;
                    default:
                        cout<<"valor no válido, intente de nuevo"<<endl;
                        break;
                }
            }
            done = false;
            break;
        case 3:
            
            cout<<"Inserte el código completo de la UBI que quiere buscar"<<endl;
            cin>>ID;
            tree.find(Log("00-00-00","00:00","X",ID));
            cout<<""<<endl;

            break;

        case 4:
            cout<<"saliendo..."<<endl;
            done =true;
            break;
        default:
            cout<<"Valor no válido, inténtelo de nuevo"<<endl;
            break;
        }

    }

    return 0;
}
