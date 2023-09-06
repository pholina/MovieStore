/*
-----------------------------------------------MovieStore.cpp------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is used for the actual implementation for the MovieStore class 
    -------------------------------------------------------------------------------------------
    parsingMovies, destructor, parsingCustomer, executeTransactions
 ----------------------------------------------------------------------------------------------
 */

#include "MovieStore.h"

// --------------------- parsingMovies(string fileName) -----------------------------------------
// reads movie data from a file nd stores it in movies data structure, reads movie type, stock, director, title
// and depending on movie type, other info like actor, month, and yr 
// --------------------------------------------------------------

void MovieStore::parsingMovies(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    if (!myfile)
    {
        cout << "File not open!" << endl;
    }

    char movieType;
    string director, title, actor;
    int stock, month, year;
    string line;
    while (getline(myfile, line))
    {
        actor = "";
        string segment;
        istringstream iss(line);

        getline(iss, segment, ',');
        movieType = segment[0];

        getline(iss, segment, ',');
        stock = stoi(segment);

        getline(iss, segment, ',');
        director = segment.substr(1);

        getline(iss, segment, ',');
        title = segment.substr(1);

        switch(movieType) 
        {
            case 'C': 
            {
                getline(iss, segment, ' ');
                getline(iss, segment, ' ');
                actor += segment;
                getline(iss, segment, ' ');
                actor += " " + segment;

                getline(iss, segment, ' ');
                month = stoi(segment);

                getline(iss, segment);
                year = stoi(segment);

                Classic* movie = new Classic();
                movie->setData(stock, director, title, actor, month, year);
                movies.insert(movie->getKey(), movie);
                break;
            }
            case 'F': 
            {
                getline(iss, segment, ' ');
                getline(iss, segment);
                year = stoi(segment);

                Comedy* movie = new Comedy();
                movie->setData(stock, director, title, year);
                movies.insert(movie->getKey(), movie);
                break;
            }
            case 'D': 
            {
                getline(iss, segment, ' ');
                getline(iss, segment);
                year = stoi(segment);

                Drama* movie = new Drama();
                movie->setData(stock, director, title, year);
                movies.insert(movie->getKey(), movie);
                break;
            }
            default:
                cout << "Unknown movie type: " << movieType << ", " << director << ", " << title << endl;
        }
    }
    myfile.close();
}

// --------------------- ~MovieStore()  -----------------------------------------
// destructor for 'MovieStore' class, deletes all movies and customers stored
// in the movie and customers data structures
// --------------------------------------------------------------

MovieStore::~MovieStore() 
{
    auto allMovies = movies.getAllValues();
    for(auto& movie : allMovies)
    {
        delete movie;
    }
    auto allCustomers = customers.getAllValues();
    for(auto& customer : allCustomers)
    {
        delete customer;
    }
}

// --------------------- parsingCustomers(string fileName)  -----------------------------------------
// reads customer data from file and stores it in customer data structure, reads customer id, last name, and first name
// --------------------------------------------------------------

void MovieStore::parsingCustomers(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    if (!myfile)
    {
        cout << "File not open!" << endl;
    }

    int id;
    string firstName,lastName;
    string line;
    while (getline(myfile,line))
    {
        istringstream iss(line);
        iss >> id >> lastName >> firstName;
        Customer* CC = new Customer();
        CC->setData(id, lastName, firstName);
        customers.insert(CC->getKey(), CC);
    }
    myfile.close();
}

// --------------------- executeTransactions(string fileName) -----------------------------------------
// reads transaction data from file and executes transactions, reads transaction type,, and depending on
// type, additional info like customer id, media type, movie type, and other moviespecific dta
// --------------------------------------------------------------

