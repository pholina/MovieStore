/*
-----------------------------------------------Comedy.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Comedy's class
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */

#include "Comedy.h"


// --------------------- Default Constructor -----------------------------------------
// default constructor, initializes Comedy obj with default values, sets movie type to F for "funny"
// --------------------------------------------------------------

Comedy::Comedy():Movie('F')
{
}

// --------------------- Comedy Constructor -----------------------------------------
// constructor initializes comdedy obj with passed in values
// --------------------------------------------------------------

Comedy::Comedy(int stock, string director, string title, int year):Movie('F')
{
    this->stock = stock; //assigns value passed in as parameter to member variable of Comedy
    this->director = director;
    this->title = title;
    this->year = year;
}


// --------------------- setData(int stock, string director, string title, int year)-----------------------------------------
// sets the data members of a Comedy obj
// --------------------------------------------------------------


void Comedy::setData(int stock, string director, string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}


// --------------------- getKey() -----------------------------------------
// gets a unique key for the Comedy obj and then it returns a string that combines
// the title and year for the movie
// --------------------------------------------------------------

string Comedy::getKey()
{
    return this->title + " " + to_string(this->year);
}


// --------------------- print() -----------------------------------------
// prints the details of the 'Comedy' obj to the console
// --------------------------------------------------------------

void Comedy::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}


// --------------------- operator<(const Movie& other)-----------------------------------------
// overloads less than operator for comedy objs, compares title and year 
// --------------------------------------------------------------

bool Comedy::operator<(const Movie& other) const
{
    const Comedy& otherComedy = dynamic_cast<const Comedy&>(other);
    if (title < otherComedy.title) 
    {
        return true;
    } else if (title == otherComedy.title) {
        return year < otherComedy.year;
    } else {
        return false;
    }
}

// --------------------- operator>(const Movie& other) -----------------------------------------
// overloads the greater than operator for the 'Comedy' obj; compares title and year
// --------------------------------------------------------------

bool Comedy::operator>(const Movie& other) const
{
    const Comedy& otherComedy = dynamic_cast<const Comedy&>(other); //hello
    if (title > otherComedy.title) 
    {
        return true;
    } else if (title == otherComedy.title) 
    {
        return year > otherComedy.year;
    } else 
    {
        return false;
    }
}