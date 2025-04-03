#pragma once
#include "HashTable.h"
#include "HashTableItem.h"

//! \brief ���������, �������������� �������, ������������� � ������� ���-�������.
struct Dictionary
{
	//! \brief ��������� �� ���-�������, ������������ ��� �������� ������.
	HashTable* HashTable;
};


//! \brief ������� ����� �������.
Dictionary* CreateDictionary();

//! \brief ��������� ����� ���� "����-��������" � �������.
//! \param dictionary ��������� �� �������, � ������� ����� ��������� ����.
//! \param key ����, �� �������� ����� �������������� ������ � ��������.
//! \param value ��������, ��������� � ��������� ������.
void Insert(Dictionary* dictionary, const string& key, const string& value);

//! \brief ������� �������� �� ���������� �����.
//! \param dictionary ��������� �� �������, � ������� ����� ��������� �����.
//! \param key ����, �� �������� ����������� ����� ��������.
//! \return ��������, ��������� � ��������� ������ ��� ������ ������, ���� ���� �� ������.
string Find(Dictionary* dictionary, const string& key);

//! \brief ������� ���� "����-��������" �� �������
//! \param dictionary ��������� �� �������, �� �������� ����� ������� ����.
//! \param key ����, ������� ����� ������� �� �������.
void Remove(Dictionary* dictionary, const string& key);

//! \brief ����������� ������, ������� ��������.
//! \param dictionary ��������� �� �������, ������� ����� �������.
void DeleteDictionary(Dictionary* dictionary);
