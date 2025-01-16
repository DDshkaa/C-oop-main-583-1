#include <iostream>
#include <string>
#include <limits>
#include "Stack.h"
#include "CircleBuffer.h"
#include "Queue.h"
#include "StackQueue.h"

using namespace std;

//! \brief функция получения значения 
//! \param const string& ссылка на строку, которая не сможет быть изменена 
//! \param text для вывода на экран строки
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
			cout << "\nInvalid input. Please enter an integer value.\n\n";
		}

		catch (const out_of_range& e)
		{
			cout << "\nInput is out of range. Please enter a valid integer value.\n\n";
		}
	}
}
//! \brief Функция для отображения элементов стека.
//! \param stack Указатель на экземпляр Stack, элементы которого будут отображены.
void DisplayStack(Stack* stack)
{
	cout << "Stack elements:\n";
	for (int i = stack->Top; i >= 0; i--)
	{
		cout << stack->Data[i] << " ";
	}
	cout << "\n";
}

//! \brief Меню для работы со стеком.
void StackMenu(Stack* stack)
{
	while (true)
	{
		cout << "\n";
		DisplayStack(stack);
		cout << "\n";
		int choice = GetInput("Stack menu: \n 1. Add element\n 2. Delete element\n \
3. Is empty\n 4. Resize\n 0. exit\n Your input: ");
		cout << "\n";
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");
				Push(stack, value);
				break;
			}
			case 2:
			{
				if (!IsEmpty(stack))
				{
					int value = Pop(stack);
					cout << "Removed element: " << value << endl;
				}
				else
				{
					cout << "Stack is empty.\n";
				}
				break;
			}
			case 3:
			{
				if (IsEmpty(stack))
				{
					cout << "Stack is empty.\n";
				}
				else
				{
					cout << "Stack is not empty.\n";
				}
				break;
			}
			case 4:
			{
				int value = GetInput("Enter new size: ");
				Resize(stack, value);
				break;
			}
			case 0:
				return;
			default:
				cout << "Error: Invalid choice.\n";
		}
	}
}

//! \brief Отображает элементы кругового буфера.
//! \param buffer Указатель на экземпляр CircleBuffer, который будет отображен.
void DisplayBuffer(CircleBuffer* buffer)
{
	int current = buffer->Head;
	do
	{
		cout << buffer->Buffer[current] << " ";
		current = (current + 1) % buffer->BufferSize;
	} 
	while (current != buffer->Tail);
	cout << endl;
}

//! \brief Меню для работы с круговым буфером.
//! \param buffer Указатель на экземпляр CircleBuffer, с которым будет работать меню.
void BufferMenu(CircleBuffer* buffer)
{

	while (true)
	{
		cout << "\n";
		cout << "Buffer elements: ";
		cout << "\n";
		if (OccupiedSpace(buffer) != 0)
		{ 
			DisplayBuffer(buffer);	
		}
		cout << "\n";
		int choice = GetInput("Buffer menu: \n 1. Add element\n 2. Remove element\n \
3. Get free space\n 4. Get space\n 0. Exit\n Your input: ");
		cout << "\n";
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");
				try
				{
					AddElement(buffer, value);
				}

				catch (const overflow_error& e)
				{
					cout << e.what() << endl;
				}

				break;
			}
			case 2:
			{
				if (Remove(buffer))
				{
					cout << "Element removed.\n";
				}
				else
				{
					cout << "Buffer is empty.\n";
				}

				break;
			}
			case 3:
			{
				cout << "Free space: " << FreeSpace(buffer) << endl;
				break;
			}
			case 4:
			{
				cout << "Occupied space: " << OccupiedSpace(buffer) << endl;
				break;
			}

			case 0:
				return;
			default:
				cout << "Error: Invalid choice.\n";
		}
	}
}

//! \brief Отображает элементы очереди.
//! \param queue Указатель на экземпляр структуры Queue, которую нужно отобразить.
void DisplayQueue(Queue* queue)
{
	DisplayBuffer(queue->Cbuffer);
}

