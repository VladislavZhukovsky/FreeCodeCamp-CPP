#include <iostream>

using namespace std;

int foo(int a, int b)
{
    return a + b;
}

void m01_beginning()
{
    // int x {3};
    // int y (4.7);
    // cout << "Hello World!" << endl;
    // cout << "Enter number x: ";
    // cin >> x;
    // cout << "x + y = " << foo(x, y) << endl;

    std::string s;
    cout << "Enter string s: ";
    std::getline(std::cin, s);
    // cin >> s;
    cout << "You entered: " << s << endl;
    
    //cerr << "error!" << endl;

    //types
    int integer_type = 7;
    float float_type = 3.14;
    double double_type = 2.78;
    char char_type = 'a';
    bool bool_type = true && false;
}

void m02_number_types()
{
    int int1 = 10;
    int int2 = 010;
    int int3 = 0x10;
    int int4 = 0b10;
    string space = " ";
    //cout << int1 << space << int2 << space << int3 << space << int4 << endl;

    int x {10};
    //int y {10.8}; //error
    int y (10.8);
}

void m03_integer_number_types()
{
    int v = 1.4;
    long x = 1;
    long long y = 2;
    cout << sizeof(y) << endl;
}

void m03_floating_point_number_types()
{
    float x = -5.5;
    float* ptr = &x;
    double y = 2.2;
    long double z = 3.3;
    //cout << sizeof(x) << endl;
    //cout << sizeof(y) << endl;
    //cout << sizeof(z) << endl;
    float zero = 0.0;
    //int u = 1; int v = 0;
    //cout << u / v << endl; runtime error
    cout << x / zero << endl; // -inf
    int infinity = x / zero;
    cout << sizeof(infinity) << endl;
    auto* ptr1 = &infinity;
}

void m04_booleans()
{
    bool b = true;
    bool* ptr = &b;
    
    cout << std::boolalpha;
    cout << true;
}

void m05_chars()
{
    char c = 200;
    char* ptr = &c;
}

void m06_auto()
{
    auto a {3};
    auto b {3.3}; //double 8 bytes
    auto c {3.3l}; //long double 16 bytes
    auto d {3.3f}; //float 4 bytes

    auto e {500ll}; // long long 8 bytes int64
}

void m07_io_manipulators()
{
    cout << "tyui";
    cout << "qwer";
    //cout << std::flush;
}

int main()
{
    size_t x = 4;
    cout << sizeof(x);
}