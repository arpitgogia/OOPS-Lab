#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
class Account {
protected:
    string account_no, name;
    char type;
    float balance;
public:
    void updateBalance(float amount) {
        this -> balance += amount;
        printBalance();
    }
    void printBalance() {
        cout << "Transaction Complete ! Your account balance is : Rs. " << this -> balance << "\n";
        checkMinimum();
    }
    void computeInterest() {
        if(this -> type == 'C') {
            cout << "Current Account does not have Interest facility !\n";
            return;
        }
        int years;
        cout << "Enter time in years for interest compounded annually at 10%: ";
        cin >> years;
        float p = this -> balance;
        float temp = (1 + 10.0 / 100.0);
        float interest = pow(temp, years);
        interest *= p;
        cout << "Interest : Rs. " << interest << "\n";
        updateBalance(interest);
    }
    void checkMinimum() {
        if(this -> balance < 500.0) {
            cout << "Your account balance is below the minimum balance, a penalty of Rs. 100 will be imposed\n";
            updateBalance(-100.0);
        } else 
            cout << "Your account balance is above the minimum balance\n";
    }
    void details() {
        cout << "Name : " << this -> name << "\n";
        cout << "Type : " << this -> type << "\n";
        cout << "Balance : " << this -> balance << "\n";
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string account_no, string name, float balance) {
        this -> account_no = account_no;
        this -> name = name;
        this -> type = 'S';
        this -> balance = balance;
    }    
};
class CurrentAccount : public Account {
public:
    CurrentAccount(string account_no, string name, float balance) {
        this -> account_no = account_no;
        this -> name = name;
        this -> type = 'C';
        this -> balance = balance;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    char type;
    string name, account_no;
    float amount, balance;
    cout << "Enter type of account Savings / Current (S / C) : ";
    cin >> type;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter account no. : ";
    cin >> account_no;
    cout << "Enter Initial Balance : ";
    cin >> balance;
    while (balance < 500.0) {
        cout << "Minimum Balance is Rs. 500.0" << "\n";
        cout << "Please enter Initial balance again : ";
        cin >> balance;
    }
    if(type == 'S') {
        SavingsAccount sAccount(account_no, name, balance);
        char option = 'c';
        while (option != '0') {
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Compute Interest\n";
            cout << "4. Check for Minimum Balance\n";
            cout << "5. Details\n";
            cout << "0. Exit\n";
            cin >> option;
            switch(option) {
                case '1' :
                    cout << "Enter amount to deposit : ";
                    cin >> amount;
                    sAccount.updateBalance(amount);
                    break;
                case '2' : 
                    cout << "Enter amount to withdraw : ";
                    cin >> amount;
                    sAccount.updateBalance(-amount);
                    break;
                case '3' : 
                    cout << "Computing Interest...\n";
                    sAccount.computeInterest();
                    break;
                case '4' : 
                    sAccount.checkMinimum();
                    break;
                case '5' : 
                    sAccount.details();
                    break;
                case '0' : 
                    break;
            }
        }
    }
    else {
        CurrentAccount cAccount(account_no, name, balance);
        char option = 'c';
        while (option != '0') {
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Compute Interest\n";
            cout << "4. Check for Minimum Balance\n";
            cout << "5. Details\n";
            cout << "0. Exit\n";
            cin >> option;
            switch(option) {
                case '1' :
                    cout << "Enter amount to deposit : ";
                    cin >> amount;
                    cAccount.updateBalance(amount);
                    break;
                case '2' : 
                    cout << "Enter amount to withdraw : ";
                    cin >> amount;
                    cAccount.updateBalance(-amount);
                    break;
                case '3' : 
                    cout << "Computing Interest...\n";
                    cAccount.computeInterest();
                    break;
                case '4' : 
                    cAccount.checkMinimum();
                    break;
                case '5' :
                    cAccount.details();
                    break;
                case '0' : 
                    break;
            }
        }
    }
}
