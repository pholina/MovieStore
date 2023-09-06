/*
-----------------------------------------------Customer.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Customer class
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, display and add transactions, check for multiple borrows
 ----------------------------------------------------------------------------------------------
 */

#include "Customer.h"
#include "Transaction.h"
#include <iostream>
#include <list>

using namespace std;

// --------------------- Customer Constructor -----------------------------------------
// constructor for 'Customer' class, initializes customerID to  nd names to empty strings 
// --------------------------------------------------------------

Customer::Customer()
{
    this->customerID = 0;
    this->lastName = "";
    this->firstName = "";
}

// --------------------- AddTransaction(Transaction t) -----------------------------------------
// adds transaction to customer's transaction history
// --------------------------------------------------------------

void Customer::AddTransaction(Transaction t)
{
    transactionHistory.push_back(t);
}

// --------------------- setData(int ID, string last, string first) -----------------------------------------
// sets custoemr's ID and names
// --------------------------------------------------------------

void Customer::setData(int ID, string last, string first)
{
    this->customerID = ID;
    this->lastName = last;
    this->firstName = first;
}

// --------------------- PrintTransactionHistory()  -----------------------------------------
// prints the customer's transaction history in reverse order, with recent being first
// --------------------------------------------------------------

void Customer::PrintTransactionHistory() 
{
    for(auto i = transactionHistory.rbegin(); i != transactionHistory.rend(); i++) 
    {
        const Transaction &transaction = *i;
        cout << transaction.getTransactionType() << " ";
        cout << transaction.getCustomerID() << " ";
        cout << transaction.getMediaType() << " ";
        cout << transaction.getMovieType() << " ";
        
        switch (transaction.getMovieType()){
            case 'C':
                cout << transaction.getMovieMonth() << " ";
                cout << transaction.getMovieYear() << " ";
                cout << transaction.getMovieActor() << endl;
                break;
            case 'F':
                cout << transaction.getMovieTitle() << ", ";
                cout << transaction.getMovieYear() << endl;
                break;
            case 'D':
                cout << transaction.getMovieDirector() << ", ";
                cout << transaction.getMovieTitle() << ", " << endl;
                break;
            default:
                cout << "Invalid movie type" << endl;
        }
    }
}

// --------------------- getID() -----------------------------------------
// returns customer's ID
// --------------------------------------------------------------

int Customer::getID()
{
    return this->customerID;
}

// --------------------- getKey() -----------------------------------------
// returns customer's ID as the key
// --------------------------------------------------------------

int Customer::getKey()
{
    return this->customerID;
}

// --------------------- multipleBorrowCheck(const Transaction& T) -----------------------------------------
// checks if customer has borrowed a movie more times than they have returned
// --------------------------------------------------------------

bool Customer::multipleBorrowCheck(const Transaction& T) 
{
    int borrowCount = 0;
    int returnCount = 0;
    
    for (const auto& transaction : transactionHistory) 
    {
        if (transaction == T) 
        {
            if (transaction.getTransactionType() == 'B') 
            {
                borrowCount++;
            }
            else if (transaction.getTransactionType() == 'R') 
            {
                returnCount++;
            }
        }
    }
    
    return borrowCount > returnCount;
}