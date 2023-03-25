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

void dynamic_HEAP_mem_alloc_01()
{
    int* ptr = nullptr; // equivalent to int* ptr {}
    cout << "address of nullptr = " << ptr << endl;
    ptr = new int; //gives address
    cout << "address of ptr after new = " << ptr << endl;
    ptr = new int{3}; //gives address and puts data
    cout << "address of ptr after second new = " << ptr << endl;
    cout << "Value in this address = " << *ptr << endl;
    //return ptr;
    delete ptr; //does not take address; removes data and puts some crap; OS owns this memory now
    //delete ptr; // DON'T DELETE TWICE
    cout << "address after deallocating = " << ptr << endl;
    cout << "Value in this address after deallocating = " << *ptr << endl;
    ptr = nullptr; // no address now
}

void allocation_on_stack_and_heap()
{
    int x = 7;
    cout << "x ref: " << &x << endl;
    int* ptr = &x;
    cout << "ptr address: " << ptr << endl;
    int* ptrH = new int{x};
    cout << "ptr address in HEAP: " << ptrH << endl;
}

void when_new_fails()
{
    //int* ptr {new int[1000000000000000000]}; runtime error bad alloc

    if (0)
    {
        for (auto i = 0; i < 100; i++)
        {
            try
            {
                int* ptr {new int[1000000000]};
                cout << i << endl;
            }
            catch(exception& ex)
            {
                cerr << "Bad alloc man" << ex.what() << endl;
            }

        }
    }
    if (1)
    {
        for (auto i = 0; i < 10; i++)
        {
            int* ptr = new(std::nothrow) int[1000000000];
            cout << i << endl;
            if (ptr == nullptr)
                cerr << "Bad alloc man" << endl;
            else
                cout << "Good alloc" << endl;
        }
    }
    cout << "Finish";
}

void memory_leak1()
{
    int* ptr {new int{55}};
    int number {77};
    ptr = &number; // but ptr is not released, our program holds the address
}

void memory_leak2()
{
    int* ptr {new int{55}};
    ptr = new int {77}; // but ptr is not released, our program holds the address
}

void memory_leak3()
{
    {
        int* ptr {new int{77}};
        // local ptr was not released and lost in local scope
    }
    // no access to ptr here, but program holds the address
}

void array_alloc()
{
    int a1[5]; //array allocated in stack filled with rubbish
    int a2[5] {}; //array allocated in stack filled with 0s
    int a3[5] {1,2,3};
    int* a4 = new int[5];//array allocated in heap, filled with crap
    int* a5 = new int[5] {};//array allocated in heap, filled with 0s
    int* a6 = new int[5] {1,2,3};
    if (0) {
        for (auto item : a3)
        {
            cout << item << endl;
        }
    }
    int* ptrs[3] { a4, a5, a6 };
    for (int* ptr : ptrs)
    {
        if (ptr) 
        {
            cout << "Array " << ptr << endl;
            for (size_t i = 0; i < 5; i++) //size of array in heap is unknown for C++
            {
                cout << *(ptr+i) << endl;
            }
        }
    }

    cout << "Size of array in stack: " << size(a3) << endl;
    //not working as size of array in heap is unknown
    //cout << "Size of array in heap: " << size(a4) << endl;
    
    delete[] a4;
    delete[] a5;
    delete[] a6;
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

void strings01()
{
    //cout << std::isdigit('3') << std::isdigit('D') << endl;
    const char s1[9] {"Hello"};
    const char* s2 = "Hello"; // = {"Hello"}, {"Hello"} - works
    string s3 {"Hello"};
    cout << s1 << ' ' << std::strlen(s1) << ' ' << sizeof(s1) << endl;
    cout << s2 << ' ' << std::strlen(s2) << ' ' << sizeof(s2) << endl; //shows size of pointer
    cout << s3 << ' ' << s3.length() << ' ' << sizeof(s3) << endl;
}

void strings02()
{
    const char* s {"Mancester United"};
    char c {'U'};
    const char* p1 = strchr(s, c);
    char* p2 = strchr(s, c);
    cout << p1 << *p2;
    cout << strlen(p1) << sizeof(p2);
}

void strings03()
{
    char s1[10] {"Hello "};
    char s2[10] {"World"};
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 adress: " << &s1;
    auto res = strcat(s1, s2);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << *res << endl;
    cout << "s1 adress: " << &s1;
}

void strings04()
{
    char s1[10] {"Hello"};
    char s2[20] {"World1234567890"};
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 adress: " << &s1 << endl;
    auto res = strcpy(s1, s2);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << *res << endl;
    cout << "s1 adress: " << &s1;
}

void strings05std()
{
    string s1;
    string s2 {"Hello!"};
    string s3 {"Hello!", 5};
    cout << s3.length() << s3;
}

void strings06()
{
    string s1 = "string";
    cout << &s1 << endl;
    s1 = "new string"; //ok, memory taken by "string" is returned
    cout << &s1 << endl;

    const char* s2 = "string";
    cout << &s2 << endl;
    s2 = "new string324932875432523894328545832423423423432423423423424324242342536758769787543242";
    //possible memory leak. memory is still taken by "string"
    cout << &s2 << endl;
}

void pass_by_reference(const int& a)
{
    cout << a;
}

int main()
{
    pointers_const();
    cout << "Hello World!" << endl;
    int a = 4;
    cout << a;
    int& p = a;
    p = 5;
    cout << a;
    pass_by_reference(p);
    cout << a;
}