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
};

template <class T>
Queue<T>::Queue()
{
}

#endif