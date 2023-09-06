/*
-----------------------------------------------Movie.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the Movie class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, increase/decrease/check stock, check movieType, set data, print >/<
 ----------------------------------------------------------------------------------------------
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// --------------------- Movie Class -----------------------------------------
// used to define Movie class, works with MovieStore class
// --------------------------------------------------------------

class Movie
{
    public:
        Movie(char movieType);
        virtual bool increaseStock(int);
        virtual bool decreaseStock(int);
        virtual int checkStock();
        virtual char checkMovieType();
        virtual void setData(string, string, int, int);
        virtual void print();
        virtual bool operator<(const Movie& other) const = 0;
        virtual bool operator>(const Movie& other) const = 0;
        
    protected:
        string title, director, actor;
        int stock, month, year;
        char mediaType, movieType;
};
#endif //MOVIE_H