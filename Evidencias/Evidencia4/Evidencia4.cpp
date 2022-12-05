#include <iostream>
#include <fstream>


using namespace std;

#include "Graph.h"
#include "Vertex.h"

string call (int chosen){

    switch (chosen)
    {
    case 1:
        return "Alexandria";
        break;
    case 2:
        return "Algeciras";
        break;
    case 3:
        return "Ambarli";
        break;
    case 4:
        return "Antwerp";
        break;
    case 5:
        return "Balboa";
        break;
    case 6:
        return "Bandar";
        break;
    case 7:
        return "Barcelona";
        break;
    case 8:
        return "Bremen";
        break;
    case 9:
        return "Busan";
        break;
    case 10:
        return "Cai_Me";
        break;
    case 11:
        return "Callao";
        break;
    case 12:
        return "Cartagena";
        break;
    case 13:
        return "Charleston";
        break;
    case 14:
        return "Chennai";
        break;
    case 15:
        return "Chittagong";
        break;
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

    done = false;

    file.open("red_puertos.txt");

    string portOrigin;
    string portGone;
    string port;
    string distance;
    int value;
    vector<Vertex<string>> routes;
    vector<string> ports;
    
    file >> value;

    for(int i = 0; i < value; i++){
        file>> portOrigin >> portGone >> distance;
        routes.push_back(Vertex<string>(portOrigin, portGone, stoi(distance)));
    }

    file >> value;

    for(int i=0; i< value; i++){
        file >> port;
        ports.push_back(port);
    }

    Graph<string> worldMap(ports,routes);
    //worldMap.Dijkstra("Ambarli", "Callao");


    string inicio;
    string destino;
    int choose;
    cout<<"Bienvenido al simulador Guugl BOATS! inserte"<<endl;
    while(!done){
        
        cout<<"Inserte el puerto de origen de su barco! puede seleccionar el origen"<<endl;
        cout<<"con los siguientes valores tecleados en el teclado."<<endl;
        cout<<"1.-Alexandria     2.-Algeciras   3.-Ambarli"<<endl;
        cout<<"4.-Antwerp        5.-Balboa      6.-Bandar"<<endl;
        cout<<"7.-Barcelona      8.-Bremen      9.-Busan"<<endl;
        cout<<"10.-Cai Me        11.-Callao     12.-Cartagena"<<endl;
        cout<<"13.-Charleston    14.-Chennai    15.- Chittagong"<<endl;
        cout<<"16.-Salir"<<endl;
        cin>>choose;
        while(!done){
            if(choose == 16){
                cout<<"Saliendo... Vuelva pronto!"<<endl;
                done = true;
            }else if(choose< 16 && choose >0 ){
                inicio =  call(choose);
            }else{
                cout<<"Valor no válido, intente de nuevo!"<<endl;
            }
        }

    }


    cout<<"Inserte el puerto de destino de su barco! puede seleccionar el origen de la lista anterior."<<endl;
        if(choose == 16){
            cout<<"Saliendo... Vuelva pronto!"<<endl;
            done = true;
        }else if(choose< 16 && choose >0 ){
            inicio =  call(choose);
        }else{
            cout<<"Valor no válido, intente de nuevo!"<<endl;
        }

    
    return 0;
}
