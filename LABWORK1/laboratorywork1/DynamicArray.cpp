#include "DynamicArray.h" 
#include <stdexcept> 

using namespace std;

void Resize(DynamicArray* array, int capacity)
{
	int* newArray = new int[capacity];
	for (int i = 0; i < array->Size; ++i)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;
	array->Array = newArray;
	array->Capacity = capacity;
}


DynamicArray* CreateArray()
{
	DynamicArray* array = new DynamicArray;
	
	array->Size = 0;
	
	array->Capacity = InitialCapacity;
	
	array->Array = new int[array->Capacity];
	
	return array;
};


int CheckRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->Size)
	{
		throw out_of_range("");
	}
}

void AddElement(DynamicArray* array, int index, int value)
{
	CheckRange(array, index);


	if (array->Size >= array->Capacity)
	{
		Resize(array, array->Capacity * GrowthFactor);
	}
	for (int i = array->Size; i > index; --i)
	{
		array->Array[i] = array->Array[i - 1];
	}
	array->Array[index] = value;
	++array->Size;
};

void RemoveByIndex(DynamicArray* array, int index)
{
	CheckRange(array, index);

	for (int i = index; i < array->Size; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Size--;

	if (array->Size < array->Capacity / GrowthFactor && array->Capacity > InitialCapacity)
	{
		Resize(array, array->Capacity / GrowthFactor);
	}
}

void RemoveByValue(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i)
	{
		if (array->Array[i] == value)
		{
			RemoveByIndex(array, i);
			--i;
		}
	}
}

int GetElement(DynamicArray* array, int index)
{
	CheckRange(array, index);
	return array->Array[index];
}

void GnomikSort(DynamicArray* array) 
{
	int index = 0;

	while (index < array->Size) 
	{
		if (index == 0 || array->Array[index] >= array->Array[index - 1])
		{
			index++;
		}
		else 
		{
			swap(array->Array[index], array->Array[index - 1]);
			index--;
		}
	}
}

int LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i)
	{
		if (array->Array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(DynamicArray* array, int value)
{
	GnomikSort(array);
	int left = 0;
	int right = array->Size - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (array->Array[mid] == value)
		{
			return mid;
		}
		if (value < array->Array[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

void FreeArray(DynamicArray* array)
{
	delete[] array->Array;
	delete array;
}