#include "ListItem.h"

//! \brief Структура для двусвязного списка
struct List
{
	//! \brief Указатель на первый узел
	ListItem* Head;

	//! \brief Указатель на последний узел
	ListItem* Tail;
};

//TODO: rewrite
//! \brief Инициализирует двусвязный список.
//! \param list Ссылка на список, который нужно инициализировать.
void InitializeList(List& list);

//! \brief Удаляет элемент из двусвязного списка.
//! \param list Ссылка на список, из которого удаляется элемент.
//! \param value Значение элемента, который нужно удалить.
void RemoveElement(List& list, int value);

//! \brief Вставляет элемент в начало двусвязного списка.
//! \param list Ссылка на список, в который вставляется элемент.
//! \param value Значение элемента, который нужно вставить.
void InsertAtBeginning(List& list, int value);

//! \brief Вставляет элемент в конец двусвязного списка.
//! \param list Ссылка на список, в который вставляется элемент.
//! \param value Значение элемента, который нужно вставить.
void InsertAtEnd(List& list, int value);

//! \brief Вставляет элемент после заданного значения в двусвязном списке.
//! \param list Ссылка на список, в который вставляется элемент.
//! \param afterValue Значение элемента, после которого нужно вставить новый элемент.
//! \param value Значение нового элемента, который нужно вставить.
void InsertAfter(List& list, int afterValue, int value);

//! \brief Вставляет элемент перед заданным значением в двусвязном списке.
//! \param list Ссылка на список, в который вставляется элемент.
//! \param beforeValue Значение элемента, перед которым нужно вставить новый элемент.
//! \param value Значение нового элемента, который нужно вставить.
void InsertBefore(List& list, int beforeValue, int value);

//! \brief Сортирует двусвязный список.
//! \param list Ссылка на список, который нужно отсортировать.
void SortList(List& list);

//! \brief Выполняет линейный поиск значения в двусвязном списке.
//! \param list Ссылка на список, в котором выполняется поиск.
//! \param value Значение, которое нужно найти.
//! \return index или -1 если не найдено значение 
int LinearSearch(List& list, int value);

//TODO: remove
//! \brief Печатает элементы двусвязного списка.
//! \param list Константная ссылка на список, элементы которого нужно напечатать.
void PrintList(const List& list);

//! \brief Освобождает память, занятую двусвязным списком.
//! \param list Ссылка на список, память которого нужно освободить.
void Cleanup(List& list);