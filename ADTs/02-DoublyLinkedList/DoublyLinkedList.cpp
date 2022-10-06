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
    cout<<x[4]<<endl;
    x.print();
    x.deleteAt(2);
    x.print();
    x.deleteData("Hola");
    x.print();
    cout<<x[1]<<endl;
 return 0;   
}
