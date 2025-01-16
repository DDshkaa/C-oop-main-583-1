#pragma once
//! \brief Структура для стека.
struct Stack
{
	//! \brief указатель на данные
	int* Data;

	//! \brief емкость стека
	int Capacity;

	//! \brief индекс верхнего элемента
	int Top;
};

//! \brief коэффициент роста для изменения размера
const int GrowthFactor = 2;

//! \brief Создает и инициализирует стек.
//! \return Указатель на созданный стек.
Stack* CreateStack();

//! \brief Добавляет элемент на верх стека.
//! \param stack Указатель на стек, в который будет добавлен элемент.
//! \param data Значение, которое будет добавлено в стек.
void Push(Stack* stack, int data);

//! \brief Удаляет и возвращает верхний элемент из стека.
//! \param stack Указатель на стек, из которого будет удален элемент.
//! \return Значение удаленного элемента.
int Pop(Stack* stack);

//! \brief Проверяет, пуст ли стек.
//! \param stack Указатель на стек, который нужно проверить.
//! \return Истина, если стек пуст, ложь в противном случае.
bool IsEmpty(Stack* stack);

//! \brief Проверяет, полон ли стек.
//! \param stack Указатель на стек, который нужно проверить.
//! \return Истина, если стек полон, ложь в противном случае.
bool IsFull(Stack* stack);

//! \brief Освобождает память, занятую стеком.
//! \param stack Указатель на стек, который нужно удалить.
void Delete(Stack* stack);

//! \brief Изменяет размер стека на новый размер.
//! \param stack Указатель на стек, который нужно изменить.
//! \param newCapacity Новый размер для стека.
void Resize(Stack* stack, int newCapacity);
