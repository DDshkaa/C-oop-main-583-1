 #include <iostream>
using namespace std;
/*void Breakpoints()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; 
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl ;
}
int main()
{
	Breakpoints();
}*/


/*#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int values[10] = { 5, 2, 9, 1, 5, 6, 3, 8, 7, 4 };

	cout << "Исходный массив: ";
	for (int i = 0; i < 10; ++i) {
		cout << values[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {
			if (values[j] > values[j+1]) {
				int temp = values[j];
				values[j] = values[j+1];
				values[j+1] = temp;

			}
		}
	}
		
	for (int i = 0; i < 10; ++i) {
		cout << values[i] << " ";
	}
		

	return 0;
}*/

/*#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	float values[12] = { 5.4, 2.2, 9.6, 1.9, -5.4, 6.0, 3.123, 8.43, 7.31, 4.55, 111.6, -11.5 };

	cout << "Исходный массив: ";
	for (int i = 0; i < 10; ++i) {
		cout << values[i] << " ";
	}
	cout << endl;
	float searchingValue;
	int elements = 0;
	cin >> searchingValue;
	for (int i = 0; i < 12; i++) {
		if (searchingValue >= values[i]) {
			elements += 1;
		}
	}
	cout << elements;
}*/

/*#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	char array[8];


	cout << "Введите 8 символов:\n";
	for (int i = 0; i < 8; i++) {
		cin >> array[i];
	}

	cout << "Исходный массив: ";
	for (int i = 0; i < 8; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	cout << "Буквы от 'a' до 'z': ";
	for (int i = 0; i < 8; i++) {
		if (array[i] >= 'a' && array[i] <= 'z') {
			cout << array[i] << ' ';
		}
	}
	cout << endl;

	return 0;
}*/

//#include <iostream>
//
//using namespace std;
//double GetPower(double base, int exponent) {
//	double result = 1.0;
//	for (int i = 0; i < exponent; i++) {
//		result *= base;
//	}
//	return result;
//}
//int main() {
//	setlocale(LC_ALL, "ru");
//	double base1 = 2.0;
//	int exponent1 = 3;
//	cout << base1 << " ^ " << exponent1 << " = " << GetPower(base1, exponent1) << endl;
//
//	double base2 = 5.0;
//	int exponent2 = 2;
//	cout << base2 << " ^ " << exponent2 << " = " << GetPower(base2, exponent2) << endl;
//
//	double base3 = 3.0;
//	int exponent3 = 1;
//	cout << base3 << " ^ " << exponent3 << " = " << GetPower(base3, exponent3) << endl;
//
//	return 0;
//}

/* #include <iostream>
#include <cmath> 
using namespace std;

double GetPower(double base, int exponent) {
	return pow(base, exponent);
}


void DemoGetPower(double base, int exponent) {
	double result = GetPower(base, exponent);
	cout << base << " ^ " << exponent << " = " << result << endl;
}

int main() {
	DemoGetPower(2.0, 3);
	DemoGetPower(5.0, 2);
	DemoGetPower(10.0, 0);

	return 0;
}*/

//#include <iostream>
//
//using namespace std;
//
//void RoundToTens(int& value) {
//	int remainder = value % 10; // Находим остаток от деления на 10
//	if (remainder < 5) {
//		value = (value / 10) * 10; // Округляем вниз
//	}
//	else {
//		value = (value / 10 + 1) * 10; // Округляем вверх
//	}
//}
//
//int main() {
//	int a;
//
//	// Пример 1
//	a = 14;
//	cout << "For " << a << " rounded value is ";
//	RoundToTens(a);
//	cout << a << endl;
//
//	// Пример 2
//	a = 191;
//	cout << "For " << a << " rounded value is ";
//	RoundToTens(a);
//	cout << a << endl;
//
//	// Пример 3
//	a = 27;
//	cout << "For " << a << " rounded value is ";
//	RoundToTens(a);
//	cout << a << endl;
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//int a = 5;
//int b = 4;
//cout << "Address of a: " << &a << endl;
//cout << "Address of b: " << &b << endl;
//
// double c = 13.5;
//cout << "Address of c: " << &c << endl;
//
//bool d = true;
//cout << "Address of d: " << &d << endl;
//}


