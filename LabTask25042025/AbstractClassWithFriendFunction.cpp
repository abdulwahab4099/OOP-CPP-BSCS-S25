/*
Q2. Abstract Class with Friend Function


 Create an abstract class Account with a pure virtual function void showBalance().
 Then implement a class SavingsAccount that inherits from Account and contains a
 private data member balance.
 Create a separate class FriendAuditor with a friend function void checkBalance(SavingsAccount&).
 This function should access the private balance and display it. Demonstrate the working
 in main().
*/


#include <iostream>
using namespace std;

// Abstract class Account
class account {
public:
    // Pure virtual function
    virtual void showBalance() const = 0;

    // Virtual destructor
    virtual ~account() {}
};

// Forward declaration of class FriendAuditor
class FriendAuditor;

// Derived class SavingsAccount
class SavingsAccount : public account {
private:
    double balance;

public:
    // Constructor
    SavingsAccount(double b) : balance(b) {}

    // Override pure virtual function
    void showBalance() const override {
        cout << "Balance shown from showBalance(): " << balance << endl;
    }

    // Declare friend function from FriendAuditor
    friend void checkBalance(SavingsAccount&); 
};

// Separate class with friend function
class FriendAuditor {
public:
    // Friend function to access private balance
    friend void checkBalance(SavingsAccount& acc);
};

// Friend function definition
void checkBalance(SavingsAccount& acc) {
    cout << "Balance accessed by FriendAuditor: " << acc.balance << endl;
}

// Main function
int main() {
    SavingsAccount myAccount(5000.75);

    myAccount.showBalance();          // Called from within the class
    checkBalance(myAccount);          // Called from a friend function

    return 0;
}
