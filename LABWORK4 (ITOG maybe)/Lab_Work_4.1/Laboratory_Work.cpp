#include <iostream>
#include <algorithm>
#include <string>
#include "HashTable.h"
#include "Dictionary.h"
using namespace std;

//! \brief ѕолучает целочисленный ввод от пользовател€.
//! \param prompt —ообщение, которое будет выведено на экран дл€ запроса ввода у пользовател€.
//! \return ¬веденное пользователем целое число.
int GetIntInput(const string& prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Invalid input. Please enter an integer value.\n";
            continue;
        }

        try
        {
            value = stoi(input);
            return value;
        }
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}

//! \brief ѕолучает строковый ввод от пользовател€.
//! \param text —ообщение, которое будет выведено на экран дл€ запроса ввода у пользовател€.
//! \return ¬веденна€ пользователем строка.
string GetStringInput(const string& text)
{
    string input;

    while (true)
    {
        cout << text;
        getline(cin, input);

        if (!input.empty())
        {
            return input;
        }
        else
        {
            cout << "An empty line. Please enter a value." << endl;
        }
    }
}
//! \brief ќтображает элементы хеш-таблицы.
//! \param hashTable ”казатель на экземпл€р HashTable, который будет отображен.
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
                cout << current->Key << ":" << current->Value << " -> ";
                current = current->Next;
            }
            cout << "nullptr";
        }
        else
        {
            cout << "empty";
        }
        cout << endl;
    }
}
//! \brief меню дл€ работы с хеш-таблицей.
//! \param hashTable ”казатель на экземпл€р HashTable, с которым будет работать меню.
void HashTableMenu(HashTable* hashTable)
{
    while (true)
    {
        DisplayHashTable(hashTable);
        cout << "Hash Table Menu: " << endl;
        cout << "1. Add to Hash Table" << endl;
        cout << "2. Searching for a value by key" << endl;
        cout << "3. Delete from HashTable" << endl;
        cout << "0. Back to Main Menu" << endl << endl;

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
                cout << "Key not found.\n";
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
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

//! \brief ќтображает элементы словар€.
//! \param dictionary ”казатель на экземпл€р Dictionary, который будет отображен.
void DisplayDictionary(const Dictionary* dictionary)
{
    if (dictionary == nullptr || dictionary->HashTable == nullptr)
    {
        cout << "Dictionary is empty.\n";
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

    cout << "\n";
}
//! \brief ћеню дл€ работы со словарЄм.
//! \param dictionary ”казатель на экземпл€р Dictionary, с которым будет работать меню.
void DictionaryMenu(Dictionary* dictionary)
{

    while (true)
    {
        cout << "Dictionary Menu:" << endl;
        cout << "1. Add to Dictionary" << endl;
        cout << "2. Searching for a value by key" << endl;
        cout << "3. Delete from Dictionary" << endl;
        cout << "0. Back to Main Menu" << endl << endl;

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
                cout << "Key not found.\n";
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
            cout << "Invalid choice! Try again." << endl;
        }
    }
}


int main()
{
    HashTable* hashTable = CreateHashTable();
    Dictionary* dictionary = CreateDictionary();

    while (true)
    {
        cout << "Main menu:" << endl;
        cout << "1. Dictionary" << endl;
        cout << "2. Hash Table" << endl << endl;

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
            cout << "Invalid choice! Try again." << endl;
        }

    }
}