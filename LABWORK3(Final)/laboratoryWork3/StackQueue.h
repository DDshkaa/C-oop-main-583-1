#pragma once
#include "Stack.h"

//! \brief —труктура, представл€юща€ очередь, реализованную с использованием двух стеков.
struct StackQueue
{
    //! \brief ѕервый стек
    Stack* Stack1;

    //! \brief ¬торой стек
    Stack* Stack2;
};

//! \brief ‘ункци€ дл€ создани€ нового экземпл€ра StackQueue.
//! \return ”казатель на только что созданный экземпл€р StackQueue.
StackQueue* CreateStackQueue();

//! \brief ƒобавл€ет элемент в конец очереди.
//! \param queue ”казатель на экземпл€р StackQueue, в который будет добавлен элемент.
//! \param data «начение, которое будет добавлено в очередь.
void EnqueueStackQueue(StackQueue* queue, int data);

//! \brief ”дал€ет и возвращает первый элемент из очереди.
//! \param queue ”казатель на экземпл€р StackQueue, из которого будет удален элемент.
//! \return «начение удаленного элемента.
int DequeueStackQueue(StackQueue* queue);

//! \brief ќчищает очередь, удал€€ оба стека.
//! \param queue ”казатель на экземпл€р StackQueue, который нужно очистить.
void FreeStackQueue(StackQueue* queue);
