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
    
    try
    {
        cout<<x.getData(7)<<endl;
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    
     try
    {
        x[2]="diez";
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    x.print();
    return 0;

}
