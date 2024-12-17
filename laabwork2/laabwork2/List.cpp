#include <iostream>
#include "List.h"
using namespace std;

void DoublyLinkedList::init() 
{
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::add(int value) 
{
    ListItem* newItem = new ListItem{ value, nullptr, tail };
    if (tail) 
    {
        tail->next = newItem;
    }
    else 
    {
        head = newItem; // Список был пуст
    }
    tail = newItem;
}

void DoublyLinkedList::remove(int value) 
{
    ListItem* current = head;
    while (current) 
    {
        if (current->data == value) 
        {
            if (current->prev) 
            {
                current->prev->next = current->next;
            }
            else 
            {
                head = current->next; // Удаляем голову
            }
            if (current->next) 
            {
                current->next->prev = current->prev;
            }
            else 
            {
                tail = current->prev; // Удаляем хвост
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::insertAtBeginning(int value) 
{
    ListItem* newItem = new ListItem{ value, head, nullptr };
    if (head) 
    {
        head->prev = newItem;
    }
    else 
    {
        tail = newItem; // Список был пуст
    }
    head = newItem;
}

void DoublyLinkedList::insertAtEnd(int value) 
{
    add(value);
}

void DoublyLinkedList::insertAfter(int target, int value) 
{
    ListItem* current = head;
    while (current) 
    {
        if (current->data == target) 
        {
            ListItem* newItem = new ListItem{ value, current->next, current };
            if (current->next) 
            {
                current->next->prev = newItem;
            }
            else 
            {
                tail = newItem; // Вставка в конец
            }
            current->next = newItem;
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::insertBefore(int target, int value) 
{
    ListItem* current = head;
    while (current) 
    {
        if (current->data == target) 
        {
            ListItem* newItem = new ListItem{ value, current, current->prev };
            if (current->prev) 
            {
                current->prev->next = newItem;
            }
            else 
            {
                head = newItem; // Вставка в начало
            }
            current->prev = newItem;
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::sort() 
{
    if (!head) return;
    bool swapped;
    do 
    {
        swapped = false;
        ListItem* current = head;
        while (current->next) 
        {
            if (current->data > current->next->data) 
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } 
    while (swapped);
}

bool DoublyLinkedList::linearSearch(int value) 
{
    ListItem* current = head;
    while (current) 
    {
        if (current->data == value) 
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::display() 
{
    ListItem* current = head;
    while (current) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::cleanup() 
{
    ListItem* current = head;
    while (current) 
    {
        ListItem* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}


