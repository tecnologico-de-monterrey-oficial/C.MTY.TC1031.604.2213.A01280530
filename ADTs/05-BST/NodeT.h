#pragma once

template<class T>
struct NodeT{
    T data;
    NodeT<T>* left;
    NodeT<T>* right;
    NodeT();
    NodeT(T data);
    NodeT(T data, NodeT<T>* left,NodeT<T>* right);
};

template<class T>
NodeT<T>::NodeT(){
    left = NULL;
    right = NULL;
}

template<class T>
NodeT<T>::NodeT(T data){
    this->data = data;
    left = NULL;
    right = NULL;
}

template<class T>
NodeT<T>::NodeT(T data,NodeT<T>* left, NodeT<T>* right){
    this->data = data;
    this->left = left;
    this->right = right;
}