#include "DynamicArray.h"
#include <iostream>
#include <string>
using namespace std;



DynamicArray *СreateDynamicArray()
{
    //Создаем экземпляр структуры
    DynamicArray* dynamicArray = new DynamicArray;

    //Начальный размер массива равен 0
    dynamicArray->Size = 0;

    dynamicArray->Capacity = 0;

    //Выделяем память
    dynamicArray->Array = { new int[dynamicArray->Capacity] {} };

    dynamicArray->Size = dynamicArray->Capacity;

    return  dynamicArray;


}

void CheckRange(DynamicArray* array, int index)
{
    if (index < 0 || index > array->Size)
    {
        throw out_of_range("Index out of range");
    }
}

void AddElement(DynamicArray* array, int index, int value)
{
    CheckRange(array, index);

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
    CheckRange(array, index);

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
    for (int i = 0; i < array->Size; ++i) 
    {
        // Если текущий элемент не равен значению для удаления,
        // копируем его на новое место в массиве
        if (array->Array[i] != value) 
        {
            array->Array[newSize] = array->Array[i];
            newSize++;
        }
    }

    // Обновляем размер массива
    array->Size = newSize;
}


void GnomeSort(DynamicArray* array) 
{
    int index = 0;
    int size = array->Size; // Предполагается, что у вас есть поле size в структуре DynamicArray

    while (index < size) 
    {
        if (index == 0) 
        {
            index++; // Переход к следующему элементу
        }
        if (array->Array[index] >= array->Array[index - 1]) {
            index++; // Переход к следующему элементу
        }
        else {
            // Меняем местами элементы
            swap(array->Array[index], array->Array[index - 1]);
            index--; // Возврат к предыдущему элементу
        }
    }
}

int LinerSearch(DynamicArray* array, int value)
{
    for (int i = 0; i < array->Size; i++)
    {
        if (array->Array[i] == value)
            cout << "искомый индекс: " << i << endl;
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
            cout << "искомый индекс: " << mid << endl;

        if (array->Array[mid] < value)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int Check(const std::string& Value)
{
    try 
    {
        int command{ stoi(Value) };
        return command;
    }
    catch (...)
    {
        return -1;
    }
}

