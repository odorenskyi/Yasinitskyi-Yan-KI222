#include <iostream>
#include <cctype>
#include <clocale>
#include "ModulesYasinitskiy.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	while (true) {
		char data;
		char exit;
		cout << "Введіть j, z, x або c: ";
		cin >> data;

		switch (data) {
			case 'j':
				int x, y, z;
				cout << "Введіть x: ";
				cin >> x;
				cout << "Введіть y: ";
				cin >> y;
				cout << "Введіть z: ";
				cin >> z;
				cout << "s = " << s_calculation(x, y, z) << endl;
				break;
			case 'z':
				float value;
				Bonus bonus;
				cout << "Введіть суму покупки: ";
				cin >> value;
				bonus = getBonus(value);
				cout << "Кількість бонусів: " << bonus.bonusBalance << ", сума  сплати з урахуванням знижки: " << bonus.discountedSum << endl;
				break;
			case 'x': {
				float farenheit;
				float celsius;

				cout << "Введіть кількість  градусів за шкалою Фаренгейта: ";
				cin >> farenheit;

				celsius = getCelsius(farenheit);

				cout << "Кількість градусів за шкалою цельсія: " << celsius << endl;
				break;
			}
			case 'c':
				int n;
				int result;
				cout << "Введіть N: ";
				cin >> n;
				result = t9_3(n);
				if (result == -1)
					cout << "Введено неправильні дані." << endl;
				else
					cout << "Результат: " << result << endl;
				break;
			default:
				cout << "\aВведено неправильні дані." << endl;
		}

		cout << "Введіть v, V або A для виходу із програми: ";
		cin >> exit;

		if (tolower(exit) == 'v' || exit == 'A')
			break;
	}

	return 0;
}
