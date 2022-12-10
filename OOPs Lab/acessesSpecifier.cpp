// #include <iostream>

// using namespace std;
// class acess
// {
// public:
//     int PublicNumber = 1234;
//     string PublicName = "nandu";

//     void display1()
//     {
//         cout << "public" << endl;
//         cout << PublicName << ":" << PublicName;
//     }

// private:
//     string PrivetWife = "kamla";
//     int kharcha = 40000;

//     void dislay2()
//     {
//         cout << "Privet" << endl;
//         cout << PrivetWife << kharcha << endl;
//     }

// protected:
//     string GfName = "laddo";
//     int Dob = 2001;

//     void display3()
//     {
//         cout << "Protected" << endl;
//         cout << GfName << ":" << Dob << endl;
//     }
// };

// class child : public acess
// {
// public:
//     string ChildCheck = GfName;
//     int CheckDob = Dob;

//     void display4()
//     {
//         cout << "ChildCheck" << endl;
//         cout << ChildCheck << ":" << CheckDob << endl;
//     }
// };

// int main()
// {
//     acess nandu;
//     nandu.display1();
    
//     child nandu2;
//     nandu2.display4();

//     return 0;
// }
#include<iostream>
     
    using namespace std;
     
    class Email{
        private:
        string password;
       
        protected:
        string email;
     
        public:
        void emailIns(){
            string email,password;
            cin>>email;
            cin>>password;
            this->email=email;
            this->password=password;
        }
     
        void emailGet(){
            cout<<"Email is: "<<this->email<<endl;
        }
    };
     
    int main(){
        Email email1;
        cout<<"Enter Email/Password"<<endl;
        email1.emailIns();
        email1.emailGet();
     
        return 0;
    }