#pragma once
#include <string>
//! brief ��������� ������������� �������.
struct DynamicArray
{
    //! brief ������ �������.
    int Size;

    //! brief ����������� �������.
    int Capacity;

    //! brief ������.
    int* Array;
};
//! brief ������ ������������ ������.
DynamicArray* �reateDynamicArray();

//! brief ��������� ������� � ������.
//! param array ��������� ������������� �������.
//! param index ������ ��������, ���� ����� �������� �������.
//! param value �������� ��������.
void AddElement(DynamicArray* array, int index, int value);

//! brief ������� ������� ������� �� ������������� �������.
//! param array ��������� ������������� �������.
//! param index ������ ��������, ������� ����� �������.
void RemoveByIndex(DynamicArray* array, int index);

//! brief ������� �������� �������� �� ��� ������������� ��������.
//! param array ��������� ������������� �������.
//! param value ���������� ��������, ������� ����� �������.
void RemoveByValue(DynamicArray* array, int value);

//! brief ��������� ������.
//! param array ��������� ������������� �������.
void GnomeSort(DynamicArray* array);

//! brief �������� ����� ������� �������� �� ������������� ��������.
//! param array ��������� ������������� �������.
//! param value ��������, ������ �������� ����� �����.
int LinerSearch(DynamicArray* array, int value);

//! brief �������� ����� ������� �������� �� ������������� ��������.
//! param array ��������� ������������� �������.
//! param value ��������, ������ �������� ����� �����.
int BinarySearch(DynamicArray* array, int value);

int Check(const std::string& Value);