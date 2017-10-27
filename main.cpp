#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "hash.h"
using namespace std;

int main(int argc, char** argv) {

    HashTable Hashy;
    string name = "";

    Hashy.AddItem("Paul", "Locha");
    Hashy.AddItem("Kim", "Iced Mocha");
    Hashy.AddItem("Emma", "Strawberry Smoothie");
    Hashy.AddItem("Annie", "Hot Chocolate");
    Hashy.AddItem("Sarah", "Passion Tes");
    Hashy.AddItem("Pepper", "Caramel Mocha");
    Hashy.AddItem("Mike", "Chai Tea");
    Hashy.AddItem("Steve", "Apple Cider");
    Hashy.AddItem("Bill", "Root Beer");
    Hashy.AddItem("Marie", "Skinny Latte");
    Hashy.AddItem("Susan", "Water");
    Hashy.AddItem("Joe", "Green Tea");


    Hashy.PrintItemsInIndex(2);

    //For Testing
    while(name != "exit"){
        cout << "Remove: ";
        cin >> name;
        if(name != "exit")
            Hashy.RemoveItem(name);
    }
    Hashy.PrintItemsInIndex(2);

    return 0;
}