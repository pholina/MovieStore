/*
-----------------------------------------------Customer.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the Customer class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, display and add transactions, check for multiple borrows
 ----------------------------------------------------------------------------------------------
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <list>
#include "Transaction.h"
using namespace std;

// --------------------- Customer Class -----------------------------------------
// used to define Customer class, works with Transaction class
// --------------------------------------------------------------

class Customer
{
    public:
        Customer();
        void AddTransaction(Transaction t);
        void PrintTransactionHistory();
        int getKey();
        void setData(int, string, string);
        int getID();
        bool multipleBorrowCheck(const Transaction&);

    private:
        int customerID;
        string firstName;
        string lastName;
        list<Transaction> transactionHistory;
};
#endif