#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template<class T>
class LinkedList
{
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void append(T data);
    void print();    
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template<class T>
void LinkedList<T>:: append(T data){
    if(head == NULL){
        head = new Node<T>(data);
        /*cout<< head->data<<endl;
        cout<<head->next<<endl;*/
        this->size++;
    }else{
        Node<T>* aux = head;
        /*cout<<aux->data<<endl;
        cout<<aux->next<<endl;*/
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
        this->size++;
    }
    
}
template<class T>
void LinkedList<T>:: print(){
    Node<T>* aux = head;
    int x = 1;
    //Imprimimos los primeros valores
    while(aux-> next != NULL){
        cout<<"-.No: "<<x<<endl;
        cout<<"Dato: "<<aux->data<<endl;
        x++;
        aux = aux->next;
    }
    //Cuando se salga del while, Imprimimos el último valor.
    cout<<"-.No: "<<x<<endl;
    cout<<"Dato: "<<aux->data<<endl;
}

#endif

