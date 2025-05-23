#include "ListItem.h"

//! \brief ��������� ��� ����������� ������
struct List
{
	//! \brief ��������� �� ������ ����
	ListItem* Head = nullptr;

	//! \brief ��������� �� ��������� ����
	ListItem* Tail = nullptr;
};


//! \brief ������� ������� �� ����������� ������.
//! \param list ������ �� ������, �� �������� ��������� �������.
//! \param value �������� ��������, ������� ����� �������.
void RemoveElement(List& list, int value);

//! \brief ��������� ������� � ������ ����������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param value �������� ��������, ������� ����� ��������.
void InsertAtBeginning(List& list, int value);

//! \brief ��������� ������� � ����� ����������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param value �������� ��������, ������� ����� ��������.
void InsertAtEnd(List& list, int value);

//! \brief ��������� ������� ����� ��������� �������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param afterValue �������� ��������, ����� �������� ����� �������� ����� �������.
//! \param value �������� ������ ��������, ������� ����� ��������.
void InsertAfter(List& list, int afterValue, int value);

//! \brief ��������� ������� ����� �������� ��������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param beforeValue �������� ��������, ����� ������� ����� �������� ����� �������.
//! \param value �������� ������ ��������, ������� ����� ��������.
void InsertBefore(List& list, int beforeValue, int value);

//! \brief ��������� ���������� ������.
//! \param list ������ �� ������, ������� ����� �������������.
void SortList(List& list);

//! \brief ��������� �������� ����� �������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �����.
//! \param value ��������, ������� ����� �����.
//! \return index ��� -1 ���� �� ������� �������� 
int LinearSearch(List& list, int value);

//! \brief ����������� ������, ������� ���������� �������.
//! \param list ������ �� ������, ������ �������� ����� ����������.
void Cleanup(List& list);