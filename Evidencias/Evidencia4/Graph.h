#ifndef Graph_h
#define Graph_h

#include "Vertex.h"
#include <limits>
#include <vector>
#include <queue>
#include <stack>
#include "HashEvidencia.h"

template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    HashEvidencia vertices;
    int size;
    int findVertex(T vertex);
    int getSmallIndex(vector<bool> status, vector<int> cost);
    int howMany;
public:
    Graph();
    Graph(vector<T> vertices);
    Graph(vector<T> vertices, vector< Vertex<T> > edges);
    void print();

    void Dijkstra(T vertex, T going);
};

// Constructor por default
template<class T>
Graph<T>::Graph() {
    size = 67;
}

// Constructor con lista de vertices
template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->size = 67;
    for(int i = 0; i< vertices.size(); i++){
        this->vertices.addPort(vertices[i]);
    }
}



template<class T>
Graph<T>::Graph(vector<T> vertices, vector< Vertex<T> > edges) {
    
    

    for (auto puerto: vertices){
        this->vertices.addPort(puerto);
    }
    this->size = 67;
    graph.resize(size);

     for (auto edge : edges) {
        // buscar el indice del arco origen en la lista de vértices
        int sourceIndex = findVertex(edge.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // agregamos el vertex en la poisición del sourceIndex en el grafo
        graph[sourceIndex].push_back(edge);
    }
    howMany = vertices.size();
}

template<class T>
int Graph <T>::findVertex(T vertex) {
     return vertices.findPort(vertex);  
}

template<class T>
void Graph<T>::print() {
    for (int i=0; i<size; i++) {
        cout << vertices[i] << " ";
        for (auto vertex : graph[i]) {
            cout << vertex.target << "," << vertex.weight << " ";
        }
        cout << endl;
    }
}


// Buscamos cual es el valor más pequeño del vector de cost que en la tabla de status tenga un valor de falso y obtnemos el índice correspondiente 
template<class T>
int Graph<T>::getSmallIndex(vector<bool> status, vector<int> cost) {
    // Creamos una variable con el valor menor que sea igual a infinito (minCost)
    int minCost = INT_MAX;
    // Creamos una variable para guardar cual fue el índice menor (minIndex) y la igualamos a -1
    int minIndex = -1;
    // Recorremos todos los valor del vector de status
    for (int i=0; i<size; i++) {
        // si el valor del indice actual del ciclo en el vector de status es igual a falso
        if (!status[i]) {
            // si es falso
            // validamos si el costo del indice atual es menor a minCost
            if (cost[i] < minCost) {
                // si es menor
                // cambiamos el valor de minCost por el costo del indice actual
                minCost = cost[i];
                // cambiamos el valor de minIndex por el índice actual
                minIndex = i;
            }
        }
    }
    // Regresar el valor de minIndex
    return minIndex;
}

template<class T>
void Graph<T>::Dijkstra(T vertex, T going) {
    
    if(vertex == going){
        cout << "con una distancia en millas de: ¡0! ¡Eligió el mismo inicio y destino!"<< endl;
        return;
    }

    // Obtener el índice del vértice que recibimos de parámetro
    int vertexIndex = findVertex(vertex);
    // Validar que si exista el vértice en la tabla de vértices
    if (vertexIndex >= 0) {
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false); // El vector de estatus
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX); // El vector de costos
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[vertexIndex] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size, -1); // El vector de path
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while (smallIndex >= 0) {
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if (!status[adjIndex]) {
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<int> > pathStack
        vector < stack<int> > pathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for (int index = 0; index < size; index++) {
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if (cost[index] < INT_MAX) {
                // Si es menor
                // Insertar el índice actual en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(i))
                pathStack[index].push(index);
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = index;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while (path[pathIndex] != -1) {
                    // insertar el valor que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(path[pathIndex]))
                    pathStack[index].push(path[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }

        if(cost[vertices.hashFunction(going)] == INT_MAX){
            cout<<"El destino es inalcanzable!"<<endl;
            return;
        }

        vector<string> NoWhere;
        for(int i=0; i< size; i++){
            if(vertices[i] != "" && cost[i] == INT_MAX){
                NoWhere.push_back(vertices[i]);
            }
        }

        

        vector < stack<int> > pathStack2 = pathStack;
        int distance = 0;
        while (!pathStack[vertices.hashFunction(going)].empty()) {
            cout << vertices[pathStack[vertices.hashFunction(going)].top()] << " -> ";
            distance = cost[pathStack[vertices.hashFunction(going)].top()];
            pathStack[vertices.hashFunction(going)].pop();
        }
        cout << "con una distancia en millas de:" << distance<< endl;

        int highest = 0;
        int test = 0;
        int indexer = 0;
        for(int i = 0; i<size; i++){
            if(vertices[i] != "" && cost[i] != INT_MAX){
                test = cost[i];
                if(test > highest){
                    highest = test;
                    indexer = i;
                }
            }
        }

        while (!pathStack2[indexer].empty()) {
            cout << vertices[pathStack2[indexer].top()] << " -> ";
            distance = cost[pathStack2[indexer].top()];
            pathStack2[indexer].pop();
        }
        cout << "con una distancia en millas de:" << distance<< endl;

        if (NoWhere.size() == 0){
            cout << "Todos los puertos son alcanzables desde: " << vertex << "!" << endl;
        } else {
            cout << "Los puertos inaccesibles son: ";
            for (auto puerto : NoWhere){
                cout << puerto << ", ";
            }
            cout << endl;
        }


    } else {
        // No existe
        // Imprimir un error
        cout << "El vértice inicial no existe" << endl;
    }
}
#endif