#pragma once
#include "DictionaryMenu.h"
#include "SearchMetod.h"
#include "HashMenu.h"
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    HashTable* hashTable = CreateHashTable();
    Dictionary* dictionary = CreateDictionary();

    while (true)
    {
        cout << "Main menu:" << endl;
        cout << "1 - Dictionary" << endl;
        cout << "2 - Hash Table" << endl;
        cout << "0 - stop" << endl << endl;

        int command = GetIntInput("Your input: ");
        cout << endl;
        switch (command)
        {
            case 1:
            {
                DictionaryMenu(dictionary);
                break;
            }
            
            case 2:
            {
                HashTableMenu(hashTable);
                break;
            }
            
            case 0:
            {
                DeleteHashTable(hashTable);
                DeleteDictionary(dictionary);
                return 0;
            }
            
            default:
            {
                cout << "Invalid choice! Try again." << endl;
            }
        }
    }
}