#include <iostream>
#include <string>
#include <chrono>
#include "List.h"
using namespace std;

//! \brief выводит меню команд для пользователя
void displayMenu() 
{
    cout << "Menu: List\n";
    cout << "1. Remove element\n";
    cout << "2. Insert at beginning\n";
    cout << "3. Insert at end\n";
    cout << "4. Insert after element\n";
    cout << "5. Insert before element\n";
    cout << "6. Sort list\n";
    cout << "7. Linear search element\n";
    cout << "8. Running time for insert and delete operations\n";
    cout << "9. Exit\n";
}

int getChoice(const string& cancl)
{
    int choice;
    string input;

    while (true)
    {
        cout << cancl;
        getline(cin, input);

        try
        {
            choice = stoi(input);
            return choice;
        }

        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Please enter an integer value.\n";
        }
    }
}


int getValue(const string& cancl)
{
    int value;
    string input;

    while (true)
    {
        cout << cancl;
        getline(cin, input);

        try
        {
            value = stoi(input);
            return value;
        }

        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Please enter an integer value.\n";
        }
        
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}

void measureInsertion(List& list, int numElements) 
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        insertAtEnd(list, i);
    }
    auto end = chrono::steady_clock::now();
    cout << "Insertion for size " << numElements << " took "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microseconds.\n";
}

void measureRemoval(List& list, int numElements) 
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        removeElement(list, i); 
    }
    auto end = chrono::steady_clock::now();
    cout << "Removal for size " << numElements << " took "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microseconds.\n";
}


int main() 
{
    List list;
    initializeList(list);
    int choice;

    const int testSizes[] = { 500, 1000, 5000, 10000, 50000, 100000 };
    
    do 
    {
        try
        {
            displayMenu();
            choice = getChoice("Choice an option: ");

            switch (choice)
            {

            case 1:
            {
                int value = getValue("Enter value: ");
                removeElement(list, value);
                break;
            }

            case 2:
            {
                int value = getValue("Enter value: ");
                insertAtBeginning(list, value);
                break;
            }

            case 3:
            {
                int value = getValue("Enter value: ");
                insertAtEnd(list, value);
                break;
            }

            case 4:
            {
                int afterValue = getValue("Enter after value: ");
                int value = getValue("Enter value: ");
                insertAfter(list, afterValue, value);
                break;
            }

            case 5:
            {
                int beforeValue = getValue("Enter before value: ");
                int value = getValue("Enter value: ");
                insertBefore(list, beforeValue, value);
                break;
            }

            case 6:
            {
                sortList(list);
                break;
            }

            case 7:
            {
                int value = getValue("Enter value: ");
                Node* foundNode = linearSearch(list, value);
                if (foundNode)
                {
                    cout << "Value " << value << " found.\n";
                }
                else
                {
                    cout << "Value " << value << " not found.\n";
                }
                break;
            }

            case 8:
            {
                for (int size : testSizes)
                {
                    // Измеряем время вставки
                    measureInsertion(list, size);

                    // Теперь удаляем элементы
                    measureRemoval(list, size);

                    //cleanup(list);
                }
            }

            case 9:
                break;
            default:
                cout << "Invalid choice\n";
            }

            if (choice != 9)
            {
                printList(list);
            }
        }
        catch (runtime_error)
        {
            cout << "value not found " << endl;
            printList(list);
        }

    } 
    while (choice != 9);

    cleanup(list);
    return 0;
}