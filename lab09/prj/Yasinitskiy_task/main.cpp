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
		cout << "¬вед≥ть j, z, x або c: ";
		cin >> data;

		switch (data) {
			case 'j':
				int x, y, z;
				cout << "¬вед≥ть x: ";
				cin >> x;
				cout << "¬вед≥ть y: ";
				cin >> y;
				cout << "¬вед≥ть z: ";
				cin >> z;
				cout << "s = " << s_calculation(x, y, z) << endl;
				break;
			case 'z':
				float value;
				Bonus bonus;
				cout << "¬вед≥ть суму покупки: ";
				cin >> value;
				bonus = getBonus(value);
				cout << " ≥льк≥сть бонус≥в: " << bonus.bonusBalance << ", сума до сплати з урахуванн€м знижки: " << bonus.discountedSum << endl;
				break;
			case 'x': {
				float farenheit;
				float celsius;

				cout << "¬вед≥ть к≥льк≥сть градус≥в за шкалою ‘аренгейта: ";
				cin >> farenheit;

				celsius = getCelsius(farenheit);

				cout << " ≥льк≥сть градус≥в за шкалою ÷ельс≥€: " << celsius << endl;
				break;
			}
			case 'c':
				int n;
				int result;
				cout << "¬вед≥ть N: ";
				cin >> n;
				result = t9_3(n);
				if (result == -1)
					cout << "¬ведено неправильн≥ дан≥." << endl;
				else
					cout << "–езультат: " << result << endl;
				break;
			default:
				cout << "\a¬ведено неправильн≥ дан≥." << endl;
		}

		cout << "¬вед≥ть v, V або A дл€ виходу ≥з програми: ";
		cin >> exit;

		if (tolower(exit) == 'v' || exit == 'A')
			break;
	}

	return 0;
}
