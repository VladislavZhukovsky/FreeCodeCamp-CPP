#include <iostream>
#include <cstring>
//#include <file.cpp>

using namespace std;

void pass_by_value(int a)
{
    ++a;
}

void pass_by_pointer(int* a)
{
    (*a)++;
}

void pass_by_const_pointer(int* const a)
{
    (*a)++;
}

void pass_by_reference(int& a)
{
    ++a;
}

void m01()
{
    int a = 1;

    cout << a;
    cout << &a;

    pass_by_value(a);
    cout << a;
    pass_by_pointer(&a);
    cout << a;
    pass_by_const_pointer(&a);
    cout << a;
    pass_by_reference(a);
    cout << a;
}

void m02()
{
    int b = 1;
    int& a = b;

    cout << a;
    cout << &a;
    cout << "\n";

    pass_by_value(a);
    cout << a;
    pass_by_reference(a);
    cout << a;
}

int main()
{
    m02();
}