#include "DynamicArray.h"
#include <iostream>
#include <functional>
using namespace std;



DynamicArray createDynamicArray(int initialCapacity)
{
    DynamicArray dynamicArray;
    dynamicArray.Size = 0; // Изначально массив пуст
    dynamicArray.Capacity = initialCapacity;
    dynamicArray.Array = { new int[dynamicArray.Capacity] {} }; // Выделяем память
    dynamicArray.Size = dynamicArray.Capacity; // Устанавливаем размер

    return dynamicArray; // Возвращаем структуру
}

void AddElement(DynamicArray* array, int index, int value)
{
    
    array->Capacity += 2;
    int* newArray = new int[array->Capacity];
    for (int i = 0; i < array->Size; i++)
    {
        newArray[i] = array->Array[i];
    }

    delete[] array->Array;

    array->Array = newArray;

    for (int i = array->Size; i > index; --i) {
        array->Array[i] = array->Array[i - 1];
    }

    // Вставляем новый элемент
    array->Array[index] = value;

    // Увеличиваем размер массива
    array->Size++;
}

void RemoveByIndex(DynamicArray* array, int index)
{
    // Сдвигаем элементы влево, начиная с указанного индекса
    for (int i = index; i < array->Size - 1; ++i)
    {
        array->Array[i] = array->Array[i + 1];
    }

    // Уменьшаем размер массива
    array->Size--;
}

void RemoveByValue(DynamicArray* array, int value)
{
    int newSize = 0; // Новый размер массива после удаления
    for (int i = 0; i < array->Size; ++i) {
        // Если текущий элемент не равен значению для удаления,
        // копируем его на новое место в массиве
        if (array->Array[i] != value) {
            array->Array[newSize] = array->Array[i];
            newSize++;
        }
    }

    // Обновляем размер массива
    array->Size = newSize;
}

int GetIndex(DynamicArray* array, int index)
{
	return 0;
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void SortArray(DynamicArray* array)
{
    // Вложенная функция для быстрой сортировки
    function<void(int, int)> QuickSort = [&](int low, int high) {
        if (low < high) 
        {
            // Выбираем опорный элемент
            int pivot = array->Array[high];
            int i = (low - 1); // Индекс меньшего элемента

            for (int j = low; j < high; j++) {
                if (array->Array[j] <= pivot) {
                    i++;
                    Swap(array->Array[i], array->Array[j]);
                }
            }
            Swap(array->Array[i + 1], array->Array[high]); // Обмен опорного элемента
            int pi = i + 1;

            // Рекурсивно сортируем элементы до и после опорного элемента
            QuickSort(low, pi - 1);
            QuickSort(pi + 1, high);
        }
        };

    // Запускаем быструю сортировку с полным диапазоном массива
    QuickSort(0, array->Size - 1);
}

int LinerSearch(DynamicArray* array, int value)
{
    for (int i = 0; i < array->Size; i++)
    {
        if (array->Array[i] == value)
            cout << "искомый индекс " << i << endl;
    }
    return -1;
}

int BinarySearch(DynamicArray* array, int value)
{
    int l = 0;
    int r = array->Size;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (array->Array[mid] == value)
            cout << "искомый индекс " << mid << endl;

        if (array->Array[mid] < value)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
