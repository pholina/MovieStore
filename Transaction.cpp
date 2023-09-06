/*
-----------------------------------------------Transaction.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Transaction class  
    -------------------------------------------------------------------------------------------
    getters, setters, = operator
 ----------------------------------------------------------------------------------------------
 */

#include "Transaction.h"

// --------------------- Transaction() -----------------------------------------
// default constructor, initializes all member variables to default value
// --------------------------------------------------------------

Transaction::Transaction()
{
    this->transactionType =' ';
    this->customerID = 0;
    this->movieType = ' ';
    this->mediaType = ' ';
    this->movieTitle = "";
    this->movieDirector = "";
    this->movieActor = "";
    this->movieYear = 0;
    this->movieMonth = 0;

}

// --------------------- getTransactionType() -----------------------------------------
// getter func. for transaction type
// --------------------------------------------------------------

char Transaction::getTransactionType() const
{
    return transactionType;
}

// --------------------- getCustomerID() -----------------------------------------
// getter func. for customer ID
// --------------------------------------------------------------

int Transaction::getCustomerID() const
{
    return customerID;
}

// --------------------- getMediaType() -----------------------------------------
// getter func. for media type
// --------------------------------------------------------------

char Transaction::getMediaType() const
{
    return mediaType;
}

// --------------------- getMovieType() -----------------------------------------
// getter func. for movie type
// --------------------------------------------------------------

char Transaction::getMovieType() const
{
    return movieType;
}

// --------------------- getMovieTitle() -----------------------------------------
// getter func. for movie title
// --------------------------------------------------------------

string Transaction::getMovieTitle() const
{
    return movieTitle;
}

// --------------------- getMovieDirector() -----------------------------------------
// getter func. for mvoie director
// --------------------------------------------------------------

string Transaction::getMovieDirector() const 
{
    return movieDirector;
}

// --------------------- getMovieActor()  -----------------------------------------
// getter func. for movie actor
// --------------------------------------------------------------

string Transaction::getMovieActor() const 
{
    return movieActor;
}

// --------------------- getMovieYear() -----------------------------------------
// getter func. for movie yr
// --------------------------------------------------------------

int Transaction::getMovieYear() const 
{
    return movieYear;
}

// --------------------- getMovieMonth() -----------------------------------------
// getter func. for movie month
// --------------------------------------------------------------

int Transaction::getMovieMonth() const 
{
    return movieMonth;
}

// --------------------- setForComedy(char transactionType, int ID, char mediaType, char movieType, string title, int year) -----------------------------------------
// setter func. for Comedy genre, sets transaction type, customer ID, media type, title, year
// --------------------------------------------------------------

void Transaction::setForComedy(char transactionType, int ID, char mediaType, char movieType, string title, int year)
{
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieTitle = title;
    this->movieYear = year;

}

// --------------------- setForDramas(char transactionType, int ID, char mediaType, char movieType, string director, string title) -----------------------------------------
// setter func. for Drama genre, sets transaction type, customer ID, media type, movie type, director, and title
// --------------------------------------------------------------

void Transaction::setForDramas(char transactionType, int ID, char mediaType, char movieType, string director, string title)
{
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieDirector = director;
    this->movieTitle = title;
}

// --------------------- setForClassics(char transactionType, int ID, char mediaType, char movieType, int month, int year, string actor) -----------------------------------------
// setter func for Classics genre, sets transaction type, customer ID, media type, movie type, month, yr, and actopr
// --------------------------------------------------------------

void Transaction::setForClassics(char transactionType, int ID, char mediaType, char movieType, int month, int year, string actor)
{
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieMonth = month;
    this->movieYear = year;
    this->movieActor = actor;
}

// --------------------- operator==(const Transaction &other) -----------------------------------------
// overloaded equality operator, returns true if all member variables of callinbg obj and the passed obj are equal
// --------------------------------------------------------------

bool Transaction::operator==(const Transaction &other) const 
{
    return 
        movieType == other.movieType &&
        mediaType == other.mediaType &&
        movieTitle == other.movieTitle &&
        movieDirector == other.movieDirector &&
        movieActor == other.movieActor &&
        movieYear == other.movieYear &&
        movieMonth == other.movieMonth;
}