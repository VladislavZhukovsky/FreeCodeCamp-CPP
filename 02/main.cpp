#include <iostream>
#include "funcs.h"

using namespace std;

struct Point
{
    double x;
    double y;
};

int main()
{
    cout << "Hello World!" << endl;
    cout << add(2,3) << "\n";
    cin.get();
    return 0;
}