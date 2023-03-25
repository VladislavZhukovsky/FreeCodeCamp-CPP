#include <iostream>
#include <cstring>
//#include <file.cpp>

using namespace std;

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

int main()
{
}