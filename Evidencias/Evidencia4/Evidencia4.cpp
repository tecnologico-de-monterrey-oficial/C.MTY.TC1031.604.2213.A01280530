#include <iostream>
#include <fstream>


using namespace std;

#include "Graph.h"
#include "Vertex.h"

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
    worldMap.Dijkstra("Ambarli", "Callao");
    
    return 0;
}
