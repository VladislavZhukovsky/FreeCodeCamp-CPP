#include <iostream>
#include "templates.h"

using std::cout, std::endl;

//template <typename T> T maximum(int a, int b);
//it is not a code. it is just a blueprint

template <typename T, typename U>
T maximum(T a, U b)
{
    return a > b ? a : b;
}

template <typename T>
void func1(T& x)
{
    cout << &x << endl;
}

template<typename T> 
const T& func2(const T& a, const T& b)
{
    return a;
}

int main()
{
    cout << "Hello world!" << endl;
    cout << maximum(1, 2.2) << endl; //creates version of int (int, int) function only if such call exist
    //generated functions is call template instance
    //template instances are created only once, not every time function is called
    cout << maximum(1.1, 2.2) << endl;

    int x{5};
    int y{7};
    int *px {&x};
    int *py {&y};
    cout << *maximum1(px,py) << endl;
    cout << sizeof(maximum1<double>(x, y)) << endl;
    double a {1.1}, b {2.2};
    //cout << maximum1(x, b) << endl; //compilation error
    cout << maximum1<int>(x, b) << endl;

    auto result = func2(x, y);
    cout << result << endl;
}