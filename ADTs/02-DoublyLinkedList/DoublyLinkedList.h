#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "NodeD.h"

template <class T>
class DoublyLinkedList
{
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    DoublyLinkedList();
    void append(T data);
    void appendLeft(T data);
    void deleteAt(int index);


    void print();
    void printReverse();
    bool isEmpty();
};
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

template <class T>
void DoublyLinkedList<T>::print()
{
   NodeD<T>* aux = head;

   while(aux!= NULL){
    cout<<aux->data<< " ";
    aux = aux->next;
   }
   cout<<endl;
}

template <class T>
void DoublyLinkedList<T>::printReverse()
{
   NodeD<T>* aux = tail;

   while(aux!= NULL){
    cout<<aux->data<< " ";
    aux = aux->prev;
   }
   cout<<endl;
}

template <class T>
void DoublyLinkedList<T>::appendLeft(T data)
{
    head = new NodeD<T>(data,head,NULL);

    if(tail == NULL){
        tail = head;
    }else{
        head->next->prev= head;
    }

   size++;
}

template <class T>
void DoublyLinkedList<T>::append(T data)
{
    tail = new NodeD<T>(data,NULL,tail);

    if(head == NULL){
        head = tail;
    }else{
        tail->prev->next= tail;
    }
   size++;
}

template <class T>
void DoublyLinkedList<T>::deleteAt(int index)
{
   if(index>=0 && index < size){
    if(size ==1){
        NodeD<T>* aux = head;
        head = NULL;
        tail = NULL;
        delete aux;
    }else if(index==0){
        NodeD<T>* aux = head;

        head = head->next
        head-> prev = NULL;
        delete aux;
    } else if(index == size-1){
        NodeD<T>* aux = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete aux;
    } else {
        NodeD<T>* aux;
        if(index < size/2){
            aux = head->next;
            int auxIndex = 1;
            while(auxIndex < index){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux= tail->prev;
            int auxIndex = size-2;
            while (auxIndex>index)
            {
                aux = aux->prev;
                auxIndex--;
            }
        }
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        delete aux;
    }

    size--;
   }else{
        throw out_of_range("El índice es inválido");
   }
}


template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size==0;
}
/*
template <class T>
 DoublyLinkedList<T>::()
{
   
}
*/
#endif