/*
-----------------------------------------------Test.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for testing of the Automated System Program
    -------------------------------------------------------------------------------------------
    parse and execute
 ----------------------------------------------------------------------------------------------
 */
#include <iostream>
#include "MovieStore.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Transaction.h"
#include "Customer.h"
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "HashNode.h"
using namespace std;

// --------------------- Main Class -----------------------------------------
// Used to test attributes of MovieStore which is connected to all 
//  other files for Automated Tracking System Prog
// --------------------------------------------------------------

int main()
{
    MovieStore Store;
    Store.parsingMovies("data4movies.txt"); //test parsing movies using data file
    Store.parsingCustomers("data4customers.txt"); //test going through customer commands
    Store.executeTransactions("data4commands.txt"); //test transactions
}