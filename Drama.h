/*
-----------------------------------------------Drama.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the Drama class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, getters, setters, print, and >/< operators
 ----------------------------------------------------------------------------------------------
 */

#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "Movie.h"
using namespace std;

// --------------------- Drama Class -----------------------------------------
// used to define Drama class, derived from Movie class but adds extra functions that are 
//  unique to Drama class 
// --------------------------------------------------------------


class Drama : public Movie 
{
    public:
        Drama();
        Drama(int stock, string director, string title, int year);
        void setData(int, string, string, int);
        string getKey();
        void print();
        bool operator<(const Movie& other) const override;
        bool operator>(const Movie& other) const override;
        
    protected:
};
#endif //DRAMA_H