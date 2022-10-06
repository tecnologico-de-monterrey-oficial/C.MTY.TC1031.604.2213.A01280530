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
    void appendLeft(T data);
    void print();
    void insert(T data, int index); 
    void deleteAt(int index);  
    void deleteData(T data);
    int findData(T data);
    T getData(int index);
    T& operator[](int index);

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
    int x = 0;
    //Imprimimos los primeros valores
        while(aux != NULL){
            cout<<"-.No: "<<x<<endl;
            cout<<"Dato: "<<aux->data<<endl;
            x++;
            aux = aux->next;
        }
        //Cuando se salga del while, Imprimimos el último valor.
}
template<class T>
void LinkedList<T>:: appendLeft(T data){
        head = new Node<T>(data,head);
        size++;
}

template<class T>
void LinkedList<T>:: insert(T data, int index){
        if(index>=0 && index <size){
            Node<T>* aux = head;
            int auxIndex = 0;
            while(auxIndex < index){
                auxIndex++;
                aux = aux->next;
            }
            aux->next = new Node<T>(data, aux->next);
            size++;
        }else{
            throw out_of_range("El índice no es válido");
        }
}

template<class T>
void LinkedList<T>:: deleteAt( int index){
        if(index>= 0 && index<size){
            if(size == 0){
            cout<<"No hay nada en la lista"<<endl;
            }else if(index == 0){
                Node<T>* destroy = head;
                head = head->next;
                delete destroy;
                size--;
            } else if(index >0){
                Node<T>* aux = head;
                int auxIndex = 0;
                while(auxIndex < index-1){
                    auxIndex++;
                    aux = aux->next;
                }
                Node<T>* destroy = aux->next;
                aux->next= destroy->next;
                delete destroy;
                size--;
            }
        }else{
            throw out_of_range("El índice no es válido");
        }   
}

template<class T>
void LinkedList<T>:: deleteData(T data){
    if(size == 0){
            cout<<"No hay nada en la lista"<<endl;
            return;
    }

    if(head->data == data){
        Node<T>* destroy = head;
        head = head->next;
        delete destroy;
        size--;
    }else{
        Node<T>* aux = head;
        int count = 1;
        while( count < size && aux->next->data != data ){
            count++;
            aux = aux->next;
        }
        if(count == size){
            cout<<"valor a borrar no existe, regresando"<<endl;
            return;
        }
        Node<T>* destroy = aux->next;
            aux->next= destroy->next;
            delete destroy;
            size--;
    }
}

template<class T>
int LinkedList<T>::findData(T data){
    if(size == 0){
            cout<<"No hay nada en la lista"<<endl;
            return 0;
    }
    int count = 0;
        if(head->data == data){
            return count;
        }else{
            Node<T>* aux = head;
            while(aux->data != data){
                if(aux->next == NULL){
                    cout<<"Valor no existente"<<endl;
                    return -1;
                }
                count++;
                aux = aux->next;
            }
            return count;
        }
}

template<class T>
T LinkedList<T>:: getData(int index){
    if(index >=0 && index < size){
            Node<T>* aux = head; 
            int count = 0;
            while (count < index)
            {
                aux = aux->next;
                count++;
            }
            return aux->data;
    }else{
        throw out_of_range("El índice no es válido");
    }

}

template <class T>
T& LinkedList<T>:: operator[](int index){
    if(index >=0 && index < size){
            Node<T>* aux = head; 
            int count = 0;
            while (count < index)
            {
                aux = aux->next;
                count++;
            }
            return aux->data;
    }else{
        throw out_of_range("El índice no es válido");
    }
}

#endif

