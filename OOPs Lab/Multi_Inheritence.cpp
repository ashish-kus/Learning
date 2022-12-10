#include <iostream>
using namespace std;

class parent
{
public:
    string who = "parent";

    void display()
    {
        cout << "Hello im parent" << endl;
    }
};
class child : public parent
{
public:
    void bol()
    {
        cout << "Im in first child " << endl;
    }
};
class super_child : public child
{
public:
    void bak()
    {
        cout << "hey, Im super child";
    }
};
int main()
{
    super_child nandu;
    nandu.display();
    nandu.bol();
    nandu.bak();

    return 0;
}