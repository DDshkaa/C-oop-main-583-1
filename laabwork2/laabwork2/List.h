#include "ListItem.h"

//! \brief �������������� ���������� ������.
//! \param list ������ �� ������, ������� ����� ����������������.
void initializeList(List& list);

//! \brief ������� ������� �� ����������� ������.
//! \param list ������ �� ������, �� �������� ��������� �������.
//! \param value �������� ��������, ������� ����� �������.
void removeElement(List& list, int value);

//! \brief ��������� ������� � ������ ����������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param value �������� ��������, ������� ����� ��������.
void insertAtBeginning(List& list, int value);

//! \brief ��������� ������� � ����� ����������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param value �������� ��������, ������� ����� ��������.
void insertAtEnd(List& list, int value);

//! \brief ��������� ������� ����� ��������� �������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param afterValue �������� ��������, ����� �������� ����� �������� ����� �������.
//! \param value �������� ������ ��������, ������� ����� ��������.
void insertAfter(List& list, int afterValue, int value);

//! \brief ��������� ������� ����� �������� ��������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �������.
//! \param beforeValue �������� ��������, ����� ������� ����� �������� ����� �������.
//! \param value �������� ������ ��������, ������� ����� ��������.
void insertBefore(List& list, int beforeValue, int value);

//! \brief ��������� ���������� ������.
//! \param list ������ �� ������, ������� ����� �������������.
void sortList(List& list);

//! \brief ��������� �������� ����� �������� � ���������� ������.
//! \param list ������ �� ������, � ������� ����������� �����.
//! \param value ��������, ������� ����� �����.
//! \return ��������� �� ���� � ��������� ��������� ��� nullptr, ���� �������� �� �������.
Node* linearSearch(List& list, int value);

//! \brief �������� �������� ����������� ������.
//! \param list ����������� ������ �� ������, �������� �������� ����� ����������.
void printList(const List& list);

//! \brief ����������� ������, ������� ���������� �������.
//! \param list ������ �� ������, ������ �������� ����� ����������.
void cleanup(List& list);
