#include <iostream>
using namespace std;

class lvalue {

};

int main()
{
    int i = 3;
    int* pi = &i;
    cout << *pi << endl;

    int& ri = i;
    cout << ri << endl;
    return 0;
}
