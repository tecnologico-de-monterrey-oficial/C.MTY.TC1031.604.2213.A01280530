#ifndef Stack_h
#define Stack_h
#include "Node.h"

template<class T>
class Stack
{
private:
    Node<T>* top;
    int size;
public:
    Stack();
    T getTop();
    T pop();
    void push(T data);
    void print();
    bool isEmpty();
};

template<class T>
Stack<T>::Stack()
{
    top = NULL;
    size = 0;
}

template<class T>
void Stack<T>::push(T data)
{
    if (isEmpty())
    {
        top = new Node<T>(data);
        size++;
    }else{
        top = new Node<T>(data, top);
        size++;
    }
    
}

template<class T>
T Stack<T>::pop(){
    //Remove the first element and return data
    if (isEmpty()==false)
    {
        Node<T>* destroy = top;
        top = top->next;
        T data = destroy->data;
        delete destroy;
        return data;
    }else{
        throw out_of_range("Lista vacía");
    }
    
}

template<class T>
T Stack<T>::getTop(){
    if (isEmpty() == false)
    {
        return top->data;
    }else{
        throw out_of_range("Lista vacía");
    }
}


template<class T>
void Stack<T>::print()
{
   if(isEmpty()){
    cout<<"La lista está vacía"<<endl;
   }else{
        Node<T>* aux = top;
        while(aux!= NULL){
            cout<< aux->data <<" ";
            aux = aux->next;
        }
        cout<<" "<<endl;
   }
}
template<class T>
bool Stack<T>::isEmpty()
{
    if(size == 0){
        return true;
    }
    return false;
}

#endif