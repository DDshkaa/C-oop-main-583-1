#pragma once
#include "HashTableItem.h"
#include <string>

//! \brief ��������� ��� ������������� ��� - �������.
struct HashTable
{
    //! \brief ��������� �� ������ ���������� �� �������� ���-�������.
    HashTableItem** HashTable;

    //! \brief ����� ������� ���-������� 
    int Capacity;

    //! \brief ������� ������ ���-�������
    int CurrentSize;

    //! \brief ��������� �� ������� �������, ������������ ��� �����������.
    int* PearsonTable;
};

//! \brief ��������� ������ ���-�������.
const int InitialSize = 8;

//! \brief ������ ������������� ��� ����� ���-�������.
const float factorial = 0.7;

//! \brief ������ ����� ���-�������.
const int GrowthFactor = 2;

//! \brief ������� ������� ������� ��� ��������� �������.
//! \param capacity ������� ���-�������, ��� ������� ��������� ������� �������.
//! \return ��������� �� ��������� ������� �������.
int* MakePearsonTable(int capacity);

//! \brief ��������� ���-��� ��� ��������� �����.
//! \param hashTable ������ �� ���-�������, � ������� ����� ��������� ���������� ���-����.
//! \param key ����, ��� �������� ���������� ��������� ���-���.
//! \param baseNum ������� ����� ��� ���������� ���-���� (�� ��������� 31).
//! \return ����������� ���-���.
int GetHashCode(HashTable& hashTable, const std::string& key, int baseNum = 31);

//! \brief ������� ����� ���-�������.
//! \return ��������� �� ��������� ���-�������.
HashTable* CreateHashTable();

//! \brief ������������ �������� � ���-�������.
//! \param hashTable ��������� �� ���-�������, ������� ���������� ��������������.
void Rehash(HashTable* hashTable);

//! \brief ��������� ������� � ���-�������.
//! \param hashTable ��������� �� ���-�������, � ������� ����� �������� �������.
//! \param key ���� ��������, ������� ����� ��������.
//! \param value �������� ��������, ������� ����� ��������.
void Add(HashTable* hashTable, const string& key, const string& value);

//! \brief ���� �������� �� ����� � ���-�������.
//! \param hashTable ������ �� ���-�������, � ������� ����� �������� �����.
//! \param key ���� ��������, ������� ����� �����.
//! \return ��������, ��������� � ������. ���� ���� �� ������, ���������� ������ ������.
string Search(HashTable& hashTable, const std::string& key);

//! \brief ������� ������� �� ���-������� �� �����.
//! \param hashTable ��������� �� ���-�������, �� ������� ����� ������ �������.
//! \param key ���� ��������, ������� ����� �������.
void DeleteItem(HashTable* hashTable, const string& key);

//! \brief ����������� ������, ������� ���-��������.
//! \param hashTable ��������� �� ���-�������, ������� ����� �������.
void DeleteHashTable(HashTable* hashTable);