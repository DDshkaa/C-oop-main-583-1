#include <iostream>
#include <string>
#include <chrono>
#include "List.h"

using namespace std;

//! \brief выводит меню команд для пользователя
void DisplayMenu()
{
	cout << "\nMenu: List\n";
	cout << "1. Remove element\n";
	cout << "2. Insert at beginning\n";
	cout << "3. Insert at end\n";
	cout << "4. Insert after element\n";
	cout << "5. Insert before element\n";
	cout << "6. Sort list\n";
	cout << "7. Linear search element\n";
	cout << "8. Running time for insert and delete operations\n";
	cout << "9. Exit\n";
}

//! \brief Проверяет, найден ли элемент по заданному индексу и выводит информацию о нем.
//! \param index Индекс, по которому проверяется наличие элемента.
//! \param value Значение элемента, которое будет выведено в случае успешного поиска.
void IndexCheck(int index, int value)
{
	if (index != -1)
	{
		cout << "Value " << value << " found\n";
		cout << "Index: " << index << endl;
	}
	else
	{
		cout << "Value " << value << " not found\n";
	}
}

//! \brief Запрашивает у пользователя ввод целого числа с проверкой корректности.
//! \param text Строка, содержащая текст запроса для пользователя.
//! \return Возвращает введенное пользователем целое число.
int GetInput(const string& text)
{
	int value;
	string input;

	while (true)
	{
		cout << text;
		getline(cin, input);

		try
		{
			value = stoi(input);
			return value;
		}

		catch (const invalid_argument& e)
		{
			cout << "Invalid input. Please enter an integer value.\n";
		}

		catch (const out_of_range& e)
		{
			cout << "Input is out of range. Please enter a valid integer value.\n";
		}
	}
}
//! \brief Измеряет время вставки заданного количества элементов в двусвязный список.
//! \param list Ссылка на двусвязный список, в который будут добавлены элементы.
//! \param numberOfElements Количество элементов, которые нужно добавить в список.
void MeasureInsertion(List& list, int numberOfElements)
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < numberOfElements; ++i)
	{
		InsertAtEnd(list, i);
	}
	auto end = chrono::steady_clock::now();
	cout << "Insertion for size " << numberOfElements << " took "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " microseconds.\n";
}
//! \brief Измеряет время удаления заданного количества элементов из двусвязного списка.
//! \param list Ссылка на двусвязный список, из которого будут удалены элементы.
//! \param numberOfElements Количество элементов, которые нужно удалить из списка.
void MeasureRemoval(List& list, int numberOfElements)
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < numberOfElements; ++i)
	{
		RemoveElement(list, i);
	}
	auto end = chrono::steady_clock::now();
	cout << "Removal for size " << numberOfElements << " took "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " microseconds.\n";
}

//! \brief Печатает элементы двусвязного списка.
//! \param list Константная ссылка на список, элементы которого нужно напечатать.
void PrintList(const List& list)
{
	ListItem* current = list.Head;
	while (current)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
}

int main()
{
	List list;
	
	while (true)
	{
		int choice;
		const int testSizes[] = {1, 500, 1000, 5000, 10000, 25000, 50000, 75000, 100000 };
		do
		{
			try
			{
				DisplayMenu();
				choice = GetInput("Choice an option: ");

				switch (choice)
				{
					case 1:
					{
						int value = GetInput("Enter value: ");
						RemoveElement(list, value);
						break;
					}

					case 2:
					{
						int value = GetInput("Enter value: ");
						InsertAtBeginning(list, value);
						break;
					}

					case 3:
					{
						int value = GetInput("Enter value: ");
						InsertAtEnd(list, value);
						break;
					}

					case 4:
					{
						int afterValue = GetInput("Enter after value: ");
						int value = GetInput("Enter value: ");
						InsertAfter(list, afterValue, value);
						break;
					}

					case 5:
					{
						int beforeValue = GetInput("Enter before value: ");
						int value = GetInput("Enter value: ");
						InsertBefore(list, beforeValue, value);
						break;
					}

					case 6:
					{
						SortList(list);
						break;
					}

					case 7:
					{
						int value = GetInput("Enter value: ");
						int index = LinearSearch(list, value);
						IndexCheck(index, value);
						break;
					}

					case 8:
					{
						for (int size : testSizes)
						{
							MeasureInsertion(list, size);
							MeasureRemoval(list, size);
						}
						break;
					}
					
					case 9:
						Cleanup(list);
						return 0;

					default:
						cout << "Invalid choice\n";
				}

				if (choice != 9)
				{
					PrintList(list);
				}
			}
			catch (runtime_error)
			{
				cout << "Value not found " << endl;
				PrintList(list);
			}

		} 
		while (choice != 9);
	}
}