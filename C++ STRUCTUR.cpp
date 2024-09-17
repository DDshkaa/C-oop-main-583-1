/* #include <iostream>
using namespace std;
void Breakpoints()
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

	// Инициализация массива значениями с клавиатуры
	cout << "Введите 8 символов:\n";
	for (int i = 0; i < 8; i++) {
		cin >> array[i];
	}

	// Вывод исходного массива на экран
	cout << "Исходный массив: ";
	for (int i = 0; i < 8; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	// Вывод символов от 'a' до 'z'
	cout << "Буквы от 'a' до 'z': ";
	for (int i = 0; i < 8; i++) {
		if (array[i] >= 'a' && array[i] <= 'z') {
			cout << array[i] << ' ';
		}
	}
	cout << endl;

	return 0;
}*/

/*#include <iostream>

using namespace std;
double GetPower(double base, int exponent) {
	double result = 1.0;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}
int main() {
	setlocale(LC_ALL, "ru");
	double base1 = 2.0;
	int exponent1 = 3;
	cout << base1 << " ^ " << exponent1 << " = " << GetPower(base1, exponent1) << endl;

	double base2 = 5.0;
	int exponent2 = 2;
	cout << base2 << " ^ " << exponent2 << " = " << GetPower(base2, exponent2) << endl;

	double base3 = 3.0;
	int exponent3 = 0;
	cout << base3 << " ^ " << exponent3 << " = " << GetPower(base3, exponent3) << endl;

	return 0;
}*/

#include <iostream>
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
}
