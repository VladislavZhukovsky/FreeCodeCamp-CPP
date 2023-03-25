#include <iostream>
#include "funcs.h"
#include "funcs1.h"

using namespace std;

struct PointFromMain
{
    double x;
    double y;
};

int main()
{
    cout << "Hello World!" << endl;
    cout << func1(2,3) << "\n";
    func2(5,6);
    PointFromMain *pm = new PointFromMain();
    //PointFromCpp *pf = new PointFromFuncsCpp(); //cannot see PointfromFuncsCpp from cpp file
    PointFromH *ph = new PointFromH(); // PointFromH
    //func11(3,4); //definition not found
    cin.get();
    return 0;
}