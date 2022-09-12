#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Log.h"




//Intercambiamos valores
template <class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}
//Imprimimos la lista
void printLogs(vector<Log> logs) {
    for (auto log : logs) {
        cout << log << endl;
    }
}
//Revisamos que valores son mayores/menores
template<class T>
int getPivot(vector<T> &list, int start, int end) {
    T pivot = list[end];
    int auxIndex = start - 1;
    for (int index=start; index<=end-1; index++) {
        if (list[index]<pivot) {
            auxIndex++;  
            swap(list, auxIndex, index);
        }
    }
    auxIndex++;
    swap(list, auxIndex, end);
    return auxIndex;
}
//Recursividad de quicksort, para obtener pivotes y ordenar.
template <class T>
void quickSort(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);
        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}
//Tratamos de encontrar si hay más valores en la lista
template <class T>
void checkIfMore(vector<T> list,int index, string value){
    
    if(index != 0){
        //recorremos para arriba para revisar si hay más valores con el mismo ubi
        while(list[index] == value){
            index--;
        }
        //ya que encontramos el de arriba, le sumamos 1 para hacerlo tener el inicio;
        index++;
    }
    for(index; list[index]== value;index++){
        cout<<list[index]<<endl;
    }

}
//BinarySearch
template<class T>
bool binarySearch(vector<T>list, string value){
    int inf = 0;    
    int sup = list.size()-1;
    int medio=0;
    while(inf <= sup){
        medio = (inf+sup)/2;
        //Revisamos si el valor de en medio de la lista es el buscado
        if(list[medio]== value){
            cout<<"Se encontraron los siguientes UBIs:"<<endl;   
            //Buscamos si hay más valores que encontramos
            checkIfMore(list, medio, value);
            return true;
        }
        if(list[medio]>value){
            //Tomamos mitad inferior
            sup = medio;
            sup -=1;
        } else
        {
            //Tomamos mitad superior
            inf = medio;
            inf+=1;
        }
    }
    //Si de plano no existe el UBI, regresamos
    cout<<"No existe el ubi que usted introdujo"<<endl;
    return false;
}



int main()
{
    ifstream file;

    bool done = false;
    string name;
    //Pedimos el nombre del archivo y revisamos si existe
    while(!done){
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
    }
    // Abrimos el archivo de texto
    file.open(name);

    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logs;
    
    while (file >> date >> time >> entry >> ubi) {
        Log log(date, time, entry, ubi);
        logs.push_back(log);
    }

    quickSort(logs, 0, logs.size()-1);
    done = false;

    //Pedir código de UBI, y revisar que sea o completo, o la serie
    while (!done)
    {
        cout<<"Introduzca los primeros 3 caracteres del UBI o introduzca una UBI completa de 5 caracteres "<<endl;
        cout<<"Escriba 'EXIT' para salir"<<endl;
        string ubi;
        cin>>ubi;
        if(ubi=="EXIT"){
            cout<<"Saliendo..."<<endl;
            return 0;
        }
        if(ubi.length() == 3 || ubi.length()==5){
            binarySearch(logs,ubi);
        }else{
            cout<<"UBI no válida en longitud, intente con otra UBI"<<endl;
        }
    }
    return 0;
}