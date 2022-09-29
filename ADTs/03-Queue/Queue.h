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



template<class T>
bool Queue<T>:: isEmpty(){
    if(front == NULL){
        return true;
    }
    return false
}
#endif