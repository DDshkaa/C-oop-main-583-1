#include "List.h"
#include <iostream>
using namespace std;

void initializeList(List& list) 
{
    list.head = nullptr;
    list.tail = nullptr;
}

void removeElement(List& list, int value) 
{
    Node* current = list.head;
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
                // Удаляем первый элемент
                list.head = current->next; 
            }
            if (current->next) 
            {
                current->next->prev = current->prev;
            }
            else 
            {   
                // Удаляем последний элемент
                list.tail = current->prev; 
            }
            delete current;
            return;
        }
        current = current->next;
    }
    throw runtime_error("value not found ");
}

void insertAtBeginning(List& list, int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = list.head;
    newNode->prev = nullptr;

    if (!list.head)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else 
    {
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void insertAtEnd(List& list, int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = list.tail;

    if (!list.head)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void insertAfter(List& list, int afterValue, int value) 
{
    Node* current = list.head;
    while (current)
    {
        if (current->data == afterValue) 
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) 
            {
                current->next->prev = newNode;
            }
            else 
            {
                list.tail = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    throw runtime_error("value not found ");
}

void insertBefore(List& list, int beforeValue, int value) 
{
    Node* current = list.head;
    while (current) 
    {
        if (current->data == beforeValue) 
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev) 
            {
                current->prev->next = newNode;
            }
            else 
            {
                list.head = newNode;
            }
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
    throw runtime_error("value not found ");
}

void sortList(List& list) 
{
    if (!list.head) return;

    bool swapped;
    do 
    {
        swapped = false;
        Node* current = list.head;
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

Node* linearSearch(List& list, int value) 
{
    Node* current = list.head;
    while (current) 
    {
        if (current->data == value) 
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void printList(const List& list) 
{
    cout << endl;
    Node* current = list.head;
    while (current) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl << endl;
}

void cleanup(List& list) 
{
    while (list.head) 
    {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }
    list.tail = nullptr;
}



