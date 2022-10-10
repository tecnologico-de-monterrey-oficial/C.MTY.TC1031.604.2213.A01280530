#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Log.h"
#include "DoublyLinkedList.h"

//Intercambiamos valores
template <class T>
void swap(DoublyLinkedList<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

//Revisamos que valores son mayores/menores
template<class T>
int getPivot(DoublyLinkedList<T> &list, int start, int end) {
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
void quickSort(DoublyLinkedList<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);
        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

template<class T>
void printFromTwo(DoublyLinkedList<T>listM , DoublyLinkedList<T>listR, int indexM, int indexR,string ubi){
    
    int month = 0;
    int year = 0;
    //Buscamos la primera fecha
    if (indexM==-1 && indexR == -1)
    {
        return;
    }
    if (indexM == -1)
    {
        month = stoi(listR[indexR].date.substr(3,2));
        year = stoi(listR[indexR].date.substr(6,2));
    }else if (indexR == -1)
    {
        month = stoi(listM[indexM].date.substr(3,2));
        year = stoi(listM[indexM].date.substr(6,2));
    }else{

        if (listM[indexM].newDate<listR[indexR].newDate)
        {
            month = stoi(listM[indexM].date.substr(3,2));
            year = stoi(listM[indexM].date.substr(6,2));
        }else{
            month = stoi(listR[indexR].date.substr(3,2));
            year = stoi(listR[indexR].date.substr(6,2));
        }  
    }
    vector<string> meses = {"jan","feb","mar","april","may","jun","jul","aug","sept","oct","nov","dec"};
    int emes = 0;
    int erres = 0;
    bool M = true;
    bool R = true;
    bool igualR = true;
    bool igualM = true;
    //Obtenemos uno por uno la cantidad del ubi que sea del mes
    while(M || R){
        if (indexM == listM.getSize()-1 || indexM==-1 ||listM[indexM].ubi.substr(0,3)!=ubi)
        {
           M = false;
        }
        if (indexR == listR.getSize()-1 || indexR == -1|| listR[indexR].ubi.substr(0,3)!=ubi)
        {
           R = false;
        }

        while (M && igualM)
        {
            if (stoi(listM[indexM].date.substr(3,2))== month && stoi(listM[indexM].date.substr(6,2))== year)
            {
                emes++;
                indexM++;
            }else{
                igualM = false;
            }
            
        }
        while (R && igualR)
        {
            if (stoi(listR[indexR].date.substr(3,2))== month && stoi(listR[indexR].date.substr(6,2))== year)
            {
                erres++;
                indexR++;
            }else{
                igualR = false;
            }
        }

        if ( M || R )
        {
            cout << meses[month-1] << " " << year << " M:"  << emes << " R:"  << erres << endl;
        }
        emes = 0;
        erres = 0;
        igualM = true;
        igualR = true;
        
        if (month == 12){
            year = (year+1)%100;
        }
        month = (month)%12+1;
    }

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

    DoublyLinkedList<Log> LogsM = DoublyLinkedList<Log>();
    DoublyLinkedList<Log> LogsR = DoublyLinkedList<Log>();

    while (file >> date >> time >> entry >> ubi) {
        Log log(date, time, entry, ubi);
        
        if(entry == "M"){
            LogsM.append(log);
        }else{
            LogsR.append(log);
        }
    }

    quickSort(LogsM, 0, LogsM.getSize()-1);
    quickSort(LogsR,0,LogsR.getSize()-1);
    
    done = false;
    int indexM;
    int indexR;
    //Pedir código de UBI, y revisar que sea o completo, o la serie
    while (!done)
    {
        cout<<"Introduzca los primeros 3 caracteres del UBI"<<endl;
        cout<<"Escriba 'EXIT' para salir"<<endl;
        string ubi;
        cin>>ubi;
        if(ubi=="EXIT" || ubi=="exit"){
            cout<<"Saliendo..."<<endl;
            return 0;
        }
        if(ubi.length() == 3){
          indexM=  LogsM.findData(ubi);
          indexR=  LogsR.findData(ubi);
          printFromTwo(LogsM, LogsR, indexM,indexR,ubi);
        }else{
            cout<<"UBI no válida en longitud, intente con otra UBI"<<endl;
        }
    }

    return 0;
}