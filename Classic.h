/*
-----------------------------------------------Classic.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the Classic class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */

#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "Movie.h"
using namespace std;


// --------------------- Classic Class -----------------------------------------
// used to define Classic class, derived from Movie class but adds extra functions that are 
//  unique to Classic class 
// --------------------------------------------------------------

class Classic:public Movie //Classic class inherits from Movie
{
    public:
        Classic();
        Classic(int stock, string director, string title, string actor, int month, int year);
        void setData(int, string, string, string, int, int);
        string getKey();
        void print();
        bool operator<(const Movie& other) const override;
        bool operator>(const Movie& other) const override;
};
#endif //CLASSIC_H