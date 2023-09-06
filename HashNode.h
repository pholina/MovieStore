/*
-----------------------------------------------HashNode.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the HashNode class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    getters and setters for key, value, and next
 ----------------------------------------------------------------------------------------------
 */
#ifndef HASHNODE_H
#define HASHNODE_H

// --------------------- HashNode Class -----------------------------------------
// used to define HashNode class, works with HashTable
// --------------------------------------------------------------


template <typename KeyT, typename ValT>
class HashNode {
    private:
        KeyT key;
        ValT value;
        HashNode* next;

    public:
        HashNode(const KeyT& k, const ValT& v) : key(k), value(v), next(nullptr) {}

    // --------------------- getters -----------------------------------------
    // used to return value of key, value, and next node
    // --------------------------------------------------------------    

        KeyT getKey() const 
        {
            return key;
        }

        ValT getValue() const 
        {
            return value;
        }

        HashNode* getNext() const 
        {
            return next;
        }
// --------------------- setters -----------------------------------------
// used to set value and the next node
// --------------------------------------------------------------

        void setValue(const ValT& v) 
        {
            value = v;
        }

        void setNext(HashNode* n) 
        {
            next = n;
        }
};

#endif // HASHNODE_H

