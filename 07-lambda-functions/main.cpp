#include <iostream>

using namespace std;

void m01()
{
    auto helloFunc = []()
    {
        cout << "Hello!" << endl;
    };
    helloFunc();
    cout << "Sizeof lambda: " << sizeof(helloFunc) << endl;

    int b = [](int a, int b) -> int { return a + b; } (5,6);
    cout << "b = " << b << endl;
    int a = 3;
}

void m02()
{
    auto func1 = [](double x, double y) -> double { return x + y; };
    auto func2 = [](double x, double y) -> int { return x + y; };
    auto func3 = [](double x, double y) -> long long { return x + y; };

    auto func4 = [](int x, int y) -> int { return x + y; };

    double x = 1.1, y = 2.2;
    auto z1 = func1(x, y);
    cout << "z1 = " << z1 << " size: " << sizeof(z1) << endl;
    auto z2 = func2(x, y);
    cout << "z2 = " << z2 << " size: " << sizeof(z2) << endl;
    auto z3 = func3(x, y);
    cout << "z3 = " << z3 << " size: " << sizeof(z3) << endl;
    auto z4 = func4(x, y);
    cout << "z4 = " << z4 << " size: " << sizeof(z4) << endl;
}

void m03()
{
    int x = 2;
    cout << x << endl;
    [](int x){ ++x; } (x);
    cout << x << endl;
}

void m03_capture_by_value()
{
    int x {12}; //x = 12
    //capture by value - x is a COPY
    auto f = [x](){ cout << "From lambda: " << x << " " << &x << endl; };

    cout << x << " " << &x << endl; //show 12
    f(); //show 12
    x++; //x = 13
    cout << x << " " << &x << endl; //show 13
    f(); //show 12
}

void m04_capture_by_ref()
{
    int x {12}; //x = 12
    //capture by value - x is a REFERENCE
    auto f = [&x](){ cout << "From lambda: " << x << " " << &x << endl; };

    cout << x << " " << &x << endl; //show 12
    f(); //show 12
    x++; //x = 13
    cout << x << " " << &x << endl; //show 13
    f(); //show 13
}

void m05_nested_lambda()
{
    int x {10}; //assume x has 0x1 address here
    cout << "SCOPE: x address:  " << &x << endl; //showing 0x1 for x address
    auto show = [](const int& y)
    {
        cout << "SHOW: parameter address: " << &y << endl; 
    };
    cout << "SCOPE: show-lambda address: " << &show << endl;
    show(x); // showing 0x2 for x address
    auto fv = [ x, show]()
    {
        cout << "FV  : x address: " << &x << " " << endl; //0x3
        cout << "FV  : show-lambda address:" << &show << endl;
        show(x); // showing 0x4 for x address
    };
    auto fr = [&x, show]()
    { 
        cout << "FR  : x address: " << &x << " " << endl; //showing 0x1 for x address
        cout << "FR  : show-lambda address:" << &show << endl;
        show(x); //showing 0x4 for x address - WHY???
        //ANSWER: seems like it is 'by chance'. I understand the flow and allocation right
    };
    fv();
    fr();
}

void m05_capture_all()
{
    int x {10};
    auto f1 = [=](){ cout << x; };
    auto f2 = [&](){ cout << x; };
    f1();
    f2();
    ++x;
    f1();
    f2();
}

int main(int argc, char **argv)
{
    m05_nested_lambda();
}