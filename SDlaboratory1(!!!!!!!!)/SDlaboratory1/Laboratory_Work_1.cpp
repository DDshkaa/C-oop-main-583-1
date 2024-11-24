

#include <iostream>
#include "DynamicArray.h"
#include <string>
using namespace std;



int main()
{
    int stop = 1;
    string element;
    string commandstr;
    string removeValue;
    string removeIndex;
    string index;
    setlocale(LC_ALL, "Russian");
    DynamicArray myArray = *СreateDynamicArray();


    while (stop == 1)
    {
       
        cout << "Элементы массива: ";
        for (int i = 0; i < myArray.Size; ++i) {
            cout << myArray.Array[i] << " ";
        }
        cout << endl << endl;

        cout << "Select the action you want to do:" << endl;
        cout << "1. Remove an element by index from an array" << endl;
        cout << "2. Remove an element by value from an array" << endl;
        cout << "3. Insert an element at the beginning" << endl;
        cout << "4. Insert an element at the end" << endl;
        cout << "5. Insert after a certain element" << endl;
        cout << "6. Sort array(Gnomik)" << endl;
        cout << "7. Linear search for an element in an array" << endl;
        cout << "8. Binary search for an element in an array" << endl;
        cout << "9. End Programm" << endl << endl;
        cout << "Your input: ";
        cin >> commandstr;
        
        try
        {
            int command{ stoi(commandstr) };
            if ((command > 0) && (command < 10))
            {
                switch (command)
                {
                case 1:

                    cout << "Введите индекс: ";
                    cin >> removeIndex;
                    if (Check(removeIndex) != -1)
                    {
                        int RemoveIndex = Check(removeIndex);
                        RemoveByIndex(&myArray, RemoveIndex);
                    }

                    else if (Check(removeIndex) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }

                    break;
                case 2:

                    cout << "Введите число: ";
                    cin >> removeValue;
                    if (Check(removeValue) != -1)
                    {
                        int RemoveValue = Check(removeValue);
                        RemoveByValue(&myArray, RemoveValue);
                    }

                    else if (Check(removeValue) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }

                    break;
                case 3:

                    cout << "Введите число: ";
                    cin >> element;
                    if (Check(element) != -1)
                    {
                        int Element = Check(element);
                        AddElement(&myArray, 0, Element);
                    }

                    else if (Check(element) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }
                    
                    break;
                case 4:

                    cout << "Введите число ";
                    cin >> element;
                    if (Check(element) != -1)
                    {
                        int Element = Check(element);
                        AddElement(&myArray, myArray.Size, Element);
                    }

                    else if (Check(element) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }
                    
                    break;
                case 5:

                    cout << "Введите число: ";
                    cin >> element;
                    cout << endl << "Введите индекс элемента после которого нужно вставить число ";
                    cin >> index;
                    if ((Check(element) != -1) && (Check(index) != -1))
                    {
                        int Element = Check(element);
                        int Index = Check(index);
                        AddElement(&myArray, Index + 1, Element);

                    }

                    else if ((Check(element) == -1) || (Check(index) == -1))
                    {
                        cout << "неверная команда " << endl;
                    }

                    break;
                case 6:

                    GnomeSort(&myArray);
                    break;

                case 7:

                    cout << "Введите число: ";
                    cin >> element;
                    if (Check(element) != -1)
                    {
                        int Element = Check(element);
                        LinerSearch(&myArray, Element);
                    }

                    else if (Check(element) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }
                    
                    break;
                case 8:

                    cout << "Введите число: ";
                    cin >> element;
                    if (Check(element) != -1)
                    {
                        int Element = Check(element);
                        BinarySearch(&myArray, Element);
                    }

                    else if (Check(element) == -1)
                    {
                        cout << "неверная команда " << endl;
                    }

                    break;
                case 9:

                    stop = 0;
                    break;

                default:
                    break;
                }

            }
            else
            {
                cout << "неверная команда" << endl << endl;
            }
        }
        catch (...)
        {
            cout << "неверная команда" << endl << endl;
        }
    }
}
