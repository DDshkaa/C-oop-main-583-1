#pragma once
#include "HashTable.h"
#include "SearchMetod.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

//! \brief ќтображает элементы хеш-таблицы.
//! \param hashTable ”казатель на экземпл€р HashTable, который будет отображен.
void DisplayHashTable(HashTable* hashTable);

//! \brief меню дл€ работы с хеш-таблицей.
//! \param hashTable ”казатель на экземпл€р HashTable, с которым будет работать меню.
void HashTableMenu(HashTable* hashTable);