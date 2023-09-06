/*
-----------------------------------------------MovieStore.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the MovieStore class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    parsingMovies, destructor, parsingCustomer, executeTransactions
 ----------------------------------------------------------------------------------------------
 */
#ifndef MOVIESTORE_H
#define MOVIESTORE_H

#include <string>
#include <iostream>
#include "HashTable.h"
#include "HashNode.h"
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// --------------------- MovieStore Class -----------------------------------------
// used to define MovieStore class, works with HashNode and HashTable class
// --------------------------------------------------------------

class MovieStore
{
    public:
        ~MovieStore();
        void parsingMovies(string fileName);
        void parsingCustomers(string fileName);
        void executeTransactions(string fileName);

    private:
        string fileName;
        HashTable<string, Movie*> movies;
        HashTable<int, Customer*> customers;
};
#endif //MOVIESTORE_H