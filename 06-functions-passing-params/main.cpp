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

void pass_by_reference(int& a)
{
    ++a;
}

int main()
{
    int a = 1;
    pass_by_value(a);
    cout << a;
    pass_by_pointer(&a);
    cout << a;
    pass_by_reference(a);
    cout << a;
}