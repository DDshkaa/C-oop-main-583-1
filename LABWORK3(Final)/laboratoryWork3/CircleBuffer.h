#pragma once

//! \brief ��������� ���������� ������.
struct CircleBuffer
{
	//! \brief ���������
	int* Buffer;

	//! \brief ��������� �������
	int Tail;

	//! \brief ������ �������
	int Head;

	//! \brief �������
	int BufferSize;

	//! \brief ���������� ���������
	int Count;
};

//! \brief ��������� ������ ���������� ������.
const int SIZE = 5;

//! \brief ������� � �������������� ��������� �����.
//! \return ��������� �� ��������� ��������� �����.
CircleBuffer* CreateCircleBuffer();

//! \brief ��������� ������� � ��������� �����.
//! \param buffer ��������� �� ��������� �����, � ������� ����� �������� �������.
//! \param item ��������, ������� ����� ��������� � �����.
void AddElement(CircleBuffer* buffer, int item);

//! \brief ��������� ������� �� ���������� ������.
//! \param buffer ��������� �� ��������� �����, �� �������� ����� �������� �������.
//! \return �������� ������������ ��������.
int Remove(CircleBuffer* buffer);

//! \brief ���������� ���������� ��������� ���� � ��������� ������.
//! \param buffer ��������� �� ��������� �����, ��� �������� ��������� ���������� ��������� ����.
//! \return ���������� ��������� ���� � ������.
int FreeSpace(CircleBuffer* buffer);

//! \brief ���������� ���������� ������� ���� � ��������� ������.
//! \param buffer ��������� �� ��������� �����, ��� �������� ��������� ���������� ������� ����.
//! \return ���������� ������� ���� � ������.
int OccupiedSpace(CircleBuffer* buffer);

//! \brief ����������� ������, ������� ��������� �������.
//! \param buffer ��������� �� ��������� �����, ������� ���������� �������.
void FreeBuffer(CircleBuffer* buffer);
