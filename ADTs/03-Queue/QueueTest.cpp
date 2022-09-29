#include <iostream>
using namespace std;
#include "Queue.h"


int main()
{
    Queue<string> x =  Queue<string>();
    x.push("hola");
    x.push("crayola");
    x.push("como te va");
    x.print();

    x.pop();
    x.print();
    cout<<x.getFront()<<endl;
    x.print();
    return 0;
}
