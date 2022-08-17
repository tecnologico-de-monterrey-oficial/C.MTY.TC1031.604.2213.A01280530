#include <iostream>

using namespace std;
void fibonaccIterativo(int k){ 
    cout << "F(1)= 1"<<endl; 
    cout << "F(2)= 1"<<endl;
    int x = 1;
    int y = 1;
    int z = 0;
for (int i = 2; i < k; i++){
    z = x+y;
    x = y;
    y = z;
    
    cout << "F("<<i+1<<")= "<<z<<endl;
}

}

void fibbonacciRecursivo( int end, int first, int second, int start){
int b = start;
int n = end;
int x = first;
int y = second;
int z;
if (start == 2){
    cout<<"F(1)= 1"<<endl;
    cout<<"F(2)= 1"<<endl;
}

if(n > 2){
    z = x+y;
    cout<<"F(" <<b+1<<")= "<<z<<endl;
    fibbonacciRecursivo(n-1, z,x,b+1);
    
} else{
    return;
}

}

/*
int fibbonacciRecursivo( int end){
int x;
if (end == 1 || end == 2){
cout<< "F(1)=1"<<endl;
    return 1;
}
x = fibbonacciRecursivo(end-1)+fibbonacciRecursivo(end-2);
cout << "F("<< end<<")="<<x<<endl;
return x;

}
*/

int main(){

//Ejercicio 1 Fibonacci
//Realiza una aplicación que calcule el número fibonacci de una variable n 
//que será leída de teclado, en donde n será un entero que el usuario dará; 
//el fibonacci se calcula sumando los dos números fibonacci anteriores, 
//por lo tanto, los primeros dos no son calculados.
bool done = false;
while (done == false){
int k;
cout<<"Introduzca la cantidad de iteraciones de Fibonacci"<<endl;
cin>> k;
if (k >=1){
    cout << "Iterativo: " << endl;
    fibonaccIterativo(k);
    cout << "Recursivo: " << endl;
    fibbonacciRecursivo(k,1,1,2);
    done = true;
}else{
 cout<< "Valor incorrecto, intente de nuevo" <<endl;
}
}

    return 0;
}