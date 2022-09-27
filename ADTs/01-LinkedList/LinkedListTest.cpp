#include <iostream>
using namespace std;

#include "LinkedList.h"
int main()
{
    LinkedList<string> x = LinkedList<string>();
    x.appendLeft("Hola");
    x.append("A");
    x.append("B");
    x.append("C");
    x.append("D");
    x.appendLeft("E");
    try
    {
         x.insert("F", 10);
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    
   

    x.appendLeft("Y");
    x.print();

    //x.deleteAt(0);
    
    //cout<<"Borrando..."<<endl;
    x.deleteData("olo");
    cout<<x.findData("Hola")<<endl;
    cout<<x.getData(0)<<endl;
    cout<<x[6]<<endl;
    return 0;

}
