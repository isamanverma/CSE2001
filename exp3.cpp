#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string name, int accNum, string accType, double bal)
    {
        customerName = name;
        accountNumber = accNum;
        accountType = accType;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void displayBalance()
    {
        cout << "Balance: ₹" << balance << endl;
    }

    virtual void withdraw(double amount)
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
};

class SavAcct : public Account
{
public:
    void computeInterest(double rate, int time)
    {
        double interest = balance * pow(1 + rate / 100, time) - balance;
        balance += interest;
    }

    void withdraw(double amount) override
    {
        Account::withdraw(amount);
    }
};

class CurrAcct : public Account
{
private:
    double minBalance = 500.0;
    double penalty = 50.0;

public:
    void checkMinBalance()
    {
        if (balance < minBalance)
        {
            cout << "Balance below minimum. Penalty imposed: ₹" << penalty << endl;
            balance -= penalty;
        }
    }

    void withdraw(double amount) override
    {
        Account::withdraw(amount);
        checkMinBalance();
    }
};

int main()
{
    SavAcct savings;
    CurrAcct current;

    savings.initialize("Aman", 12345, "Savings", 1000.0);
    current.initialize("Dhruv", 67890, "Current", 800.0);

    savings.deposit(500.0);
    savings.computeInterest(5, 1);
    savings.withdraw(200.0);
    savings.displayBalance();

    current.deposit(300.0);
    current.withdraw(700.0);
    current.displayBalance();

    return 0;
}