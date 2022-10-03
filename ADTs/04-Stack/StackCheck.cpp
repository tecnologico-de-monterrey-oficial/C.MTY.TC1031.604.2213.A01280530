#include <iostream>
using namespace std;
#include "Stack.h"
int main()
{
    Stack<string> x = Stack<string>();
    x.push("Hola");
    x.push("Crayola");
    x.print();
    x.pop();
    x.print();
    cout<<x.getTop()<<endl;
    return 0;
}
