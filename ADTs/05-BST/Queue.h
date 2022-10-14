#ifndef Queue_h
#define Queue_h

#include "Node.h"
template <class T>
class Queue
{
private:
    Node<T>* front;
    int size;
public:
    Queue();
    void push(T data);
    T pop();
    T getFront();
    void print();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue()
{
    front = NULL;
    size = 0;
}
template <class T>
void Queue<T>::push(T data)
{
        if (isEmpty())
        {
            //if it's empty, we add the front
            front = new Node<T>(data);
            size++;
        }else{
            Node<T>* aux = front;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next= new Node<T>(data);
            size++;
        }
    
}

template<class T>
T Queue<T>::pop(){
    //Remove the first element and return data
    if (isEmpty()==false)
    {
        Node<T>* destroy = front;
        front = front->next;
        T data = destroy->data;
        delete destroy;
        return data;
    }else{
        throw out_of_range("Lista vacía");
    }
    
}

template<class T>
T Queue<T>::getFront(){
    if (isEmpty() == false)
    {
        return front->data;
    }else{
        throw out_of_range("Lista vacía");
    }
}

template<class T>
void Queue<T>::print(){
    if (isEmpty() == false)
    {
        Node<T>* aux = front;
        while (aux != NULL)
        {
            cout<< aux->data <<" ";
            aux = aux->next;
        }
        cout<<" "<<endl;
    }else{
        cout<<"La lista está vacía"<<endl;
    }
}

template<class T>
bool Queue<T>:: isEmpty(){
    if(front == NULL){
        return true;
    }
    return false;
}
#endif