#include <iostream>
#include <cstring>
//#include <file.cpp>

using namespace std;

void arrays()
{
    // set size or initialize!!!!
    int a1[3];
    int a2[3] {1,2,3};
    int a3[] {1,2,3};
    int* a4 = new int[3];

    cout << sizeof(a1) << endl;
    cout << sizeof(a4) << endl;
}

void char_array()
{
    //int a2[3] {1,2,3};
    //cout << a2 << endl; // prints address
    char s1[] = {'H','e','l','l','o'};
    char* s1p = s1;
    char s2[] = {'H','e','l','l','o', '\0'};
    char* s2p = s2;
    char s3[6] = {'H','e','l','l','o'};
    char* s3p = s3;
    cout << sizeof(s1) << ' ' << s1 << ' ' << s1p << endl;
    cout << sizeof(s2) << ' ' << s2 << ' ' << s2p  << endl;
    cout << sizeof(s3) << ' ' << s3 << ' ' << s3p  << endl;
}

void array_bounds()
{
    int a[] {1,2,3};
    cout << a[4] << endl;
    a[12473463] = 55; // CRASH
    cout << a[4] << endl;
    cout << "Finish";
}

int main()
{
}