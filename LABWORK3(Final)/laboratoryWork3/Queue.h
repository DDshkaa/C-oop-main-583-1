#pragma once
#include "CircleBuffer.h"

//! \brief ��������� ������� �� ������ ���������� ������.
struct Queue
{
	//! \brief ��������� �� ��������� �����
	CircleBuffer* Cbuffer;
};

//! \brief ������� � �������������� �������, ��������� ��������� �����.
//! \return ��������� �� ��������� �������.
Queue* CreateQueueByBuffer();

//! \brief ��������� ������� � ����� �������.
//! \param queue ��������� �� �������, � ������� ����� �������� �������.
//! \param item ��������, ������� ����� ��������� � �������.
void Enqueue(Queue* queue, int item);

//! \brief ������� � ���������� ������ ������� �� �������.
//! \param queue ��������� �� �������, �� ������� ����� ������ �������.
//! \return �������� ���������� ��������.
int Dequeue(Queue* queue);

//! \brief ����������� ������, ������� �������� � �� �������.
//! \param queue ��������� �� �������, ������� ���������� �������.
void FreeQueue(Queue* queue);
