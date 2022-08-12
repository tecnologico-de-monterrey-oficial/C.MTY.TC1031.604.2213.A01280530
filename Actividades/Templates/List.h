#ifndef List_h
#define List_h

template <class T>
class List
{
private:
    vector<T> list;
    int size;
public:
    List(/* args */);
    List(vector<T> list);
    void add(T a);
    void print();
};
template <class T>
List<T>::List()
{
    size = 0;
    cout<< "Constructor por default"<<endl;
}
template <class T>
List<T>::List(vector<T> list)
{
    this->list = list;
    size = list.size();
    cout<< "Constructor con parámetros"<<endl;
}
template <class T>
void List<T>:: add(T a){
    list.push_back(a);
    size++;
}
template <class T>
void List<T>:: print(){
    for(auto el:list){
        cout <<el<<endl;
    }
}

#endif