//! \brief Меню для работы с очередью.
//! \param queue Указатель на экземпляр структуры Queue, с которой будет работать меню.
void QueueMenu(Queue* queue)
{
	while (true)
	{
		cout << "\n";
		cout << "Queue elements: ";
		cout << "\n";
		if (OccupiedSpace(queue->Cbuffer) != 0)
		{
			DisplayQueue(queue);
		}
		cout << "\n";
		int choice = GetInput("Queue menu: \n 1. Add element\n 2. Remove element\n\
 0. Exit\n Your input: ");
		cout << "\n";
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");
				if (OccupiedSpace(queue->Cbuffer) == 5)
				{
					cout << "No free space for element\n";
					break;
				}
				Enqueue(queue, value);
				break;
			}
			case 2:
			{
				if (Dequeue(queue))
				{
					cout << "Element removed.\n";
				}
				else
				{
					cout << "Queue is empty.\n";
				}
				break;
			}

			case 0:
				return;
			default:
				cout << "Error: Invalid choice.\n";
		}
	}
}

//! \brief Печатает элементы стека для очереди.
//! \param stack Указатель на экземпляр структуры Stack, который нужно вывести.
void PrintStackForQueue(Stack* stack) 
{
	if (stack == nullptr)
	{
		cout << "Stack is null." << endl;
		return;
	}

	if (IsEmpty(stack))
	{
		cout << "Stack is empty." << endl;
		return;
	}

	Stack* temp = CreateStack();

	while (!IsEmpty(stack)) 
	{
		int value = Pop(stack);
		cout << value << " ";
		Push(temp, value);
	}
	cout << endl;

	while (!IsEmpty(temp))
	{
		Push(stack, Pop(temp));
	}

	Delete(temp);
}

//! \brief Отображает содержимое стека очереди.
//! \param queue Указатель на экземпляр структуры StackQueue, содержимое
//! которого нужно отобразить.
void DisplayStackQueue(StackQueue* queue)
{
	cout << "InStack: ";
	PrintStackForQueue(queue->Stack1);

	cout << "OutStack: ";
	PrintStackForQueue(queue->Stack2);
}

//! \brief Меню для работы с очередью на основе стеков.
//! \param queue Указатель на экземпляр структуры StackQueue, 
//! с которой будет работать меню.
void StackQueueMenu(StackQueue* sque)
{
	while (true)
	{
		cout << "\n";
		DisplayStackQueue(sque);
		cout << "\n";
		int choice = GetInput("Queue menu: \n 1. Add element\n 2. Remove element\n \
0. Exit\n Your input: ");
		cout << "\n";
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");

				EnqueueStackQueue(sque, value);
				break;
			}

			case 2:
			{
				int value = DequeueStackQueue(sque);
				if (value != -1)
				{
					cout << "Removed element: " << value << endl;
				}
				else
				{
					cout << "Queue is empty!" << endl;
				}
				break;
			}

			case 0:
				return;

			default:
				cout << "Error: Invalid choice." << endl;
		}
	}
}


int main()
{
	Stack* stack = CreateStack();
	CircleBuffer* buffer = CreateCircleBuffer();
	Queue* queue = CreateQueueByBuffer();
	StackQueue* sque = CreateStackQueue();
	while (true)
	{
		int choice = GetInput("\nMenu: \n 1. Stack\n 2. Buffer\n 3. Queue\n \
4. Stack queue\n 0. End\n Your input: ");
		switch (choice)
		{
			case 1:
				StackMenu(stack);
				break;

			case 2:
				BufferMenu(buffer);
				break;

			case 3:
				QueueMenu(queue);
				break;

			case 4:
				StackQueueMenu(sque);
				break;

			case 0:
				Delete(stack);
				FreeBuffer(buffer);
				FreeQueue(queue);
				FreeStackQueue(sque);
				return 0;
				break;

			default:
				cout << "Error: Invalid choice." << endl;
		}
	}
	return 0;
}