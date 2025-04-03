#pragma once
#include "HashTable.h"
#include "SearchMetod.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

//! \brief ���������� �������� ���-�������.
//! \param hashTable ��������� �� ��������� HashTable, ������� ����� ���������.
void DisplayHashTable(HashTable* hashTable);

//! \brief ���� ��� ������ � ���-��������.
//! \param hashTable ��������� �� ��������� HashTable, � ������� ����� �������� ����.
void HashTableMenu(HashTable* hashTable);