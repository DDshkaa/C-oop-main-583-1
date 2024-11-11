// SDlaboratory1.cpp : Ётот файл содержит функцию "main". «десь начинаетс€ и заканчиваетс€ выполнение программы.
//

#include <iostream>
#include "DynamicArray.h"
using namespace std;



int main()
{
    int stop = 1;
    int element;
    int command;
    int removeValue;
    int removeIndex;
    int CertainElement;
    int index;
    setlocale(LC_ALL, "Russian");
    int initialCapacity = 2;
    // —оздаем динамический массив
    DynamicArray myArray = createDynamicArray(initialCapacity);

    // ¬ыводим элементы массива

    while (stop == 1)
    {
       
        cout << "Ёлементы массива: ";
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
        cout << "6. Sort array" << endl;
        cout << "7. Linear search for an element in an array" << endl;
        cout << "8. Binary search for an element in an array" << endl;
        cout << "9. End Programm" << endl << endl;
        cout << "Your input: ";
        cin >> command;
        if ((command > 0)&&(command < 11))
        {
            switch (command)
            {
            case 1:
                cout << "¬ведите индекс";
                cin >> removeIndex;
                RemoveByIndex(&myArray, removeIndex);
                break;
            case 2:
                cout << "¬ведите число";
                cin >> removeValue;
                RemoveByValue(&myArray, removeValue);
                break;
            case 3:
                cout << "¬ведите число";

                cin >> element;
                AddElement(&myArray, 0, element);
                break;
            case 4:
                cout << "¬ведите число";
                cin >> element;
                AddElement(&myArray, myArray.Size , element);
                break;
            case 5:  
                cout << "¬ведите число ";
                cin >> element;
                cout << endl << "¬ведите индекс элемента после которого нужно вставить число ";
                cin >> index;
                AddElement(&myArray, index + 1, element);
                break;
            case 6:
                SortArray(&myArray);
                break;
            case 7:
                cout << "¬ведите число";
                cin >> element;
                LinerSearch(&myArray, element);
                break;
            case 8:
                cout << "¬ведите число";
                cin >> element;
                BinarySearch(&myArray, element);
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
            cout << "неверна€ команда" << endl<< endl;
        }
        /*if (command <= 0 and command >= 10)
        {
            cout << "¬вел хуйню чел иди попей таблетки";
        }
        if (command == 1)
        {
            cout << "¬ведите индекс";
            int removeIndex;
            cin >> removeIndex;
            RemoveByIndex(&myArray, removeIndex);
        }
        if (command == 2)
        {
            int removeValue;
            cin >> removeValue;
            RemoveByValue(&myArray, removeValue);
        }
        if (command == 3)
        {
            cout << "¬ведите число";
            int Element;
            cin >> Element;
            AddElement(&myArray, 0 , Element);
        }
        if (command == 4)
        {
            cout << "¬ведите число";
            int Element;
            cin >> Element;
            AddElement(&myArray, -1, Element);
        }
        if (command == 5)
        {
            cout << "¬ведите число ";
            int CertainElement;
            int Element;
            cin >> Element;
            cout << endl << "¬ведите элемент после которого нужно вставить число ";
            cin >> CertainElement;
            AddElement(&myArray, GetIndex(&myArray, CertainElement)+1, Element);
        }
        if (command == 6)
        {
            SortArray(&myArray);
        }
        if (command == 7)
        {
            cout << "¬ведите число";
            int Element;
            cin >> Element;
            LinerSearch(&myArray, Element);
        }
        if (command == 8)
        {
            cout << "¬ведите число";
            int Element;
            cin >> Element;
            BinarySearch(&myArray, Element);
        }
        if (command == 9)
        {
            stop = 1;
        }*/
           
    }
}
