#pragma once
#include <string>
using namespace std;

//! \brief ��������� ��� ������������� �������� ���-�������.
struct HashTableItem
{
    //! \brief ���� ��������, ������������ ��� �����������.
    string Key;

    //! \brief ��������, ��������� � ������.
    string Value;

    //! \brief  ��������� �� ��������� ������� � �������.
    HashTableItem* Next;
    
    //! \brief ����������� ��� �������� ������ �������� ���-�������.
    //! \param key ���� ��������, ������� ����� �������� � ���-�������.
    //! \param value ��������, ��������� � ��������� ������.
    HashTableItem(const string& key, const string& value) : Key(key), Value(value), Next(nullptr) {};
};