//int main()
//{
//int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
//cout << "Size of int type: " << sizeof(int) << endl;
//
//for (int i = 0; i < 10; i++)
//{
//cout << "Address of a[" << i << "]: " << &a[i] << endl;
//}
//
//cout << endl;
//cout << "Size of double type: " << sizeof(double) << endl;
//double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
//for (int i = 0; i < 10; i++)
//{
//cout << "Address of b[" << i << "]: " << &b[i] << endl;
//}
//}

//int main()
//{
//int a = 5;
//int& b = a;
//
//cout << "Address of a: " << &a << endl;
//cout << "Address of b: " << &b << endl;
//
//
//cout << endl;
//b = 7;
//cout << "Value of a: " << a << endl;
//}

//void Foo(double& a)
//{
//cout << "Address of a in Foo(): " << &a << endl;
//cout << "Value of a in Foo(): " << a << endl;
//
//a = 15.0;
//cout << "New value of a in Foo(): " << a << endl;
//}
//
//int main()
//{
//double a = 5.0;
//cout << "Address of a in main(): " << &a << endl;
//cout << "Value of a in main(): " << a << endl;
//cout << endl;
//
//Foo(a);
//
//cout << endl;
//cout << "Value of a in main(): " << a << endl;
//}

//int main()
//{
//int a = 5;
//int* pointer = &a;
//
//cout << "Address of a: " << &a << endl;
//cout << "Address in pointer: " << pointer << endl;
//cout << "Address of pointer: " << &pointer << endl;
//
//cout << endl;
//* pointer = 7;
//cout << "Value in a: " << a << endl;
//cout << "Value by pointer address: " << *pointer << endl;
//}

//void Foo(double* a)
//{
//cout << "Address in pointer: " << a << endl;
//cout << "Address of pointer: " << &a << endl;
//cout << "Value in pointer address: " << *a << endl;
//
//
//* a = 15.0;
//cout << "New value in pointer address: " << *a << endl;
//}
//
//int main()
//{
//double value = 5.0;
//double* pointer = &value;
//cout << "Address of value in main(): " << &value << endl;
//cout << "Address in pointer in main(): " << pointer << endl;
//cout << "Address of pointer in main(): " << &pointer << endl;
//cout << "Value of a in main(): " << value << endl;
//cout << endl;
//
//Foo(pointer);
//
//cout << endl;
//cout << "Value of a in main(): " << value << endl;
//}

//int main()
//{
//	float* arr = new float[8];
//	arr[0] = 1.0;// а мог с клавиатуры))
//	arr[1] = 15.0;
//	arr[2] = -8.2;
//	arr[3] = -3.5;
//	arr[4] = 12.6;
//	arr[5] = 38.4;
//	arr[6] = -0.5;
//	arr[7] = 4.5;
//	for (int i = 0; i < 8; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	delete[] arr;
//	return 0;
//}

//int main()
//{
//	bool* arr = new bool[8];
//	arr[0] = true;
//	arr[1] = false;
//	arr[2] = true;
//	arr[3] = true;
//	arr[4] = false;
//	arr[5] = true;
//	arr[6] = false;
//	arr[7] = false;
//	for (int i = 0; i < 8; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	delete[] arr;
//	return 0;
//}

//int main()
//{
//	int n;
//	cout << "enter size n ";
//	cin >> n;
//	char* arr = new char[n];
//	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		cout << arr[i] << " ";
//	}
//    delete[] arr;
//	return 0;
//}

//void bubblesort(double* arr)
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				double temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	double* arr = new double[10];
//	arr[0] = 1.0;
//	arr[1] = 15.0;
//	arr[2] = -8.2;
//	arr[3] = -3.5;
//	arr[4] = 12.6;
//	arr[5] = 38.4;
//	arr[6] = -0.5;
//	arr[7] = 4.5;
//	arr[8] = 16.7;
//	arr[9] = 4.5;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	bubblesort(arr);
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	delete[] arr;
//	return 0;
//}

//int indexElementsArray(int* arr, int el)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		if (el == arr[i])
//		{
//			return i;
//		}
//	}
//}
//int main()
//{
//	int el;
//	cin >> el;
//	int* arr = new int[10];
//	arr[0] = 1;
//	arr[1] = 15;
//	arr[2] = -8;
//	arr[3] = -3;
//	arr[4] = 12;
//	arr[5] = 38;
//	arr[6] = 0;
//	arr[7] = 4;
//	arr[8] = 16;
//	arr[9] = 4;
//	int index = indexElementsArray(arr, el);
//	cout << index;
// 	delete[] arr;
//	return 0;
//}

