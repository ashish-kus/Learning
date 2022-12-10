#include <iostream>
using namespace std;

class D_argu
{
public:
    int rollno;
    string name;
    D_argu()
    {
        this->rollno = 00;
        this->name = "Name";
    }
    D_argu(int Rollno, string Name)
    {
        this->rollno = Rollno;
        this->name = Name;
    }
    void display(){
        cout<<rollno<<endl;
        cout<<name<<endl;
    }
};

int main()
{
    D_argu ashih;
    D_argu Ashih(235, "nandu");
    return 0;
}

