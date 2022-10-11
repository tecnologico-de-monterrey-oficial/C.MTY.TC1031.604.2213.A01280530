#include <iostream>
using namespace std;

#include "BinaryTree.h"

int main()
{
    BinaryTree<int> bst;    

    bst.insert(40);
    bst.insert(20);
    bst.insert(60); 
    bst.insert(10);
    bst.insert(30);
    bst.insert(15);   
    bst.insert(25);
    bst.insert(35);
    bst.print();
    try{
        bst.remove(20);
    } catch(invalid_argument &error){
        cout<<error.what()<<endl;
    }
    bst.print();

    return 0;
}