//int SumLetter(char* arr)
//{
//	int sum = 0;
//	for (int i = 0; i < 15; i++)
//	{
//		if (arr[i] >= 'a' && arr[i] <= 'z')
//		{
//			sum += 1;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	char* arr = new char[15]{'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k'}; // только сейчас понял, что можно и так
//	for (int i = 0; i < 15; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	int sum = SumLetter(arr);
//	cout << sum;
//	delete[] arr;
//	return 0;
//}

//#include <cstdlib> // для rand()
//
//// Функция для создания массива случайных чисел
//int* MakeRandomArray(int arraySize)
//{
//	int* arr = new int[arraySize];
//
//	for (int i = 0; i < arraySize; i++)
//	{
//		arr[i] = rand() % 101;
//	}
//	return arr;
//}
//int main()
//{
//	int sizeFive = 5;
//	int sizeEight = 8;
//	int sizethirteen = 13;
//
//	int* arrFive = MakeRandomArray(sizeFive);
//	int* arrEight = MakeRandomArray(sizeEight);
//	int* arrthirteen = MakeRandomArray(sizethirteen);
//	cout << "array size 5:" << endl;
//	for (int j = 0; j < sizeFive; j++)
//	{
//		cout << arrFive[j] << " ";
//	}
//	cout << endl;
//	cout << "array size 8:" << endl;
//	for (int j = 0; j < sizeEight; j++)
//	{
//		cout << arrEight[j] << " ";
//	}
//	cout << endl;
//	cout << "array size 13:" << endl;
//	for (int j = 0; j < sizethirteen; j++)
//	{
//		cout << arrthirteen[j] << " ";
//	}
//	delete[] arrFive;
//	delete[] arrEight;
//	delete[] arrthirteen;
//	return 0;
//}

//#include <iostream> 
//using namespace std;
//
//int* ReadArray(int count) {
//	int* values = new int[count];
//	for (int i = 0; i < count; i++) {
//		cin >> values[i];
//	}
//	return values;
//}
//
//int CountPositiveValues(int* values, int count) {
//	int result = 0;
//	for (int i = 0; i < count; i++) {
//		if (values[i] > 0) {
//			result++;
//		}
//	}
//	return result;
//}
//
//int main() {
//	int count = 15;
//	int* values = ReadArray(count);
//	cout << "Count is: " << CountPositiveValues(values, count) << endl;
//
//	// Освобождаем память перед переназначением указателя
//	delete[] values;
//
//	count = 20;
//	values = ReadArray(count);
//	cout << "Count is: " << CountPositiveValues(values, count) << endl;
//
//	// Освобождаем память после использования
//	delete[] values;
//
//	return 0;
//}

#include <iostream>
#include <string>

struct Person {
	std::string FirstName;
	std::string LastName;
	int Age;
};

const int PeopleCount = 5;

Person** CreatePeopleArray() {
	Person** people = new Person * [PeopleCount];

	people[0] = new Person{ "Casey", "Aguilar", 30 };
	people[1] = new Person{ "Brock", "Curtis", 19 };
	people[2] = new Person{ "Blake", "Diaz", 21 };
	people[3] = new Person{ "Cristian", "Evans", 55 };
	people[4] = new Person{ "Les", "Foss", 4 };

	return people;
}

void ClearPeople(Person** people, int itemsCount) {
	for (int i = 0; i < itemsCount; i++) {
		delete people[i];
	}
	delete[] people;
}

void WritePerson(Person* person) {
	std::cout << "First Name: " << person->FirstName
		<< "; Last Name: " << person->LastName
		<< "; Age: " << person->Age << std::endl;
}

void Task1_FindPersonByLastName() {
	Person** people = CreatePeopleArray();

	for (int i = 0; i < PeopleCount; i++) {
		WritePerson(people[i]);
	}

	std::string lastName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;

	int foundIndex = -1;

	for (int i = 0; i < PeopleCount; i++) {
		if (people[i]->LastName == lastName) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex == -1) {
		std::cout << "Could not find a person by last name: " << lastName << std::endl;
	}
	else {
		std::cout << "A person's last name " << lastName
			<< " was found. Its index in the array is " << foundIndex << std::endl;
	}

	ClearPeople(people, PeopleCount);
}

int main() {
	Task1_FindPersonByLastName();
	return 0;
}






