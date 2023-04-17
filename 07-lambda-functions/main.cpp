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
    int s {9};
    cout << "SCOPE: x address:  " << &x << endl; //showing 0x1 for x address
    auto show = [](int y)
    {
        cout << "SHOW: parameter address: " << &y << endl; 
    };
    cout << "SCOPE: show-lambda address: " << &show << endl;
    show(x); // showing 0x2 for x address
    ++x;
    show(x);
    auto fv = [ x, show]()
    {
        cout << "FV  : x address: " << &x << " " << endl; //0x3
        cout << "FV  : show-lambda address:" << &show << endl;
        show(x); // showing 0x4 for x address
    };
    auto fr = [&s, show]()
    { 
        cout << "FR  : x address: " << &s << " " << endl; //showing 0x1 for x address
        cout << "FR  : show-lambda address:" << &show << endl;
        show(s); //showing 0x4 for x address - WHY???
        //ANSWER: as lambda's body compiled into one place, program goes to one and only block of memory
        //that's why passed parameter is put to same address
    };
    fv();
    fr();
}

void m05_nested_lambda_class()
{
    struct __showFunctor
    {
        auto operator()(int y){ cout << "SHOW: parameter address: " << &y << endl;  }
    };

    __showFunctor showFunctor;

    int x {10}; //assume x has 0x1 address here
    int a {11}; int b {12};
    cout << &a << " " << &b << endl;
    showFunctor(a);
    showFunctor(b);
    cout << "SCOPE: x address:  " << &x << endl; //showing 0x1 for x address

    cout << "SCOPE: functor address: " << &showFunctor << endl;
    cout << "SCOPE: ";
    showFunctor(x); // showing 0x2 for x address
    auto fv = [ x]()
    {
        __showFunctor sfv;
        cout << "\t" << "FV  : captured x address: " << &x << " " << endl; //0x3
        cout << "\t" << "FV  : show-functor address:" << &sfv << endl;
        cout << "\t" << "FV  : ";
        sfv(x); // showing 0x4 for x address
    };
    auto fr = [&x]()
    { 
        __showFunctor sfr;
        cout << "\t" << "FR  : captured x address: " << &x << " " << endl; //showing 0x1 for x address
        cout << "\t" << "FR  : show-functor address:" << &sfr << endl;
        cout << "\t" << "FR  : ";
        sfr(x); // showing 0x4 for x address - same as inside FV

    };
    fv();
    fr();
}

void m05_capture_all()
{
    int x {10};
    auto f1 = [x](){ cout << &x << endl; };
    auto f2 = [x](){ cout << &x << endl; };
    f1();
    f1();
}

int main(int argc, char **argv)
{
    m05_capture_all();
}