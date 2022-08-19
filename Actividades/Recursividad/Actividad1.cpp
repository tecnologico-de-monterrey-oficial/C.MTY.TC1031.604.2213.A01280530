#include <iostream>

using namespace std;

int fibonaccIterativo(int k){ 
    if (k == 2){
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
    double final = cantidad;
    for(int i = 1; i <= n; i++){
        final = final*1.1875;
    }
    return final;
}

double inversionRecursiva(int n, double cantidad){
    double tasa = 1.1875;
    if (n==0){
        return cantidad;
    }

    return tasa*inversionRecursiva(n-1, cantidad);
}

int potenciaIterativa(int x, int y){
int z = x;
for(int i=1; i <y; i++){
 x=x*z;
}
return x;
}

int potenciaRecursiva(int x, int y){
if (y == 1){
return x;
}
return x*(potenciaRecursiva(x,y-1));
}


int main(){

bool done = false;
int elegir = 10;
while(elegir != 0){
while (done == false)
{
    
    cout<<"Cual aplicacion quiere utilizar?"<<endl;
    cout<<"0.- Terminar"<<endl;
    cout<<"1.- Fibonacci"<<endl;
    cout<<"2.- Bacterias"<<endl;
    cout<<"3.- Inversion"<<endl;
    cout<<"4.- Exponencial"<<endl;
    cin>>elegir;
    if(elegir >= 0 && elegir <=4){
        done = true;
    }else{
        cout <<"Dato no válido"<<endl;
    }
}


if(elegir == 1){
    cout<<"Fibonacci"<<endl;
    //Ejercicio 1 Fibonacci
    //Realiza una aplicación que calcule el número fibonacci de una variable n 
    //que será leída de teclado, en donde n será un entero que el usuario dará; 
    //el fibonacci se calcula sumando los dos números fibonacci anteriores, 
    //por lo tanto, los primeros dos no son calculados.
    done = false;
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
}

if (elegir == 2)
{
    cout<<"Bacterias"<<endl;
    /*
    Cierta bacteria de laboratorio tiene un índice de crecimiento diario del 378% y un índice 
    de fallecimiento diario del 234%; realiza una aplicación que calcule el número de bacteria 
    finales en n días, en donde n será un entero que el usuario dará (asume que en el día 0 
    solo se tiene una bacteria).
    */

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
}

if (elegir == 3)
{
    cout<<"Inversion"<<endl;
    /*
    Cierto banco está ofreciendo un interés mensual del 18.75%; 
    realiza una aplicación que calcule monto final en n meses dada una cantidad inicial que es leída de teclado.
    */

    int monto;
    done = false;
    while (done==false)
    {
        int k;
        cout<<"Inserte el monto incial"<<endl;
        cin>>monto;
        if(monto > 0){
            cout<<"Por cuantos meses?"<<endl;
            cin>>k;
            if(k>0){
                cout <<"Dinero despues de " <<k <<" meses (Iterativo) "<<inversionIterativa(k,monto)<<endl;
                cout << "Dinero despues de " <<k <<" meses (Recursivo) "<<inversionRecursiva(k,monto)<<endl;
                done = true;
            } else{
                cout <<"Cantidad no válida, intente de nuevo"<<endl;
            }
        }else{
            cout<<"Monto no valido, intente de nuevo"<<endl;
        }
    }
}


if (elegir == 4)
{
    cout<<"Potencias"<<endl;
    /*
    Realiza una aplicación que evalúe x^y; tanto x como y son enteros positivos leídos de teclado.
    */


    done = false;
    while (done==false)
    {
        int x;
        int y;
        cout<<"Numero base (int)"<<endl;
        cin>>x;
        if(x > 0){
            cout<<"Numero a elevar?"<<endl;
            cin>>y;
            if(y>0){
                cout<<"hola"<<endl;
                cout << x << " elevado a " << y << "es igual a (Iterativo) "<<potenciaIterativa(x,y)<<endl;
                cout << x << " elevado a " << y << "es igual a (Recursivo) "<<potenciaRecursiva(x,y)<<endl;
                done = true;
            } else{
                cout <<"Cantidad no válida, intente de nuevo"<<endl;
            }
        }else{
            cout<<"Monto no valido, intente de nuevo"<<endl;
        }
     }
    }
    if(elegir !=0){
    done = false;
    }
}
    return 0;
}
