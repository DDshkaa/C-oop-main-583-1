#include "ListItem.h"

struct DoublyLinkedList 
{
    ListItem* head;

    ListItem* tail;

    void init();
    void add(int value);
    void remove(int value);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAfter(int target, int value);
    void insertBefore(int target, int value);
    void sort();
    bool linearSearch(int value);
    void display();
    void cleanup();
};


