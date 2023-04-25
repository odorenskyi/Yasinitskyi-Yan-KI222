#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <codecvt>
#include <bitset>
#include <limits>
#include "ModulesYasinitskiy.h"

using namespace std;

wstring letters = L"абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
wstring replacedLetters = L"ктУлЙ";

float s_calculation(int x, int y, int z) {
	if (x > 3)
		return pow(3*sin(sqrt(12*x+log10(x-3))), y)+(z/(float)x);
	else
		return NAN;
}

Bonus getBonus(float value) {
	Bonus bonus;
	bonus.bonusBalance = 0;

	if (value >= 100 && value < 200)
		bonus.bonusBalance = 1;
	else if (value >= 200 && value < 500)
		bonus.bonusBalance = 5;
	else if (value >= 500 && value < 1000)
		bonus.bonusBalance = 10;
	else if (value >= 1000 && value < 2500)
		bonus.bonusBalance = 50;
	else if (value >= 2500 && value < 5000)
		bonus.bonusBalance = 150;
	else if (value >= 5000)
		bonus.bonusBalance = 300;

	bonus.discountedSum = value - bonus.bonusBalance * 0.25;
	return bonus;
}

float getCelsius(float farenheit) {
	return (5.0/9)*(farenheit-32);
}

int t9_3(int number) {
	unsigned int count = 0;
	if (number > 0 || number <= 51950) {
		bool set = (number >> 4) & 1;
		while (number) {
			count += (number & 1) == set;
			number >>= 1;
		}
	} else {
		return -1;
	}
	return count;
}

int t10_1(string inputFile, string outputFile) {
	wstring line;
	int number = 0;
	wifstream indata;
	indata.open(inputFile);
	wofstream outdata;
	outdata.open(outputFile);

	if (!indata || !outdata)
		return 1;

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
	outdata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	outdata << L"Розробник: Yasinitskiy Yan" << endl << L"Установа/організація: Центральноукраїнський національний технічний університет" << endl << L"Місто: Кропивницький" << endl << L"Країна: Україна" << endl << L"Рік розробки: 2023" << endl << endl;

	outdata << L"Речення: ";

	while (getline(indata,line)) {
		for (unsigned int i = 0; i < line.length(); i++) {
			for (unsigned int j = 0; j < letters.length(); j++)
			{
				if (towlower(line[i]) == letters.at(j))
				{
					number += 1;
					for (unsigned int k = 0; k < replacedLetters.length(); k++)
						if (line[i] == replacedLetters.at(k))
							line[i] = L'?';
				}
			}
		}
		outdata << line << endl;
	}

	outdata << endl;

	if (number % 2 == 0)
		outdata << L"Матері" << endl << L"В хаті сонячній промінь косо" << endl << L"На долівку ляга з вікна..." << endl << L"Твої чорні шовкові коси" << endl << L"Припорошила вже сивина." << endl;
	else
		outdata << L"Вклонися їй" << endl << L"Коли малим ти вперше став на ноги -" << endl << L"Яка ж то радість матері була!" << endl << L"Від тихої колиски до порога" << endl << L"Вона тебе за руку провела." << endl;

	indata.close();
	outdata.close();

	return 0;
}

int t10_2(string file) {
	wstring line;
	wchar_t character;
	time_t rawtime;
	time(&rawtime);
	int number = 0;

	wifstream indata;
	indata.open(file);
	wofstream outdata;
	outdata.open(file, ios_base::app);

	if (!indata || !outdata)
		return 1;

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
	outdata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (indata >> character) {
		number += 1;
		if (number % 2 != 0)
			line += character;
	}

	outdata << endl << L"Непарні символи речення: " << line << endl;
	outdata << L"Дата й час дозапису: " << ctime(&rawtime);

	indata.close();
	outdata.close();

	return 0;
}

int t10_3(string file, int x, int y, int z, int b) {
	time_t rawtime;
	time(&rawtime);

	ofstream data;
	data.open(file, ios_base::app);

	if (!data)
		return 1;

	data << endl << "s = " << s_calculation(x, y, z) << endl;
	if (b > 0) {
		string binary = bitset<numeric_limits<int>::digits>(b).to_string();
		binary.erase(0, binary.find_first_not_of('0'));
		data << "b у двійковому коді: " << binary << endl;
	}
	else
		data << "b — не натуральне число" << endl;

	data.close();
	return 0;
}
