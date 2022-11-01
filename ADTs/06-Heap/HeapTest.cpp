#include <iostream>
#include <vector>
using namespace std;

#include "Heap.h"


template<class T>
void HeapSort(vector<T>& list){
    Heap<T> heap(list);
    list.clear();
    
}

int main()
{
     vector<int> list = {8,5,17,19,21,28};
    //Heap<int> heap = {8,5,17,19,21,28};
    //Heap<int> heap(list);
    //heap.print();
    HeapSort(list);
    for (auto el : list)
    {
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}