#pragma once
#include <string>
//! brief Структура динамического массива.
struct DynamicArray
{
    //! brief Размер массива.
    int Size;

    //! brief Вместимость массива.
    int Capacity;

    //! brief Массив.
    int* Array;
};
//! brief Создаёт динамический массив.
DynamicArray* СreateDynamicArray();

//! brief Добавляет элемент в массив.
//! param array Структура динамического массива.
//! param index Индекс элемента, куда нужно добавить элемент.
//! param value Значение элемента.
void AddElement(DynamicArray* array, int index, int value);

//! brief Удаляет элемент массива по передаваемому индексу.
//! param array Структура динамического массива.
//! param index Индекс элемента, который нужно удалить.
void RemoveByIndex(DynamicArray* array, int index);

//! brief Удаляет значение элемента по его передаваемому значению.
//! param array Структура динамического массива.
//! param value Посылаемое значение, которое нужно удалить.
void RemoveByValue(DynamicArray* array, int value);

//! brief Сортирует массив.
//! param array Структура динамического массива.
void GnomeSort(DynamicArray* array);

//! brief Линейный поиск индекса элемента по передаваемому значению.
//! param array Структура динамического массива.
//! param value Значение, индекс которого нужно найти.
int LinerSearch(DynamicArray* array, int value);

//! brief Бинарный поиск индекса элемента по передаваемому значению.
//! param array Структура динамического массива.
//! param value Значение, индекс которого нужно найти.
int BinarySearch(DynamicArray* array, int value);

int Check(const std::string& Value);