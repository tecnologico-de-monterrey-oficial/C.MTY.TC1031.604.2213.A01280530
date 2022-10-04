#include <iostream>
using namespace std;
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList<string> x = DoublyLinkedList<string>();
    x.append("Hola");
    x.appendLeft("Crayola");
    x.append("XD");
    x.print();
    x.print();
    x.insert(2,"YO");
    x.insert(2, "NO");
    x.print();
    x.deleteAt(2);
    x.print();
 return 0;   
}
