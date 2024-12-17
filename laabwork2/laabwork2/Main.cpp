#include <iostream>
#include <chrono>
#include "List.h"
using namespace std;

void displayMenu() 
{
    cout << "1. Add element\n"
        << "2. Remove element\n"
        << "3. Insert at beginning\n"
        << "4. Insert at end\n"
        << "5. Insert after\n"
        << "6. Insert before\n"
        << "7. Sort list\n"
        << "8. Linear search\n"
        << "9. Compare insertion and deletion times\n"
        << "10. Exit\n";
}

int getInputValue(const std::string& cancl) 
{
    int value;
    cout << cancl;
    cin >> value;
    return value;
}

void measureInsertion(DoublyLinkedList& list, int numElements) 
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        list.add(i);
    }
    auto end = chrono::steady_clock::now();
    cout << "Insertion time for " << numElements << " elements: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
}

void measureDeletion(DoublyLinkedList& list, int numElements) 
{
    for (int i = 0; i < numElements; ++i) 
    {
        list.add(i); // Populate the list first
    }
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < numElements; ++i) 
    {
        list.remove(i);
    }
    auto end = chrono::steady_clock::now();
    cout << "Deletion time for " << numElements << " elements: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
}
const int lengths[] = { 50000, 100000, 1000000, 10000000 };

void processChoice(DoublyLinkedList& list, int choice) {
    int value, target;

    switch (choice) 
    {
    case 1:
        value = getInputValue("Enter value: ");
        list.add(value);
        break;
    case 2:
        value = getInputValue("Enter value to remove: ");
        list.remove(value);
        break;
    case 3:
        value = getInputValue("Enter value: ");
        list.insertAtBeginning(value);
        break;
    case 4:
        value = getInputValue("Enter value: ");
        list.insertAtEnd(value);
        break;
    case 5:
        target = getInputValue("Enter target value: ");
        value = getInputValue("Enter value to insert: ");
        list.insertAfter(target, value);
        break;
    case 6:
        target = getInputValue("Enter target value: ");
        value = getInputValue("Enter value to insert: ");
        list.insertBefore(target, value);
        break;
    case 7:
        list.sort();
        break;
    case 8:
        value = getInputValue("Enter value to search: ");
        if (list.linearSearch(value)) {
            cout << "Element found\n";
        }
        else 
        {
            cout << "Element not found\n";
        }
        break;
    case 9:
        for (int length : lengths) {
            list.init();
            measureInsertion(list, length);
            list.cleanup(); 

            measureDeletion(list, length);
            list.cleanup(); 
        }
        break;
    case 10:
        list.cleanup();
        exit(0);
    default:
        cout << "Invalid choice\n";
    }

    // ¬ывод текущего списка после выполнени€ операции
    list.display();
}

int main() 
{
    DoublyLinkedList list;
    list.init();
    int choice;

    while (true) 
    {
        displayMenu();
        choice = getInputValue("Choose an option: ");
        processChoice(list, choice);
    }

    return 0;
}
