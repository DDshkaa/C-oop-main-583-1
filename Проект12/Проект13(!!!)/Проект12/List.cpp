#include "List.h"
#include <iostream>
using namespace std;

void InitializeList(List& list)
{
	list.Head = nullptr;
	list.Tail = nullptr;
}

void RemoveElement(List& list, int value)
{
	ListItem* current = list.Head;
	while (current)
	{
		if (current->Data == value)
		{
			if (current->Prev)
			{
				current->Prev->Next = current->Next;
			}
			else
			{
				list.Head = current->Next;
			}
			if (current->Next)
			{
				current->Next->Prev = current->Prev;
			}
			else
			{
				list.Tail = current->Prev;
			}
			delete current;
			return;
		}
		current = current->Next;
	}
	throw runtime_error("value not found ");
}

void InsertAtBeginning(List& list, int value)
{
	ListItem* newNode = new ListItem;
	newNode->Data = value;
	newNode->Next = list.Head;
	newNode->Prev = nullptr;

	if (!list.Head)
	{
		list.Head = newNode;
		list.Tail = newNode;
	}
	else
	{
		list.Head->Prev = newNode;
		list.Head = newNode;
	}
}

void InsertAtEnd(List& list, int value)
{
	ListItem* newNode = new ListItem;
	newNode->Data = value;
	newNode->Next = nullptr;
	newNode->Prev = list.Tail;

	if (!list.Head)
	{
		list.Head = newNode;
		list.Tail = newNode;
	}
	else
	{
		list.Tail->Next = newNode;
		list.Tail = newNode;
	}
}

void InsertAfter(List& list, int afterValue, int value)
{
	ListItem* current = list.Head;
	while (current)
	{
		if (current->Data == afterValue)
		{
			ListItem* newNode = new ListItem;
			newNode->Data = value;
			newNode->Next = current->Next;
			newNode->Prev = current;
			if (current->Next)
			{
				current->Next->Prev = newNode;
			}
			else
			{
				list.Tail = newNode;
			}
			current->Next = newNode;
			return;
		}
		current = current->Next;
	}
	throw runtime_error("value not found ");
}

void InsertBefore(List& list, int beforeValue, int value)
{
	ListItem* current = list.Head;
	while (current)
	{
		if (current->Data == beforeValue)
		{
			ListItem* newNode = new ListItem;
			newNode->Data = value;
			newNode->Prev = current->Prev;
			newNode->Next = current;
			if (current->Prev)
			{
				current->Prev->Next = newNode;
			}
			else
			{
				list.Head = newNode;
			}
			current->Prev = newNode;
			return;
		}
		current = current->Next;
	}
	throw runtime_error("value not found ");
}

void SortList(List& list)
{
	if (!list.Head) return;

	bool swapped;
	do
	{
		swapped = false;
		ListItem* current = list.Head;
		while (current->Next)
		{
			if (current->Data > current->Next->Data)
			{
				swap(current->Data, current->Next->Data);
				swapped = true;
			}
			current = current->Next;
		}
	} while (swapped);
}

int LinearSearch(List& list, int value)
{
	ListItem* current = list.Head;
	int index = 0;
	while (current)
	{
		if (current->Data == value)
		{
			return index;
		}
		current = current->Next;
		index++;
	}
	return -1;
}

//TODO: remove

void PrintList(const List& list)
{
	ListItem* current = list.Head;
	while (current)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
}

void Cleanup(List& list)
{
	while (list.Head)
	{
		ListItem* temp = list.Head;
		list.Head = list.Head->Next;
		delete temp;
	}
	list.Tail = nullptr;
}