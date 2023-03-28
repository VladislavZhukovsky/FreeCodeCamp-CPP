#include <iostream>
#include <cstring>

using std::cout, std::endl;

template <typename T>
T func1(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T func2(T a, T b)
{
    return a > b ? a : b;
}

template <> // explicit template
const char* func2(const char* a, const char* b)
{
    return std::strcmp(a,b) > 0 ? a : b;
}

int main()
{
    const char* a {"wild"};
    const char* b {"animal"};
    cout << func2(a, b) << endl;
}