#include <iostream>

using namespace std;

class smart
{
public:
    string name;
    int marks;

    smart(string name)
    {
        this->name = name;
        this->marks = 0;
        cout << name << "marks ka pata nahi" << endl;
    }
    smart(string name, int marks)
    {
        this->marks = marks;
        this->name = name;
        cout << name << "got in :" << marks << endl;
    }
    void display()
    {
        cout << this->name << "got : " << marks << endl;
    }
};
int main()
{
    smart asish("ashish");
    
    asish.display();

    return 0;
}