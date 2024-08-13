#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
    string name;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount(string n, int accNum, string accType, double bal)
    {
        name = n;
        accountNumber = accNum;
        accountType = accType;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

int main()
{
    BankAccount account("Amankumar Verma", 2349852, "Savings", 23423.0);

    account.deposit(500.0);
    account.withdraw(200.0);

    account.display();

    return 0;
}