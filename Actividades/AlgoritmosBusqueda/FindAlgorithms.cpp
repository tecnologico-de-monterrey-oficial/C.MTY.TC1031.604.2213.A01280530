#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <chrono>

using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}


template<class T>
bool sequencialSearch(vector<T> list, T value){
//Algoritmo de búsqueda inicial
for (int i = 0; i < list.size(); i++)
{
    if(list[i]==value){
        cout<<"Si existe"<<endl;
        return true;
    }
}
cout<<"No existe"<<endl;
return false;

}

template<class T>
bool binarySearch(vector<T>list, int value){
    //Definir el límite inferior
    //Definir el límite superior
    //Iterar en la lista mientra el límite inferior <= límite superior
        //Calculo la posición de en medio (limite inferior+limite superior)/2
        //Checar si valor buscado es igual al elemento de enmedio
        //si es igual
            //regreso true
        //si no es igual
            //reviso si el valor es menor al valor de en medio
                //Si es menor
                    //actualizo el límite superior con el indice de en medio -1
                //Si es mayor
                    //actualizo el limite inferior con el valor de en medio + 1
    //Cuando salga del ciclo
    //Regreso false
    int inf = 0;    
    int sup = list.size()-1;
    int medio=0;
    while(inf <= sup){
        medio = (inf+sup)/2;
        if(list[medio]== value){
            cout<<"Si existe"<<endl;
            return true;
        }
        if(list[medio]>value){
            sup = medio;
            sup -=1;
        } else if (list[medio] < value)
        {
            inf = medio;
            inf+=1;
        }
    }
    cout<<"No existe"<<endl;
    return false;
}

int main()
{
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    vector<int> list = {5,7,10,20,35,42,63,70,93,100,120,130,155,169,175,186,190,201,205,209,230,270};

    /*Solicita al usuario un número entero entre
    1 y 100 Despliega un mensaje que indique si
    el número tecleado por el usuario existe en
    la lista.*/
    int n = 0;
    while (n<1||n>300)
    {
       cout<<"Inserte un numero a buscar si existe en el arreglo"<<endl;
        cin>>n;
        if(n<1||n>300){
            cout<<"Error, numero no valido"<<endl;
        }
    }
    startTime(begin);
    cout<<"Secuencial search"<<endl;
    bool check = sequencialSearch(list, n);
    getTime(begin, end);

    startTime(begin);
    cout<<"Binary search"<<endl;
    bool check2 = binarySearch(list, n);
    getTime(begin,end);
    /*if(check){
        cout <<"Si existe"<<endl;
    }else{
        cout<<"No existe"<<endl;
    }
    */

    return 0;
}
