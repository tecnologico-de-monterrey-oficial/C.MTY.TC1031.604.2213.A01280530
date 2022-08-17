#include <iostream>

using namespace std;
int fibonaccIterativo(int k){ 
    if (k == 2){
    cout<<"F(1)= 1"<<endl;
    cout<<"F(2)= 1"<<endl;
    }
    if (k == 1){
    cout<<"F(1)= 1"<<endl;
    }
    int x = 1;
    int y = 1;
    int z = 0;
for (int i = 2; i < k; i++){
    z = x+y;
    x = y;
    y = z;
}
return z;
}
/*
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
if (end == 1){
    cout<<"F(1)= 1"<<endl;
}

if(n > 2){
    z = x+y;
    cout<<"F(" <<b+1<<")= "<<z<<endl;
    fibbonacciRecursivo(n-1, z,x,b+1);
    
} else{
    return;
}

}
*/

int fibbonacciRecursivo( int end){
int x;
if (end == 1|| end == 2){
    return 1;
}
x = fibbonacciRecursivo(end-1)+fibbonacciRecursivo(end-2);
return x;

}

int bacteriaIterativa(int n){
    double aumento = 3.78;
    double disminuye = 2.34;
    double cantidad = 1;
    for(int i = 1; i <= n; i++){
        cantidad =(cantidad*aumento) - (cantidad*disminuye);  
    }
    return cantidad;
}

double bacteriaRecursiva(int n){
    double aumento = 3.78;
    double disminuye = 2.34;
    if(n == 0){
        return 1;
    }
    
    return bacteriaRecursiva(n-1)*(aumento-disminuye);
}

double inversionIterativa(int n, double cantidad){
    double tasa = 1.875;
    double final = cantidad;
    for(int i = 1; i <= n; i++){
        final = final*1.875;
    }
    return final;
}

double inversionRecursiva(int n, double cantidad){
    double tasa = 1.875;
    if (n==0){
        return 100;
    }

    return tasa*inversionRecursiva(n-1, cantidad);
}

void potenciaIterativa(int x, int y){
int z = x;
for(int i=1; i <y; i++){
 x=x*z;
}
cout <<x <<endl;
}

int potenciaRecursiva(int x, int y){
if (y == 1){
return x;
}
return x*(potenciaRecursiva(x,y-1));
}


int main(){
cout<<"Fibonacci"<<endl;
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
    cout << "Iterativo: F("<<k<<")= " << fibonaccIterativo(k)<<endl;
    cout << "Recursivo: F("<<k<<")= " << fibbonacciRecursivo(k)<<endl;
    //fibbonacciRecursivo(k,1,1,2);
    
    done = true;
}else{
 cout<< "Valor incorrecto, intente de nuevo" <<endl;
}
}

/*
Cierta bacteria de laboratorio tiene un índice de crecimiento diario del 378% y un índice 
de fallecimiento diario del 234%; realiza una aplicación que calcule el número de bacteria 
finales en n días, en donde n será un entero que el usuario dará (asume que en el día 0 
solo se tiene una bacteria).
*/
cout<<"Bacterias"<<endl;
//cout << bacteriaIterativa(10)<<endl;
//cout << int(bacteriaRecursiva(10))<<endl;

done = false;
while (done == false){
int k;
cout<<"Introduzca la cantidad de tiempo para ver crecer las bacterias"<<endl;
cin>> k;
if (k >=1){
    cout << "Iterativo: " << bacteriaIterativa(k)<<endl;
    
    cout << "Recursivo: " << int(bacteriaRecursiva(k))<<endl;
    //fibbonacciRecursivo(k,1,1,2);
    ;
    done = true;
}else{
 cout<< "Valor incorrecto, intente de nuevo" <<endl;
}
}

/*
Cierto banco está ofreciendo un interés mensual del 18.75%; 
realiza una aplicación que calcule monto final en n meses dada una cantidad inicial que es leída de teclado.
*/
cout<<"Inversión"<<endl;
cout << inversionIterativa(2,100)<<endl;
cout << inversionRecursiva(2,100)<<endl;


/*
Realiza una aplicación que evalúe xy; tanto x como y son enteros positivos leídos de teclado.
*/
cout<<"Potencias"<<endl;
potenciaIterativa(2,5);
cout<<potenciaRecursiva(2,5)<<endl;

    return 0;
}