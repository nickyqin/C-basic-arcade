//
//  main.cpp
//  test
//
//  Created by Nicky Qin on 5/15/22.
//


#include "ticTacToe.hpp"
#include "hangman.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int arcadeSession();


class Account {
public:
    int accountNumber;
    string accountName;
    string accountType;
    
    Account(string name, string type);
    
    int getBalance();
    int deposit(int amount);
    int withdraw(int amount);
    
private:
    int balance = 0;
    static int nextAccountNumber;
};

// **** STATIC VARIABLES **** //
int Account::nextAccountNumber = 1;


// **** ACCOUNT CONSTRUCTOR **** //
Account::Account(string name, string type) {
    accountName = name;
    accountType = type;
    accountNumber = Account::nextAccountNumber;
    Account::nextAccountNumber++;
}


// **** ACCOUNT METHODS **** //
int Account::getBalance() {
    return balance;
}

int Account::deposit(int amount) {
    cout << "Old balance: " << balance << "\n";
    balance += amount;
    cout << "New balance: " << balance << "\n";
    
    return 0;
}

int Account::withdraw(int amount) {
    if (amount > balance) {
        cout << "Insufficient funds!\n";
        return 1;
    } else {
        cout << "Old balance: " << balance << "\n";
        balance -= amount;
        cout << "New balance: " << balance << "\n";
    }
    return 0;
}


// **** ACCOUNT UI **** //
void accountSession() {
    int status = 0;
    
    while (status == 0) {
        string input;
        
        cout << "Bank Menu\n"
        << "1: Create Account\n";
        
        cin >> input;
        
        // Create Account
        if (input == "1") {
            string accountName, accountType;
            cout << "Account name: ";
            cin >> accountName;
            cout << "Account type: ";
            cin >> accountType;
            
            Account test(accountName, accountType);
            
            cout << test.accountName << " " << test.getBalance() << "\n";
        }
        status = 1;
    }
}



int main()
{
    accountSession();
    
    return 0;
}









int arcadeSession()
{
    // to run in main:
    //    int arcadeStatus = 0;
    //    while (arcadeStatus == 0)
    //    {
    //        arcadeStatus = arcadeSession();
    //    }
    
    
    string gameNum;
    
    cout << "Choose your game: \n"
         << "1: Tic Tac Toe\n"
         << "2: Hangman\n\n"
         << "O to exit\n"
         << "Choice: ";
    cin >> gameNum;
    
    if (gameNum == "0")
    {
        return 1;
    }
    else if (gameNum == "1")
    {
        ticTacToe();
    }
    else if (gameNum == "2")
    {
        hangmanSession();
    }
    else
    {
        cout << "Invalid input!\n";
    }
    
    return 0;
}
