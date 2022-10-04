#ifndef BinaryTree_h
#define BinaryTree_h
#include "NodeT.h"

template<class T>
class BinaryTree
{
private:
    NodeT<T>* root;
public:
    BinaryTree();
    void insert(T data);
    bool find(T data);
    void remove(T data);
    void print();
};
template<class T>
BinaryTree<T>::BinaryTree(/* args */)
{
}


#endif