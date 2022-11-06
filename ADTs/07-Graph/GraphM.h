#ifndef GraphM_h
#define GraphM_h
#include<iterator>
#include "Vertex.h"


template<class T>
class GraphM{
    private:
        vector<vector<int>> graph;
        vector<T> vertices;
        int size;
    public:
        GraphM();
        GraphM(vector<T> vertices);
        GraphM(vector<T> vertices, vector<Vertex<T>> edges);
        void addEdge(Vertex<T> edge);
        int findVertex(T vertex);
        void addEdges(vector<Vertex<T>> edges);
        void print();
        void addVertex(T vertex);
};

template<class T>
GraphM<T>:: GraphM(){
    size = 0;
}


template<class T>
GraphM<T>:: GraphM(vector<T> vertices){
    this->vertices = vertices;
    size = vertices.size();
    vector<int> row(size,0);
    graph.resize(size, row);
}

template<class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
    // Actualizar la matriz de adyacencias de acuerdo a la lista de arcos
    /*graph.resize(vertices.size());
    for(auto el: graph){
        el.resize(vertices.size());
    }
    */
    vector<int> row(size,0);
    graph.resize(size, row);

    for(auto el: edges){
        // buscar la posición del vértice origen
        int source = findVertex(el.source);
        // buscar la posición del vértice destino
        if(source == -1){
            throw out_of_range("No existe el vértice en el grafo");
            return;
        }
        int target = findVertex(el.source);
        if (target == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
        }
        // y en esa posición asignar el valor del peso en la matriz de adyacencias
        //graph[target][source] = el.weight;
        graph[source][target] = el.weight;
        
    }
}

template<class T>
int GraphM<T>::findVertex(T vertex){
    typename vector<int>::iterator it= find(vertices.begin(),vertices.end(),vertex);
    if(it!=vertces.end()){
        return it-vertices.begin();
    }else{
        return -1;
    }
}

template<class T>
void GraphM<T>::addEdges(vector<Vertex<T>> edges) {
    for(auto el: edges){
        // buscar la posición del vértice origen
        int source = findVertex(el.source);
        // buscar la posición del vértice destino
        if(source == -1){
            throw out_of_range("No existe el vértice en el grafo");
            return;
        }
        int target = findVertex(el.source);
        // y en esa posición asignar el valor del peso en la matriz de adyacencias
        //graph[target][source] = el.weight;
        graph[source][target] = el.weight;
        
    }
}

template<class T>
void GraphM<T>::addEdge(Vertex<T> edge) {

    // Actualizar la matriz de adyacencias de acuerdo al arco 
    // buscar la posición del vértice origen
    int source = findVertex(vertex.source);
    // buscar la posición del vértice destino
    if(source == -1){
        throw out_of_range("No existe el vértice en el grafo");
        return;
    }
    int target = findVertex(vertex.source);
    // y en esa posición asignar el valor del peso en la matriz de adyacencias
    if (target == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
    }
    graph[source][target] = el.weight;
}

template<class T>
void GraphM<T>::print() {
    for (int i=0; i<vertices.size(); i++ ) {
        cout << vertices[i] << " ";
        for (int j=0; j<vertices.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

#endif