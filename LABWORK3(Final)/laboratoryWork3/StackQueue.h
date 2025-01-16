#pragma once
#include "Stack.h"

//! \brief ���������, �������������� �������, ������������� � �������������� ���� ������.
struct StackQueue
{
    //! \brief ������ ����
    Stack* Stack1;

    //! \brief ������ ����
    Stack* Stack2;
};

//! \brief ������� ��� �������� ������ ���������� StackQueue.
//! \return ��������� �� ������ ��� ��������� ��������� StackQueue.
StackQueue* CreateStackQueue();

//! \brief ��������� ������� � ����� �������.
//! \param queue ��������� �� ��������� StackQueue, � ������� ����� �������� �������.
//! \param data ��������, ������� ����� ��������� � �������.
void EnqueueStackQueue(StackQueue* queue, int data);

//! \brief ������� � ���������� ������ ������� �� �������.
//! \param queue ��������� �� ��������� StackQueue, �� �������� ����� ������ �������.
//! \return �������� ���������� ��������.
int DequeueStackQueue(StackQueue* queue);

//! \brief ������� �������, ������ ��� �����.
//! \param queue ��������� �� ��������� StackQueue, ������� ����� ��������.
void FreeStackQueue(StackQueue* queue);
