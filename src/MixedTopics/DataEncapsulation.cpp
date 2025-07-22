/*Encapsulation is about bundling data and methods that operate on that data within a single unit (class)
 and restricting direct access to some of the object’s components.*/
#include <iostream>
using namespace std;
class Account 
{
    private:
    double balance;  // hidden from outside

    public:
    void deposit(double amount) 
    {
        if (amount > 0) balance += amount;
    }

    double getBalance() const 
    {
        return balance;
    }
};

int main()
{
    Account acc;
    // acc.balance = 1000; // ❌ Not allowed (private)
    acc.deposit(500);      // ✅ Controlled access
    cout << acc.getBalance()<<endl; // ✅ Read-only access

}

/*  g++ -std=c++14 DataEncapsulation.cpp -o DataEncapsulation -pthread */
/* ./DataEncapsulation  */