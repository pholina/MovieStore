/*
-----------------------------------------------Classic.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Classic's class
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */
 
#include "Classic.h"

// --------------------- Default Constructor -----------------------------------------
//  default constructor for classic class, calls constructor of base class (Movie)
//  and passed in char C to present "Classic"
//  actual constructor takes in data calues to initialize Class object with givem values
//  , also calls base constructor
// --------------------------------------------------------------

Classic::Classic() : Movie('C')
{
}

// --------------------- Classic Constructor -----------------------------------------
//  constructor takes in data calues to initialize Class object with givem values
//  also calls base constructor
// --------------------------------------------------------------

Classic::Classic(int stock, string director, string title, string actor, int month, int year) : Movie('C')
{
    this->stock = stock; //assigns val of passed in parameter to member variable of class object
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
}

// --------------------- setData(int stock, string director, string title, string actor, int month, int year) -----------------------------------------
// used to set data values of Classic obj with passed in values
// --------------------------------------------------------------

void Classic::setData(int stock, string director, string title, string actor, int month, int year)
{
    this->stock = stock; //sets passed in values to class member variables
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
}

// --------------------- getKey() -----------------------------------------
// used to return key for Classic obj, key is string containing 
// month, year, and actor
// --------------------------------------------------------------

string Classic::getKey()
{
    return to_string(this->month) + " " + to_string(this->year) + " " + this->actor; //convert int vals of month, year, and actor to properly formatted string
}

// --------------------- print() -----------------------------------------
// used to print details of Classic obj
// --------------------------------------------------------------

void Classic::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << actor << ", " << month << " " << year << endl; //prints out information about the movie
}

// --------------------- operator<(const Movie& other) -----------------------------------------
// used to compare two Classic objs based on release year, month, and actor.
// returns true if current obh is less than other obj, otherwise false
// --------------------------------------------------------------

bool Classic::operator<(const Movie& other) const
{
    const Classic& otherClassic = dynamic_cast<const Classic&>(other);//casts 'other' Movie obj to reference assuming 'other' is a Classic obj
                                                                        //allows access to attributes of Classic class
    if (year < otherClassic.year) //compares release years of curr Classic obj and other Classic obj
    {
        return true; //if less, return true
    } 
    else if (year == otherClassic.year) //compares if years are equal 
    {
        if (month < otherClassic.month) //compare months
        {
            return true; //if less, return true
        } 
        else if (month == otherClassic.month) //compares if months are equal
        {
            return actor < otherClassic.actor; //return true if actors less than 
        }
    }
    return false; //return false if curr Classic obj is not less than other Classic
}

// --------------------- operator>(const Movie& other) -----------------------------------------
// used to compare two Classic objs based on release year, month, and actor.
//  return true if current obj is greather than other, and false otherwise
// --------------------------------------------------------------

bool Classic::operator>(const Movie& other) const
{
    const Classic& otherClassic = dynamic_cast<const Classic&>(other);//casts 'other' Movie obj to reference assuming 'other' is a Classic obj
                                                                        //allows access to attributes of Classic class
    if (year > otherClassic.year) //compares release years of curr Classic obj and other Classic obj 
    {
        return true; //if greater, return true
    } 
    else if (year == otherClassic.year) //compares if years are equal  
    {
        if (month > otherClassic.month) //compare months 
        {
            return true; //if greater, return true
        } 
        else if (month == otherClassic.month) //compares if months are equal 
        {
            return actor > otherClassic.actor; //return true if actors greater than 
        }
    }
    return false; //return false if curr Classic obj is not greater than other Classic
}