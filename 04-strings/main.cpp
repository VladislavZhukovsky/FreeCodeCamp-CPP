#include <iostream>
#include <cstring>
//#include <file.cpp>

using namespace std;

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

int main()
{
}