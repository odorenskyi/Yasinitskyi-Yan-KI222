#include "ModulesYasinitskiy.h"
#include <iostream>
#include <clocale>
#include <limits>

using namespace std;

bool test_1(float value, int bonusBalance, float discountedSum) {
	Bonus bonus = getBonus(value);
	if (bonus.bonusBalance == bonusBalance && bonus.discountedSum == discountedSum)
		return true;
	else
		cout << endl << "Очікуваний результат: Кількість бонусів: " << bonusBalance << ", сума до сплати з урахуванням знижки: " << discountedSum << endl << "Отриманий результат: Кількість бонусів: " << bonus.bonusBalance << ", сума до сплати з урахуванням знижки: " << bonus.discountedSum << endl;
	return false;
}

bool test_2(float farenheit, float celsius) {
	float result = getCelsius(farenheit);
	if (result == celsius)
		return true;
	else
		cout << endl << "Очікуваний результат: " << celsius << endl << "Отриманий результат: " << result << endl;
    return false;
}

bool test_3(int n, int count) {
	int result = t9_3(n);
	if (result == count)
		return true;
	else {
		cout << endl << "Очікуваний результат: " << count << endl << "Отриманий результат: " << result << endl;
		return false;
	}
}

int main() {
	float value[5] = {10, 100, 1000, 2500, 5000};
	int bonusBalance[5] = {0, 1, 50, 150, 300};
	float discountedSum[5] = {10, 99.75, 987.5, 2462.5, 4925};

	float farenheit[5] = {0, 5, 15, 100, 200};
	float celsius[5] = {-17.7777786254883, -15, -9.44444465637207, 37.7777786254883, 93.3333358764648};

	int n[5] = {0, 10, 15, 16, 31};
	int result_3[5] = {0, 2, 0, 1, 5};

	cout.precision(std::numeric_limits<double>::digits10);

	setlocale(LC_ALL, "");

	for (int i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				for (int j = 0; j < 5; j++) {
					cout << "Test " << i + 1 << "." << j + 1 << " (сума покупки: " << value[j] << ", кількість бонусів: " << bonusBalance[j] << ", сума до сплати з урахуванням знижки: " << discountedSum[j] << ") " << (test_1(value[j], bonusBalance[j], discountedSum[j]) ? "passed" : "failed") << endl;
				}
				break;
			case 1:
				for (int j = 0; j < 5; j++) {
					cout << "Test " << i + 1 << "." << j + 1 << " (за шкалою Фаренгейта: " << farenheit[j] << ", за шкалою Цельсія: " << celsius[j] << ") " << (test_2(farenheit[j], celsius[j]) ? "passed" : "failed") << endl;
				}
				break;
			case 2:
				for (int j = 0; j < 5; j++) {
					cout << "Test " << i + 1 << "." << j + 1 << " (n = " << n[j] << ", результат = " << result_3[j] << ") " << (test_3(n[j], result_3[j]) ? "passed" : "failed") << endl;
				}
				break;
		}

	}

	return 0;
}
