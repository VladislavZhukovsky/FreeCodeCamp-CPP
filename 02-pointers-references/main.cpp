#include <iostream>
#include <cstring>
//#include <file.cpp>

using namespace std;

void pointers()
{
    int x = 1;
    double y = 1;
    int* intPtr = &x;
    //intPtr = &y; //compile error
    double* doublePtr = &y;
    cout << sizeof(bool*);
}

void pointers_char()
{
    //char* s = "Hello"; //warning
    const char* r {"Hello"};
    //*r = 'S';
    char* s = new char[5] {'H','e','l','l','o'};
    char q[5] {'H','e','l','l','o'};
    char* qPointer = q;
    cout << r << endl;
    cout << s << endl;
    cout << q << endl;
    cout << qPointer << endl;
}

void pointers_const()
{
    int x = 3;
    int y = 4;
    const int* p = &x;
    p = &y;
    // *p = 5; //compile error
    cout << *p;
}

void references()
{
    int x = 3;
    int y = 4;
    int& ref1 = x;
    ref1 = y; //updates the value, but references same memory
    //int& ref2 {4}; reference must reference some variable
    cout << x << ' ' << &x << ' ' << ref1 << ' ' << &ref1;
    int* p = &ref1;
    (*p)++;
    cout << x << ' ' << &x << ' ' << ref1 << ' ' << &ref1;
}

void const_refs_and_ptrs()
{
    int* p1; //pointer
    const int* p2; //pointer to const int, you cannot change value
    int* const p3 {}; //const pointer to int, must be initialized, you cannot change address
    const int* const p4 {}; //const pointer to const int, must be initialized, you can change neither address nor value

    int x {2};
    int& ref1 {x};
    //int& const ref2 {x}; //no const refs, they are always const
    const int& ref3 {}; //ref to const int
    cout << ref3 << endl;
}

int main()
{
}