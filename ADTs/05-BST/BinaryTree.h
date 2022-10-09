#ifndef BinaryTree_h
#define BinaryTree_h
#include "NodeT.h"

template<class T>
class BinaryTree
{
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);
public:
    BinaryTree();
    void insert(T data);
    bool find(T data);
    void remove(T data);
    void print();
    bool isEmpty();
};
template<class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template<class T>
bool BinaryTree<T>::isEmpty()
{
  return root == NULL;
}

template<class T>
void BinaryTree<T>::insert(T data)
{
  // Validamos si el arbol está vacío
    if (isEmpty()) {
        // Si esta vació
        // Apuntamos root a un nuevo nodo con el valor de data
        root = new NodeT<T>(data);
    // else
    } else {
        // Si no está vacío
        // Creamos un nodo auxiliar igual a root
        NodeT<T>* aux = root;
        // Recorremos el arbol hasta encontrar donde colocar el nodo nuevo (while aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor el valor del nodo auxiliar
            if (data < aux->data) {
                // Si es menor
                // Revisamos si el apuntador left de aux es igual a nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado izquierdo de aux
                    aux->left = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado izquierdo de aux
                    aux = aux->left;
                }
            // else 
            } else {
                // No es menor
                // Revisamos si el apuntador right de aux es igual a nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado derecho de aux
                    aux->right = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template<class T>
bool BinaryTree<T>:: find(T data){
    NodeT<T>* aux = root;
    while (aux!= NULL)
    {
        if (aux->data == data)
        {
            return true;
        }else if (aux->data > data)
        {
            aux = aux->left;
        }else if (aux->data < data)
        {
            aux = aux->right;
        }
    }
    return false;
}

template<class T>
void BinaryTree<T>::printTree(NodeT<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BinaryTree<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BinaryTree is empty" << endl << endl;
    }
} 

#endif