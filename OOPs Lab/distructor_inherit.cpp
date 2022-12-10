#include <iostream>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "I am parent" << endl;
    }
    void display()
    {
        cout << "Display from parent" << endl;
    }
    ~Parent()
    {
        cout << "Parent dead" << endl;
    }
};

class Child : public Parent
{
public:
    Child() : Parent()
    {
        cout << "Hello i am child" << endl;
    }
    ~Child()
    {
        cout << "Child dead" << endl;
    }
};

int main()
{
    Child c = Child();

    c.display();
    return 0;
}