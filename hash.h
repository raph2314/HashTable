//
// Created by Raphael Lopez on 2017-10-05.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef HASHTABLE_HASH_H
#define HASHTABLE_HASH_H

class HashTable{

private:
    static const int tableSize = 4;

    struct item{
        string name;
        string drink;
        item* next;
    };

    item* hash_table[tableSize];

public:
    HashTable();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);

};


#endif //HASHTABLE_HASH_H
