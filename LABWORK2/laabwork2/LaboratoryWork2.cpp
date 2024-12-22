#include <iostream>
#include <string>
#include <chrono>
#include "List.h"
using namespace std;

//! \brief выводит меню команд для пользователя
void DisplayMenu() 
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
void IndexCheck(int index, int value)
{
    if (index != -1)
    {
        cout << "Value " << value << " found\n";
        cout << "Index: " << index << endl;
    }
    else
    {
        cout << "Value " << value << " not found\n";
    }
}

int GetInput(const string& cancl)
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

void MeasureInsertion(List& list, int numElements) 
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        InsertAtEnd(list, i);
    }
    auto end = chrono::steady_clock::now();
    cout << "Insertion for size " << numElements << " took "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microseconds.\n";
}

void MeasureRemoval(List& list, int numElements) 
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        RemoveElement(list, i); 
    }
    auto end = chrono::steady_clock::now();
    cout << "Removal for size " << numElements << " took "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microseconds.\n";
}


int main() 
{
    List list;
    InitializeList(list);
    int choice;

    const int testSizes[] = { 500, 1000, 5000, 10000, 50000, 100000 };
    
    do 
    {
        try
        {
            DisplayMenu();
            choice = GetInput("Choice an option: ");

            switch (choice)
            {

            case 1:
            {
                int value = GetInput("Enter value: ");
                RemoveElement(list, value);
                break;
            }

            case 2:
            {
                int value = GetInput("Enter value: ");
                InsertAtBeginning(list, value);
                break;
            }

            case 3:
            {
                int value = GetInput("Enter value: ");
                InsertAtEnd(list, value);
                break;
            }

            case 4:
            {
                int afterValue = GetInput("Enter after value: ");
                int value = GetInput("Enter value: ");
                InsertAfter(list, afterValue, value);
                break;
            }

            case 5:
            {
                int beforeValue = GetInput("Enter before value: ");
                int value = GetInput("Enter value: ");
                InsertBefore(list, beforeValue, value);
                break;
            }

            case 6:
            {
                SortList(list);
                break;
            }

            case 7:
            {
                int value = GetInput("Enter value: ");
                int index = LinearSearch(list, value);
                IndexCheck(index, value);
                break;
            }

            case 8:
            {
                for (int size : testSizes)
                {
                    // Измеряем время вставки
                    MeasureInsertion(list, size);

                    // Теперь удаляем элементы
                    MeasureRemoval(list, size);
                }
            }

            case 9:
                break;
            default:
                cout << "Invalid choice\n";
            }

            if (choice != 9)
            {
                PrintList(list);
            }
        }
        catch (runtime_error)
        {
            cout << "value not found " << endl;
            PrintList(list);
        }

    } 
    while (choice != 9);

    Cleanup(list);
    return 0;
}