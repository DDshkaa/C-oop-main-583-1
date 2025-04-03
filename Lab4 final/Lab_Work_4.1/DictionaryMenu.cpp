#include "DictionaryMenu.h"
#include "SearchMetod.h"
#include <iostream>
#include <string>
using namespace std;

void DisplayDictionary(const Dictionary* dictionary)
{
    if (dictionary == nullptr || dictionary->HashTable == nullptr)
    {
        cout << "Dictionary is empty."<<endl;
        return;
    }
    cout << "Dictionary:" << endl;
    for (int i = 0; i < dictionary->HashTable->Capacity; ++i)
    {
        HashTableItem* item = dictionary->HashTable->HashTable[i];
        while (item != nullptr)
        {
            cout << "key: " << item->Key << ", value: " << item->Value << endl;
            item = item->Next;
        }
    }
    cout << endl;
}


void DictionaryMenu(Dictionary* dictionary)
{

    while (true)
    {
        cout << "Dictionary Menu:" << endl;
        cout << "1 - Add to Dictionary" << endl;
        cout << "2 - Searching for a value by key" << endl;
        cout << "3 - Delete from Dictionary" << endl;
        cout << "0 - Back to Main Menu" << endl << endl;

        DisplayDictionary(dictionary);
        int command = GetIntInput("Your input: ");
        switch (command)
        {
            case 1:
            {
                string key = GetStringInput("Enter key to add: ");
                string value = GetStringInput("Enter value to add: ");
                cout << endl;
                Insert(dictionary, key, value);
                break;
            }
            case 2:
            {
                string key = GetStringInput("Enter key to search: ");
                string value = Find(dictionary, key);
                if (value.empty())
                {
                    cout << "Key not found."<<endl;
                }
                else
                {
                    cout << "Value(s) for key '" << key << "': " << value << endl;
                }
                break;
            }
            case 3:
            {
                string key = GetStringInput("Enter key to delete: ");
                Remove(dictionary, key);
                break;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "Invalid choice! Try again." << endl;
            }
        }
    }
}