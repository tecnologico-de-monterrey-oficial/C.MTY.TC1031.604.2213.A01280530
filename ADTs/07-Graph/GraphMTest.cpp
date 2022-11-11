#include <iostream>
#include <vector>
using namespace std;

#include "GraphM.h"

int main()
{
    vector<int> vertices = {0,1,2,3,4,5,6,7};
    vector< Vertex<int> > edges;
    edges.push_back(Vertex<int>(0,1,4));
    edges.push_back(Vertex<int>(0,4,2));
    edges.push_back(Vertex<int>(1,0,5));
    edges.push_back(Vertex<int>(1,3,1));
    edges.push_back(Vertex<int>(2,4,2));
    edges.push_back(Vertex<int>(2,5,2));
    edges.push_back(Vertex<int>(3,1,2));
    edges.push_back(Vertex<int>(5,1,6));
    edges.push_back(Vertex<int>(5,3,7));
    edges.push_back(Vertex<int>(6,2,7));
    edges.push_back(Vertex<int>(6,4,9));
    edges.push_back(Vertex<int>(6,5,2));
    GraphM<int> graph(vertices);
    graph.addEdges(edges);
    graph.print();


    return 0;
}