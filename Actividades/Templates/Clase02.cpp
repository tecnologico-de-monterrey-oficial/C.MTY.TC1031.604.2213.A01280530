#include <iostream>
#include <vector>

using namespace std;

#include "List.h"
int sumInt(int x, int y, int z){
return x+y+z;
}

double sumDouble(double x, double y, double z){
return x+y+z;
}

float sumFloat(float x, float y, float z){
return x+y+z;
}
string sumString(string x, string y, string z){
return x+y+z;
}
template <class T>
T sumAnything(T a, T b, T c){
    return a+b+c;
}

int main(){
    //Act 1.0
    //Realiza 3 funciones para sumar 3 números
    //Vas a recibir los 3 números de parámetros
    //1 funcón con enteros, 1 función con double, i función punto flotante
    //sumInt, sumDouble, sumFloat
    int a1=1;
    int b1=2;
    int c1=3;
    double a2= 2.2;
    double b2= 2.6;
    double c2= 2.7;
    float a3 = 1.4;
    float b3 = 2.6;
    float c3 = 3.3;
    string a4 = "Hola";
    string b4 = " crayola";
    string c4 = " mi cajita de colores";

    List<string> list;
    list.add("A");
    list.add("B");
    list.print();

    List<int> list2;
    list2.add(1);
    list2.add(2);
    list2.print();

    cout <<"La suma Int de a + b + c es igual a " << sumInt(a1,b1,c1) <<endl;
    cout <<"La suma Anything de a + b + c es igual a " << sumAnything(a1,b1,c1) <<endl;
    cout <<"La suma Double de a + b + c es igual a " << sumDouble(a2,b2,c2) <<endl;
    cout <<"La suma Anything de a + b + c es igual a " << sumAnything(a2,b2,c2) <<endl;
    cout <<"La suma Float de a + b + c es igual a " << sumFloat(a3,b3,c3) <<endl;
    cout <<"La suma Anything de a + b + c es igual a " << sumAnything(a3,b3,c3) <<endl;
    cout <<"La suma String de a + b + c es igual a " << sumString(a4,b4,c4) <<endl;
    cout <<"La suma Anything de a + b + c es igual a " << sumAnything(a4,b4,c4) <<endl;

    return 0;
}