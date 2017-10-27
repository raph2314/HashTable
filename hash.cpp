//
// Created by Raphael Lopez on 2017-10-05.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "hash.h"

using namespace std;


HashTable::HashTable() {
    for(int i = 0; i < tableSize; i++) {
        hash_table[i] = new item;
        hash_table[i]->name = "empty";
        hash_table[i]->drink = "empty";
        hash_table[i]->next = NULL;
    }
}

void HashTable::AddItem(string name, string drink) {
    int index = Hash(name);

    //Base Case: hash_table at hashed index is vacant
    if(hash_table[index] -> name == "empty"){
        hash_table[index]-> name = name;
        hash_table[index]-> drink = drink;

    }
    //Other Case: hash_table at hashed index is occupied
    else{
        item* Ptr = hash_table[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(Ptr->next != NULL){
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int HashTable::NumberOfItemsInIndex(int index) {
    int count = 0;

    if(hash_table[index]->name == "empty"){
        return count;
    }
    else{
        count++;
        item* Ptr = hash_table[index];
        while(Ptr->next != NULL){
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

void HashTable::PrintTable(){
    //Holds number of elements in each bucket
    int number;

    for(int i = 0; i < tableSize; i++){
        number = NumberOfItemsInIndex(i);
        cout << "--------------------\n";
        cout << "index = " << i << endl;
        cout << hash_table[i]->name << endl;
        cout << hash_table[i]->drink << endl;
        cout << "# of items = " << number << endl;
        cout << "--------------------\n";


    }
}

void HashTable::PrintItemsInIndex(int index) {
    item* Ptr = hash_table[index];

    if(Ptr->name == "empty")
        cout << "index = " << index << " is empty";

    else{
        cout << "index " << index << " contains the following items\n";
        while(Ptr != NULL){
            cout << "--------------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "--------------------\n";
            Ptr = Ptr->next;
        }
    }
}

void HashTable::FindDrink(string name) {
    int index = Hash(name);
    bool foundName = false;
    string drink;

    item* Ptr = hash_table[index];
    while(Ptr != NULL){
        if(Ptr->name == name){
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if(foundName)
        cout << "Favourite drink = " << drink << endl;
    else
        cout << name << "'s info was not found in the Hash Table\n";
}

void HashTable::RemoveItem(string name) {

    int index = Hash(name);

    item* delPtr;
    item* P1;
    item* P2;

    //Case 0 - Bucket is empty
    if(hash_table[index]->name == "empty" && hash_table[index]->drink == "empty"){
        cout << name << " was not found in the hash table\n";

    }

    //Case 1 - Only one item in bucket and that item has matching name
    else if(hash_table[index]->name == name && hash_table[index]->next == NULL){
        hash_table[index]->name = "empty";
        hash_table[index]->drink = "empty";
        cout << name << " was removed from the hash table\n";
    }

    //Case 2 - Match is located in the first item in the bucket, but there are more items in the bucket
    else if(hash_table[index]->name == name && hash_table[index]->next!= NULL){
        delPtr = hash_table[index];
        hash_table[index] = hash_table[index]->next;
        delete delPtr;
        cout << name << " was removed from the hash table\n";
    }

    //Case 3 - Bucket contains items but first item is not a match
    else{
        P1 = hash_table[index]->next;
        P2 = hash_table[index];

        while(P1 != NULL && P1->name != name){
            P2 = P1;
            P1 = P1->next;
        }

        //Case 3.1 - No match
        if(P1 == NULL)
          cout << name << " was not found in the hash table\n";

        //Case 3.2 - Match  is found
        else{
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            delete delPtr;
            cout << name << " was removed from the hash table\n";
        }
    }






}

int HashTable::Hash(string key) {
    int hash = 0;
    int index;

    for(int i = 0; i < key.length(); i++)
        hash +=  ((int)key[i]) * 17;

    index  = hash % tableSize;

    return index;

//    unsigned int Init = 1234564352;
//    unsigned int Magic = 5674356;
//    unsigned int index;
//    for(int i = 0; i < key.length(); i++){
//        index = hash ^ (key[i]); //XOR each byte of input
//        hash = hash * Magic; //Multiply by the magic number
//    }
//    return hash;


}
