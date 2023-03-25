//implementation

int func1(int a, int b)
{
    return a + b;
}

int func2(int a, int b)
{
    return a - b;
}

//struct is visible only in funcs.cpp file, main.cpp does not see it
struct PointFromCpp
{
    int x;
    int y;
    int z;
};