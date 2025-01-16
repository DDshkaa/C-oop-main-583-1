#pragma once
#include "CircleBuffer.h"

//! \brief Структура очереди на основе кольцевого буфера.
struct Queue
{
	//! \brief указатель на кольцевой буфер
	CircleBuffer* Cbuffer;
};

//! \brief Создает и инициализирует очередь, используя кольцевой буфер.
//! \return Указатель на созданную очередь.
Queue* CreateQueueByBuffer();

//! \brief Добавляет элемент в конец очереди.
//! \param queue Указатель на очередь, в которую будет добавлен элемент.
//! \param item Значение, которое будет добавлено в очередь.
void Enqueue(Queue* queue, int item);

//! \brief Удаляет и возвращает первый элемент из очереди.
//! \param queue Указатель на очередь, из которой будет удален элемент.
//! \return Значение удаленного элемента.
int Dequeue(Queue* queue);

//! \brief Освобождает память, занятую очередью и ее буфером.
//! \param queue Указатель на очередь, которую необходимо удалить.
void FreeQueue(Queue* queue);
