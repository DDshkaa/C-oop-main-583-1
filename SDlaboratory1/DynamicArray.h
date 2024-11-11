#pragma once
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

DynamicArray createDynamicArray(int initialCapacity);

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

//! brief ���������� ������� �� �������.
//! param array ��������� ������������� �������.
//! param index ������, �� �������� ����� �������� ��������.
//! return ���������� ��������, ������� ��������� ��� ��������.
int GetIndex(DynamicArray* array, int Index);

//! brief ��������� ������.
//! param array ��������� ������������� �������.
void SortArray(DynamicArray* array);

//! brief �������� ����� ������� �������� �� ������������� ��������.
//! param array ��������� ������������� �������.
//! param value ��������, ������ �������� ����� �����.
int LinerSearch(DynamicArray* array, int value);

//! brief �������� ����� ������� �������� �� ������������� ��������.
//! param array ��������� ������������� �������.
//! param value ��������, ������ �������� ����� �����.
int BinarySearch(DynamicArray* array, int value);
