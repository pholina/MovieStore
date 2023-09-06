/*
-----------------------------------------------Movie.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the Movie class 
    -------------------------------------------------------------------------------------------
    constructor, increase/decrease/check stock, check movieType, set data, print >/<
 ----------------------------------------------------------------------------------------------
 */

#include "Movie.h"

// --------------------- Movie Constructor -----------------------------------------
// constructs movie ob with specific movie type, all the other attributes are initialized to default values 
// --------------------------------------------------------------

Movie::Movie(char movie)
{
    this->title = "";
    this->director = "";
    this->stock = 0;
    this->year = 0;
    this->actor = "";
    this->month = 0;
    this->mediaType = 'D';
    this->movieType = movie;
}

// --------------------- increaseStock(int n) -----------------------------------------
// increase stock of movie by specified amount, returns true after successful operation
// --------------------------------------------------------------

bool Movie::increaseStock(int n)
{
    this->stock += n;
    return true;
}

// --------------------- decreaseStock(int n) -----------------------------------------
// decreases stock of movie by specified amt, returns false if operation would be negative stock
// true otherwise
// --------------------------------------------------------------

bool Movie::decreaseStock(int n)
{
    if (this->stock - n < 0)
    {
        return false;
    }
    this->stock -= n;
    return true;
}

// --------------------- checkStock() -----------------------------------------
// returns current stock of movie
// --------------------------------------------------------------

int Movie::checkStock()
{
    return this->stock;
}

// --------------------- checkMovieType() -----------------------------------------
// returns type of the movie
// --------------------------------------------------------------

char Movie::checkMovieType()
{
    return this->movieType;
}

// --------------------- setData(string title, string director, int stock, int year) -----------------------------------------
// sets title, director, stock, and yr of movie
// --------------------------------------------------------------

void Movie::setData(string title, string director, int stock, int year)
{
    this->title = title;
    this->director = director;
    this->stock = stock;
    this->year = year;
}

// --------------------- print() -----------------------------------------
// prints title, director, stock of movie
// --------------------------------------------------------------

void Movie::print()
{
    cout << "Title: " << stock <<  title << ", Director: " << director << ", Stock: " << endl;
}

// --------------------- operator<(const Movie& other) -----------------------------------------
// overloads the '<' operator to compare two 'Movie' objs, returns true if title of movie is lexicographically 
// less than the others, or if titles are equal, then movie's year is less than others
// --------------------------------------------------------------

bool Movie::operator<(const Movie& other) const
{
    if (title < other.title) 
    {
        return true;
    } 
    else if (title == other.title) 
    {
        return year < other.year;
    } 
    else 
    {
        return false;
    }
}

// --------------------- operator>(const Movie& other) -----------------------------------------
// overloads '>' operator to compare two Movie objs, returns true if title of movie is lexicographically greater than
// others, or if titles areequal to this movie's year is greater thn others
// --------------------------------------------------------------

bool Movie::operator>(const Movie& other) const
{
    if (title > other.title) 
    {
        return true;
    } 
    else if (title == other.title) 
    {
        return year > other.year;
    } 
    else 
    {
        return false;
    }
}