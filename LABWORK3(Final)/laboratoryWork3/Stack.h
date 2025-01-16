#pragma once
//! \brief ��������� ��� �����.
struct Stack
{
	//! \brief ��������� �� ������
	int* Data;

	//! \brief ������� �����
	int Capacity;

	//! \brief ������ �������� ��������
	int Top;
};

//! \brief ����������� ����� ��� ��������� �������
const int GrowthFactor = 2;

//! \brief ������� � �������������� ����.
//! \return ��������� �� ��������� ����.
Stack* CreateStack();

//! \brief ��������� ������� �� ���� �����.
//! \param stack ��������� �� ����, � ������� ����� �������� �������.
//! \param data ��������, ������� ����� ��������� � ����.
void Push(Stack* stack, int data);

//! \brief ������� � ���������� ������� ������� �� �����.
//! \param stack ��������� �� ����, �� �������� ����� ������ �������.
//! \return �������� ���������� ��������.
int Pop(Stack* stack);

//! \brief ���������, ���� �� ����.
//! \param stack ��������� �� ����, ������� ����� ���������.
//! \return ������, ���� ���� ����, ���� � ��������� ������.
bool IsEmpty(Stack* stack);

//! \brief ���������, ����� �� ����.
//! \param stack ��������� �� ����, ������� ����� ���������.
//! \return ������, ���� ���� �����, ���� � ��������� ������.
bool IsFull(Stack* stack);

//! \brief ����������� ������, ������� ������.
//! \param stack ��������� �� ����, ������� ����� �������.
void Delete(Stack* stack);

//! \brief �������� ������ ����� �� ����� ������.
//! \param stack ��������� �� ����, ������� ����� ��������.
//! \param newCapacity ����� ������ ��� �����.
void Resize(Stack* stack, int newCapacity);
