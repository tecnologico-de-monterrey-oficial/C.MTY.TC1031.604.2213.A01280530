#ifndef Heap_h
#define Heap_h

template<class T>
class Heap {
private:
    vector<T> heap;
public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    void print();
    void swap(vector<T> &list, int a, int b);
};

template<class T>
Heap<T>::Heap() {

}

template<class T>
void Heap<T>::swap(vector<T> &list, int a, int b) {
    T aux = list[a];
    list[a] = list[b];
    list[b] = aux;
}


template<class T>
Heap<T>::Heap(vector<T> list) {
    
    int father = (list.size() - 2) / 2;
    int bigSon;
    while (father >= 0) {
        int auxFather = father;
        while ((auxFather * 2 + 1) < list.size()) {
            int son1 = auxFather * 2 + 1;
            if ((auxFather * 2 + 2) < list.size()) {
                int son2 = auxFather * 2 + 2;
                (list[son1] > list[son2]) ? bigSon = son1 : bigSon = son2;  
            } else {
               bigSon = son1;
            }
            if (list[auxFather] > list[bigSon]) {
                auxFather = list.size(); 
            } else { 
                swap(list, auxFather, bigSon);
                auxFather = bigSon;
            }
        }
        father--;
    }
    heap = list;
}

template<class T>
Heap<T>::Heap(initializer_list<T> listI) {
   vector<T> list = listI;
    int father = (list.size() - 2) / 2;
    int bigSon;
    while (father >= 0) {
        int auxFather = father;
        
        while ((auxFather * 2 + 1) < list.size()) {
            
            int son1 = auxFather * 2 + 1;
           
            if ((auxFather * 2 + 2) < list.size()) {
                
                int son2 = auxFather * 2 + 2;
                
                (list[son1] > list[son2]) ? bigSon = son1 : bigSon = son2;  
            } else {
                
                bigSon = son1;
            }
           
            if (list[auxFather] > list[bigSon]) {
                
                auxFather = list.size(); 
            
            } else { 
               swap(list, auxFather, bigSon);
                
                auxFather = bigSon;
            }
        }
        
        father--;
    }
    
    heap = list;
}

template<class T>
void Heap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}

#endif