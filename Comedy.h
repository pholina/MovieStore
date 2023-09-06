/*
-----------------------------------------------Comedy.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the Comedy class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */

#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "Movie.h"
using namespace std;

// --------------------- Comedy Class -----------------------------------------
// used to define Comedy class, derived from Movie class but adds extra functions that are 
//  unique to Comedy class 
// --------------------------------------------------------------

class Comedy : public Movie 
{
    public:
        Comedy();
        Comedy(int stock, string director, string title, int year);
        //~
        void setData(int, string, string, int);
        string getKey();
        void print();
        bool operator<(const Movie& other) const override;
        bool operator>(const Movie& other) const override;
//protected:
};
#endif //COMEDY_H