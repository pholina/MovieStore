/*
-----------------------------------------------HashTable.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - This file is the framework of the HashTable class, it is used to declare methods used
    -------------------------------------------------------------------------------------------
    constructor, destructor, getter, insert, retrieve, remove
 ----------------------------------------------------------------------------------------------
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashNode.h"
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// --------------------- HashTable Class -----------------------------------------
// used to define HashTable class, works with HashNode and used to operate MovieStore class
// --------------------------------------------------------------


template<typename KeyT, typename ValT>

class HashTable 
{
    private:
        static const int SIZE = 100;
        HashNode<KeyT, ValT>* hashTable[SIZE];
        std::hash<KeyT> key_hash;  // hash function for KeyT
    public:
        HashTable() 
        {
            for (int i = 0; i < SIZE; i++) 
            {
                hashTable[i] = nullptr;
            }
        }

    // ---------------------  ~HashTable()  -----------------------------------------
    // destructor deletes all HashNodes nd sets their pointers in the hashTable array to nullptr 
    // --------------------------------------------------------------

        ~HashTable() 
        {
            for (int i = 0; i < SIZE; i++) 
            {
                HashNode<KeyT, ValT>* prevNode = hashTable[i];
                while (prevNode) 
                {
                    HashNode<KeyT, ValT>* temp = prevNode;
                    prevNode = prevNode->getNext();
                    delete temp;
                }
                hashTable[i] = nullptr;
            }
        }

    // --------------------- getAllValues()  -----------------------------------------
    // method returns a vector of all values in HashTable
    // --------------------------------------------------------------

        std::vector<ValT> getAllValues() 
        {
            std::vector<ValT> values;
            for (int i = 0; i < SIZE; i++) 
            {
                HashNode<KeyT, ValT>* currNode = hashTable[i];
                while (currNode) 
                {
                    values.push_back(currNode->getValue());
                    currNode = currNode->getNext();
                }
            }
            return values;
        }

    // --------------------- insert(const KeyT& key, const ValT& value) -----------------------------------------
    // inserts new key value pair into HashTable... if key already exists, it updates value
    // --------------------------------------------------------------

        void insert(const KeyT& key, const ValT& value) 
        {
            unsigned long hashValue = key_hash(key) % SIZE;
            HashNode<KeyT, ValT>* prevNode = nullptr;
            HashNode<KeyT, ValT>* currNode = hashTable[hashValue];
            
            while (currNode && currNode->getKey() != key) 
            {
                prevNode = currNode;
                currNode = currNode->getNext();
            }
            if (!currNode) 
            {
                HashNode<KeyT, ValT>* newNode = new HashNode<KeyT, ValT>(key, value);
                if (!prevNode) 
                {
                    hashTable[hashValue] = newNode;
                } 
                else 
                {
                    prevNode->setNext(newNode);
                }
            } 
            else 
            {
                currNode->setValue(value);
            }
        }

    // --------------------- retrieve(const KeyT& key, ValT& value) -----------------------------------------
    // retrives value associated w/ given key in HashTable, if key found, method returns true, sets value perameter to associated value
    //  if key not found, method returns false
    // --------------------------------------------------------------

        bool retrieve(const KeyT& key, ValT& value) 
        {
            unsigned long hashValue = key_hash(key) % SIZE;
            HashNode<KeyT, ValT>* prevNode = hashTable[hashValue];
            while (prevNode) 
            {
                if (prevNode->getKey() == key) 
                {
                    value = prevNode->getValue();
                    return true;
                }
                prevNode = prevNode->getNext();
            }
            return false;
        }

    // --------------------- remove(const KeyT& key) -----------------------------------------
    // removes key value pair from HashTable, if key is not found, method does nothing
    // --------------------------------------------------------------

        void remove(const KeyT& key) 
        {
            unsigned long hashValue = key_hash(key) % SIZE;
            HashNode<KeyT, ValT>* prevNode = nullptr;
            HashNode<KeyT, ValT>* currNode = hashTable[hashValue];
            while (currNode && currNode->getKey() != key) 
            {
                prevNode = currNode;
                currNode = currNode->getNext();
            }
            if (!currNode) 
            {
                return;  // Key not found, do nothing
            }
            if (!prevNode) 
            {
                hashTable[hashValue] = currNode->getNext();
            } 
            else 
            {
                prevNode->setNext(currNode->getNext());
            }
            delete currNode;
        }
};

#endif // HASHTABLE_H