void MovieStore::executeTransactions(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    if (!myfile)
    {
        cout << "File not open!" << endl;
    }

    char transactionType, mediaType, movieType;
    string director, title, actor, keyString;
    int id, month, year;
    string line;
    while (getline(myfile, line))
    {
        string segment;
        istringstream iss(line);
        Movie *retrievedMovie;
        Customer *retrievedCustomer;
        Transaction T;
        keyString = "";

        iss >> transactionType;
        switch(transactionType) 
        {
            case 'B': 
            case 'R': 
            {
                iss >> id >> mediaType >> movieType;
                if (!customers.retrieve(id, retrievedCustomer))
                {
                    cout << "Customer ID " << id << " Does Not Exist!" << endl;
                    continue;
                }

                if (movieType == 'F')
                {
                    getline(iss, segment, ',');
                    title = segment.substr(1);
                    iss >> year;
                    keyString = title + " " + to_string(year);
                    T.setForComedy(transactionType, id, mediaType, movieType, title, year);
                }
                else if (movieType == 'C')
                {
                    iss >> month >> year;
                    getline(iss, segment, '\n');
                    actor = segment.substr(1);
                    keyString = to_string(month) + " " +  to_string(year) + " " + actor;
                    if(!keyString.empty() && keyString[keyString.size()-1] == '\r')
                    {
                        keyString.erase(keyString.size()-1);
                    }
                    T.setForClassics(transactionType, id, mediaType, movieType, month, year, actor);
                }
                else if (movieType == 'D')
                {
                    getline(iss, segment, ',');
                    director = segment.substr(1);
                    getline(iss, segment, ',');
                    title = segment.substr(1);
                    keyString = director + " " + title;
                    T.setForDramas(transactionType, id, mediaType, movieType, director, title);
                }
                else
                {
                    getline(iss, segment, '\n');
                    cout << "Movie type " << movieType << " is not available for" << segment << endl;
                    continue;
                }

                if (mediaType != 'D')
                {
                    cout << "Media type " << mediaType << " is not available for " << keyString << endl;
                    continue;
                }
                
                if (!movies.retrieve(keyString, retrievedMovie))
                {
                    cout << keyString << " Does not exist!" << endl;
                    continue;
                }
                else
                {
                    if (transactionType == 'B')
                    {
                        if (retrievedCustomer->multipleBorrowCheck(T)) 
                        {
                            cout << "Customer " << retrievedCustomer->getID() << " has check out an item muptiple times (Or have not returned): " << keyString << endl;
                            retrievedCustomer->AddTransaction(T);
                            continue;
                        }
    
                        if(!retrievedMovie->decreaseStock(1))
                        {
                            cout << keyString << " does not have enough stock!" << endl;
                        }
                        retrievedCustomer->AddTransaction(T);
                    }
                    else if (transactionType == 'R')
                    {
                        retrievedMovie->increaseStock(1);
                        retrievedCustomer->AddTransaction(T);
                    }
                }
                break;
            }
            case 'I': {
                cout << endl;
                cout << "Movie Inventory: " << endl;
                auto allMovies = movies.getAllValues();
                vector<Comedy*> comedyMovies;
                vector<Drama*> dramaMovies;
                vector<Classic*> classicMovies;
            
                for(auto& movie : allMovies) {
                    if(movie->checkMovieType() == 'C')
                    {
                        classicMovies.push_back(dynamic_cast<Classic*>(movie)); 
                    }
                    else if(movie->checkMovieType() == 'F')
                    {
                        comedyMovies.push_back(dynamic_cast<Comedy*>(movie));
                    }
                    else if(movie->checkMovieType() == 'D')
                    {
                        dramaMovies.push_back(dynamic_cast<Drama*>(movie));
                    }
                }

                // Only sort and print if the vector is not empty
                if (!comedyMovies.empty()) {
                    sort(comedyMovies.begin(), comedyMovies.end(), [](Comedy* a, Comedy* b) { return *a < *b; });
                    for(auto& movie : comedyMovies) 
                    {
                        movie->print();
                    }
                }
                
                if (!dramaMovies.empty()) {
                    sort(dramaMovies.begin(), dramaMovies.end(), [](Drama* a, Drama* b) { return *a < *b; });
                    for(auto& movie : dramaMovies) 
                    {
                        movie->print();
                    }
                }
                
                if (!classicMovies.empty()) {
                    sort(classicMovies.begin(), classicMovies.end(), [](Classic* a, Classic* b) { return *a < *b; });
                    for(auto& movie : classicMovies) 
                    {
                        movie->print();
                    }
                }
                cout << endl;
                break;
            }
            case 'H': 
            {
                iss >> id;
                if (customers.retrieve(id, retrievedCustomer)) 
                {
                    cout << "History for ID " << id << endl;
                    retrievedCustomer->PrintTransactionHistory();
                    cout << endl;
                } 
                else 
                {
                    cout << "ID " << id << " is not valid! Cannot retrieve transactions!" << endl;
                }
                break;
            }
            default:
                cout << "Unknown transaction type " << transactionType << endl;
        }
    }
    myfile.close();
}
