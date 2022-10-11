#ifndef BinaryTree_h
#define BinaryTree_h
#include "NodeT.h"

template<class T>
class BinaryTree
{
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);
    int howManyChilds(NodeT<T>* aux);
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
int BinaryTree<T>::howManyChilds(NodeT<T>* aux)
{
    int count = 0;
    if (aux->left != NULL)
    {
        count++;
    }
    if (aux->right!= NULL)
    {
        count++;
    }
    return count;
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
void BinaryTree<T>:: remove(T data){
    // Validar si el arbol no esta vacío
    // Encontrarlo
    // Validar cuantos hijos tiene el nodo a borar
        // No tiene hijos
            // El apuntador del papa del lado donde encontré el valor a eliminar va a apuntar a nulos
        // Tiene 1 hijo
            // El apuntador del papa del lado donde encontré el valor a eliminar va a apuntar al hijo
        // Tiene 2 hijos
            // Buscar el hijo más grande del lado izquierdo del nodo a eliminar
            // Movemos el valor del nodo más grande del lado izquierdo al valor del nodo a eliminar
            // Eliminamos el nodo más grande del lado izquierdo
                // Solo puede ser sin hijos o con 1 hijo (Mandar llamar a la función de borrar)
    if (isEmpty())
    {
        throw invalid_argument("El valor no se encuentra en el árbol");
    }else{
        //Encontramos el nodo del dato
        NodeT<T>* aux = root;
        if(data == root->data){
            switch (howManyChilds(root))
            {
            case 0:
                root = NULL;
                delete aux;
                break;
            
            case 1:
                root->right == nullptr ? root =root->left: root = root->right;
                delete aux;
                break;
            case 2:
                NodeT<T>* auxBigLeft = aux->left;
                        //validamos si el apuntador del lado derecho es nulo
                if (auxBigLeft->right!=NULL)
                {
                // auxBigLeft es el más grande del lado izquierdo
                    aux->data = auxBigLeft->data;
                    aux->left = auxBigLeft->left;
                    delete auxBigLeft;
                }else{
                //Crear un apuntador auxiliar que va a ser el papa de Big
                    NodeT<T>* auxPa = aux;
                    while(auxBigLeft->right != NULL){
                        auxPa = auxBigLeft;
                        auxBigLeft= auxBigLeft->right;
                    }
                    // Big es el más grande del lado izquierdo
                    aux->data = auxBigLeft->data;
                    auxPa->right= auxBigLeft->left;
                    delete auxBigLeft;
                }

                break;
            }
        }else{
            //El nodo a quitar no es root
            //Crear un nodo que apunte al padre
            NodeT<T>* father = root;
            //Apuntar aux al hijo al lado correspondiente de root.
            data < root->data ? aux = root->left : aux = root->right;
            //Recorrer el arbol hasta encontrar el valor a quitar
            while (aux != NULL)
            { 
                if (aux->data == data)
                {
                    switch (howManyChilds(aux))
                    {
                    case 0:// cero hijos
                        data< father->data ? father->left = NULL: father->right = NULL;
                        delete aux;

                        break;
                    case 1://1 hijo
                        if (data<father->data)
                        {
                            aux->left != NULL ? father->left= aux->left : father->left=aux->right;
                        }else{
                            aux->left != NULL ? father->right = aux->left : father->right = aux->right;
                        }
                        delete aux;
                        break;
                    case 2://tiene 2 hijos
                        NodeT<T>* auxBigLeft = aux->left;
                        //validamos si el apuntador del lado derecho es nulo
                        if (auxBigLeft->right!=NULL)
                        {
                        // auxBigLeft es el más grande del lado izquierdo
                            aux->data = auxBigLeft->data;
                            aux->left = auxBigLeft->left;
                            delete auxBigLeft;
                        }else{
                        //Crear un apuntador auxiliar que va a ser el papa de Big
                            NodeT<T>* auxPa = aux;
                            while(auxBigLeft->right != NULL){
                                auxPa = auxBigLeft;
                                auxBigLeft= auxBigLeft->right;
                            }
                            // Big es el más grande del lado izquierdo
                            aux->data = auxBigLeft->data;
                            auxPa->right= auxBigLeft->left;
                            delete auxBigLeft;
                        }      
                        break;
                    }
                    return;
                }else if (aux->data > data)
                {
                    father = aux;
                    aux = aux->left;
                }else if (aux->data < data)
                {
                    father = aux;
                    aux = aux->right;
                }

            }
            //No se encontró
            throw invalid_argument("El valor no se encuentra en el árbol");
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