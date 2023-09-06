/*
-----------------------------------------------Drama.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Drama class
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */
 
#include "Drama.h"

// --------------------- Drama Constructor -----------------------------------------
// default constructor, initializes Drama obj with default values, sets movie type to D for "drama"
// --------------------------------------------------------------

Drama::Drama() : Movie('D')
{
}

// --------------------- Customer Constructor -----------------------------------------
// constructor initializes Customer obj with passed in values
// --------------------------------------------------------------

Drama::Drama(int stock, string director, string title, int year) : Movie('D')
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

// --------------------- setData(int stock, string director, string title, int year) -----------------------------------------
// sets the data members of a Drama obj
// --------------------------------------------------------------

void Drama::setData(int stock, string director, string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

// --------------------- getKey()-----------------------------------------
// // gets a unique key for the Drama obj and then it returns a string that combines
// the director and title for the movie
// --------------------------------------------------------------

string Drama::getKey()
{
    return this->director + " " + this->title;
}

// --------------------- print() -----------------------------------------
// prints the details of the Drama obj to the console
// --------------------------------------------------------------

void Drama::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// --------------------- operator<(const Movie& other) -----------------------------------------
// overloads less than operator for Drama objs, makes comparisons about director and movie title
// --------------------------------------------------------------

bool Drama::operator<(const Movie& other) const
{
    const Drama& otherDrama = dynamic_cast<const Drama&>(other);
    if (director < otherDrama.director) 
    {
        return true;
    } 
    else if (director == otherDrama.director) 
    {
        return title < otherDrama.title;
    } 
    else 
    {
        return false;
    }
}

// --------------------- operator>(const Movie& other) -----------------------------------------
// overloads greater than operator for Drama objs, makes comparisons about director and movie title
// --------------------------------------------------------------

bool Drama::operator>(const Movie& other) const
{
    const Drama& otherDrama = dynamic_cast<const Drama&>(other);
    if (director > otherDrama.director) 
    {
        return true;
    } 
    else if (director == otherDrama.director) 
    {
        return title > otherDrama.title;
    } 
    else 
    {
        return false;
    }
}