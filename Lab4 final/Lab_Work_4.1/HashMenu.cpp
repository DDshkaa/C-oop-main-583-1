#include "HashMenu.h"

void DisplayHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->Capacity; ++i)
    {
        cout << "[" << i << "] ";
        if (hashTable->HashTable[i])
        {
            HashTableItem* current = hashTable->HashTable[i];
            while (current)
            {
                cout << current->Key << ":" << current->Value << " >> ";
                current = current->Next;
            }
        }
        else
        {
            cout << "empty";
        }
        cout << endl;
    }
}

void HashTableMenu(HashTable* hashTable)
{
    while (true)
    {
        DisplayHashTable(hashTable);
        cout << "Hash Table Menu: " << endl;
        cout << "1 - Add to Hash Table" << endl;
        cout << "2 - Searching for a value by key" << endl;
        cout << "3 - Delete from HashTable" << endl;
        cout << "0 - Back to Main Menu" << endl << endl;

        int command = GetIntInput("Your input: ");
        switch (command)
        {
            case 1:
            {
                string key = GetStringInput("Enter key to add: ");
                string value = GetStringInput("Enter value to add: ");
                cout << endl;
                Add(hashTable, key, value);
                break;
            }
            case 2:
            {
                string key = GetStringInput("Enter key to search: ");
                string value = Search(*hashTable, key);
                if (value.empty())
                {
                    cout << "Key not found."<<endl;
                }
                else
                {
                    cout << "Value(s) for key '" << key << "': " << value << ", " << endl;
                }
                break;
            }
            case 3:
            {
                string key = GetStringInput("Enter key to delete: ");
                DeleteItem(hashTable, key);
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