#include<iostream>
#include<vector>
using namespace std;
class Account{
    private:
        int AccountNumber;
        double Balance;
        public:
        enum class AccountType{ SAVINGS, CHECKING };
        AccountType accountType;
        int getAccountNumber() {
            return AccountNumber;
        }
        Account(){
            AccountNumber = 0;
            Balance = 0;
            accountType = AccountType::SAVINGS;
        }
        Account(int number , double balance , AccountType type)
        : AccountNumber(number) , Balance(balance) , accountType(type){}
        void Deposit(double depo){
            if(depo <= 0){
                cout<<"Invalid Deposit Amount.."<<endl;
            }
            else{
                Balance +=depo;
            }
        }
        void Withdrawal(double with){
            if(with > Balance){
                cout<<"Withdrawal Amount cannot be larger than Balance.."<<endl;
            }
            else if(with <= 0){
                cout<<"Invalid Withdrawal Amount"<<endl;
            }
            else{
                Balance -= with;
            }
        }
        void Display_Balance(){
            cout<<"Balance: "<<Balance<<endl;
        }
        ~Account(){
        }
};
int main(){
    vector <Account>accounts;
    vector<Account> :: iterator it;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Welcome to the OOP bank"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    int choice;
    do{
        cout<<"----------MENU----------"<<endl;
        cout<<"1.Create Account"<<endl<<"2.Deposit"<<endl<<"3.Withdraw"<<endl<<"4.Check Balance"<<endl<<"5.Exit"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Choose your option(1 , 2 , 3 , 4 or 5):"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                int acc_no;
                double bal;
                int type;
                cout<<"Enter Account Number: "<<endl;
                cin>>acc_no;
                bool exists = false;
                for(it = accounts.begin() ; it != accounts.end() ; ++it){
                    if(it->getAccountNumber() == acc_no){
                        exists  = true;
                        break;
                    }
                }
                if(exists){
                    cout<<"Account already exists!"<<endl;
                    break;
                }
                cout<<"Enter Initial Balance: "<<endl;
                cin>>bal;
                if(bal < 0){
                    cout<<"Balance cannot be negative"<<endl;
                    break;
                }
                cout<<"Enter Account Type: "<<endl<<"1.Savings"<<"2.Checking"<<endl;
                cin>>type;
                Account::AccountType accountType;
                if (type == 1) {
                    accountType = Account::AccountType::SAVINGS;
                }
                else if (type == 2) {
                    accountType = Account::AccountType::CHECKING;
                }
                accounts.push_back(Account(acc_no, bal, accountType));
                cout<<"Account created Successfully!!"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 2:{
                cout<<"----------Deposit----------"<<endl;
                int accNo;
                double dep;
                cout<<"Enter Account Number: "<<endl;
                cin>>accNo;
                bool exists = false;
                for(it = accounts.begin() ; it != accounts.end() ; ++it){
                    if(it->getAccountNumber() == accNo){
                        exists  = true;
                        break;
                    }
                }
                if(exists){
                    cout<<"Enter Deposit Amount: "<<endl;
                    cin>>dep;
                    it->Deposit(dep);
                    char display;
                    cout<<"Do you want to view the balance:y/n"<<endl;
                    cin>>display;
                    if(display == 'y'){
                        it->Display_Balance();
                    }
                }
                else{
                    cout<<"Create an Account through option 1"<<endl;
                }
                cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 3:{
                cout<<"----------Withdrawal----------"<<endl;
                int accNo;
                double with;
                cout<<"Enter Account Number: "<<endl;
                cin>>accNo;
                bool exists = false;
                for(it = accounts.begin() ; it != accounts.end() ; ++it){
                    if(it->getAccountNumber() == accNo){
                        exists  = true;
                        break;
                    }
                }
                if(exists){
                    cout<<"Enter the Amount to withdraw: "<<endl;
                    cin>>with;
                    it->Withdrawal(with);
                    char display;
                    cout<<"Do you want to view the balance:y/n"<<endl;
                    cin>>display;
                    if(display == 'y'){
                        it->Display_Balance();
                    }
                }
                cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 4:{
                cout<<"Displaying Balance..."<<endl;
                int acc_no;
                cout<<"Enter Account Number: "<<endl;
                cin>>acc_no;
                for (it = accounts.begin(); it != accounts.end(); ++it) {
                    if (it->getAccountNumber() == acc_no) {
                        it->Display_Balance();
                    }
                }
                cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 5:{
                cout<<"Thank You for visiting OOP Bank..."<<endl;
                cout<<"Please Visit us Again..."<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
        }
    }while(choice != 5);
    return 0;
}