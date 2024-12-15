#include <iostream> 
#include "DynamicArray.h" 
using namespace std;

//! \brief функция получения значения 
//! \param const string& ссылка на строку, которая не сможет быть изменена 
//! \param concl для вывода на экран строки 
int GetInput(const string& concl)
{
    int value;
    cout << concl;
    cin >> value;
    return value;
}

//! \brief функция получения индекса 
//! \param index показывает индекс элемента 
void CheckIndex(int index)
{
    if (index > -1)
    {
        cout << "Index found: " << index << endl;
    }
    else
    {
        cout << "Value index not found " << endl;
    }
}


int main()
{
    DynamicArray* meinArray = CreateArray();

    //! \brief реализация меню с выводом текущего массива 
    //! \param true выполняет работу пока значение имеется 
    while (true)
    {
        cout << "Current array\n";
        for (int i = 0; i < meinArray->Size; i++)
        {
            cout << meinArray->Array[i] << " ";
        }
        cout << endl;
        cout << endl;

        cout << "Menu: \n";
        cout << "1. Delete by index \n";
        cout << "2. Delete by value \n";
        cout << "3. Add to beggining \n";
        cout << "4. Add to end \n";
        cout << "5. Add after \n";
        cout << "6. Sort array \n";
        cout << "7. Linnear search \n";
        cout << "8. Binnary search \n";
        cout << "9. End \n";

        int choice = GetInput("Your input: ");

        try
        {
            if ((choice > 0) && (choice < 10))
            {
                switch (choice)
                {
                case 1:
                {
                    int index = GetInput("Enter the index to delete: ");
                    RemoveByIndex(meinArray, index);
                    break;
                }

                case 2:
                {
                    int value = GetInput("Enter the value to delete: ");
                    RemoveByValue(meinArray, value);
                    break;
                }

                case 3:
                {
                    int value = GetInput("Enter the element to add at the beginning: ");
                    AddElement(meinArray, 0, value);
                    break;
                }

                case 4:
                {
                    int value = GetInput("Enter the element to add at the end: ");
                    AddElement(meinArray, meinArray->Size, value);
                    break;
                }

                case 5:
                {
                    int index = GetInput("Enter index to add: ");
                    int value = GetInput("Enter the element to add after a certain one: ");
                    AddElement(meinArray, index, value);
                    break;
                }

                case 6:
                {
                    GnomikSort(meinArray);
                    cout << "The array is sorted." << endl;
                    break;
                }

                case 7:
                {
                    int value = GetInput("Enter a value for a linear search: ");
                    int index = LinearSearch(meinArray, value);
                    CheckIndex(index);
                    break;
                }

                case 8:
                {
                    int value = GetInput("Enter a value for a binary search: ");
                    int index = BinarySearch(meinArray, value);
                    CheckIndex(index);
                    break;
                }

                case 9:
                    FreeArray(meinArray);
                    return 0;
                default:
                    cout << "Error " << endl;
                }
            }

        }
        catch (...)
        {
            cout << "Invalid command or index out of range." << endl << endl;
        }
    }
}