#pragma once

//! \brief Структура кольцевого буфера.
struct CircleBuffer
{
	//! \brief указатель
	int* Buffer;

	//! \brief последний элемент
	int Tail;

	//! \brief первый элемент
	int Head;

	//! \brief емкость
	int BufferSize;

	//! \brief количество элементов
	int Count;
};

//! \brief начальный размер кольцевого буфера.
const int SIZE = 5;

//! \brief Создает и инициализирует кольцевой буфер.
//! \return Указатель на созданный кольцевой буфер.
CircleBuffer* CreateCircleBuffer();

//! \brief Добавляет элемент в кольцевой буфер.
//! \param buffer Указатель на кольцевой буфер, в который будет добавлен элемент.
//! \param item Значение, которое будет добавлено в буфер.
void AddElement(CircleBuffer* buffer, int item);

//! \brief Извлекает элемент из кольцевого буфера.
//! \param buffer Указатель на кольцевой буфер, из которого будет извлечен элемент.
//! \return Значение извлеченного элемента.
int Remove(CircleBuffer* buffer);

//! \brief Возвращает количество свободных мест в кольцевом буфере.
//! \param buffer Указатель на кольцевой буфер, для которого требуется количество свободных мест.
//! \return Количество свободных мест в буфере.
int FreeSpace(CircleBuffer* buffer);

//! \brief Возвращает количество занятых мест в кольцевом буфере.
//! \param buffer Указатель на кольцевой буфер, для которого требуется количество занятых мест.
//! \return Количество занятых мест в буфере.
int OccupiedSpace(CircleBuffer* buffer);

//! \brief Освобождает память, занятую кольцевым буфером.
//! \param buffer Указатель на кольцевой буфер, который необходимо удалить.
void FreeBuffer(CircleBuffer* buffer);
