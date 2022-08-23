#include <iostream>
#include <vector>
using namespace std;
template<class T>
bool sequencialSearch(vector<T> list, T value){
//Algoritmo de búsqueda inicial
for (int i = 0; i < list.size(); i++)
{
    if(list[i]==n){
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
}

int main()
{
    vector<int> list = {5,7,10,20,35,42,63,70,93,100};

    /*Solicita al usuario un número entero entre
    1 y 100 Despliega un mensaje que indique si
    el número tecleado por el usuario existe en
    la lista.*/
    int n = 0;
    while (n<1||n>100)
    {
       cout<<"Inserte un numero a buscar si existe en el arreglo"<<endl;
        cin>>n;
        if(n<1||n>100){
            cout<<"Error, numero no valido"<<endl;
        }
    }
    
    bool check = sequencialSearch(list, n);
    /*if(check){
        cout <<"Si existe"<<endl;
    }else{
        cout<<"No existe"<<endl;
    }
    */


    return 0;
}
