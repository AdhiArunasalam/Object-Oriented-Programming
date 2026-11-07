#include<iostream>
#include<sstream>
#include<fstream>
#include<windows.h>
using namespace std;

class Login{
    
    private:
        string username;
        string password;
    
        public: 
        Login(){
            username = "";
            password = "";
        }
        void setname(string username){
            this->username = username;
        }
        void pwd(string password){
            this->password = password;
        }
        string getname(){
            return username;
        }
        string getpwd(){
            return password;
        }
};

void registration(Login log1){
    string n , pass;
    cout<<"Enter the usename: ";
    getline(cin>>ws,n);
    log1.setname(n);
    start:
    cout<<"Enter a Strong Password:(Minimum of 8 characters: )"<<endl;
    cin>>pass;
    if(pass.length() >= 8){
        log1.pwd(pass);
    }
    else{
        cout<<"Please choose a strong password"<<endl;
        goto start;
    }
    ofstream outfile("D:/ADHI/PROJECTS/2_OOP_LOGIN_REGISTER/uname_pwd.txt" , ios::app);
    if(!outfile){
        cout<<"Sorry! Cannot register account..."<<endl;
    }
    else{
        outfile<<"\t"<<log1.getname()<<" : "<<log1.getpwd()<<endl;
        cout<<"User registered successfully"<<endl;
    }
    outfile.close();
}

void login(Login log1){
    string name , pass;
    cout<<"Enter Your username: "<<endl;
    getline(cin>>ws , name);
    cout<<"Enter Your Password: "<<endl;
    cin>>pass;
    ifstream infile("D:/ADHI/PROJECTS/2_OOP_LOGIN_REGISTER/uname_pwd.txt");
    if(!infile){
        cout<<"Sorry! Failed to Login.."<<endl;
    }
    else{
        string line;
        bool found = false;
        while(getline(infile , line)){
            stringstream ss;
            ss<<line;
            string test_name , test_pwd;
            char delimiter;
            ss>>test_name>>delimiter>>test_pwd;
            if(name == test_name && pass == test_pwd){
                found = true;
                cout<<"Successfully Logged in!"<<endl;
                break;
            }
        }
        if(!found){
            cout<<"Invalid Credentials..."<<endl;
        }
        else{
            cout<<"Welcome to the Home Page!"<<endl;
        }
    }
}

int main(){
    int choice;
    Login log1;
    bool exit = false;
    while(!exit){
        cout<<"----------Login and Registration Form----------"<<endl;
        cout<<"----------MENU----------"<<endl;
        cout<<"1.Register\n2.Login\n3.exit"<<endl;
        cin>>choice;
        if(choice == 1){
            registration(log1);
        }

        else if(choice == 2){
            login(log1);
        }

        else if(choice == 3){
            cout<<"Thank You!\nVisit Us Again..."<<endl;
            exit = true;
        }

        else{
            cout<<"Invalid Choice!\nClick 1 for Registration\nClick 2 for Login\nClick 3 to exit\n"<<endl;
        }
}
    return 0;
}