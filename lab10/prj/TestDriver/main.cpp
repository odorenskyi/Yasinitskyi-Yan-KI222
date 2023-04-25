#include "ModulesYasinitskiy.h"
#include <iostream>
#include <locale>
#include <fstream>
#include <codecvt>
#include <string>
#include <limits>

using namespace std;

string input = "input.txt";
string output = "output.txt";

bool createInput(wstring content) {
	wofstream data;
	data.open(input);

	data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	if (!data) {
		wcout << L"Помилка запису вхідних даних." << endl;
		return false;
	}

	data << content << endl;

	return true;
}

bool test1_1() {
	wstring line;
	wstring lines[3] = {L"Розробник: Yasinitskiy Yan", L"Установа/організація: Центральноукраїнський національний технічний університет", L"Рік розробки: 2023"};
	bool linesFound[3] = {false, false, false};
	int currentLine = 0;
	if(!createInput(L"тест"))
		return false;

	t10_1(input, output);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(lines[currentLine]) != wstring::npos) {
			linesFound[currentLine] = true;
			currentLine++;
		}
		if (linesFound[0] && linesFound[1] && linesFound[2])
			return true;
	}
	return false;
}

bool test1(wstring data, wstring modified, bool even) {
	wstring line;
	bool modifiedCorrect = false;

	if(!createInput(data))
		return false;

	t10_1(input, output);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(L"Речення: " + modified) != wstring::npos)
			modifiedCorrect = true;
		if (modifiedCorrect && ((even && line.find(L"Матері") != wstring::npos) || (!even && line.find(L"Вклонися їй") != wstring::npos)))
			return true;
	}

	return false;
}

bool test2_1() {
	wstring line;
	if(!createInput(L"тест"))
		return false;

	t10_2(input);

	wifstream indata;
	indata.open(input);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(L"Дата й час дозапису: ") != wstring::npos)
			return true;
	}

	return false;
}

bool test2(wstring data, wstring oddCharacters) {
	wstring line;
	if(!createInput(data))
		return false;

	t10_2(input);

	wifstream indata;
	indata.open(input);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
		if (line.find(L"Непарні символи речення: " + oddCharacters) != wstring::npos)
			return true;
	}

	return false;
}

bool test3(int x, int y, int z, int b, float s, wstring bin) {
	wstring line;
	bool firstValid = true;
	t10_3(output, x, y, z, b);

	wifstream indata;
	indata.open(output);

	indata.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	while (getline(indata,line)) {
        string s_str = to_string(s);
        wstring s_wstr (s_str.begin(), s_str.end());
		if (!firstValid && line.find(L"s = " + s_wstr) != wstring::npos)
			firstValid = true;
		else if (firstValid && line.find(L"b у двійковому коді: " + bin) != wstring::npos)
			return true;
	}

	return false;
}

int main() {
	const wstring data1_1[] = {L"Тест.", L"Тест123.", L"Непарне."};
    const wstring data1_2[] = {L"Тес?.", L"Тес?123.", L"Непарне."};
	bool even[] = {true, true, false};

	const wstring data2_1[] = {L"Тест.", L"Тест123.", L"Непарне."};
	const wstring data2_2[] = {L"Тс.", L"Тс13", L"Нпре"};

	const int x[] = {10, 0, 4, 4};
	const int y[] = {2, 1, 1, 0};
	const int z[] = {5, 1, 1, 0};
	const int b[] = {1, 3, 8, 15};
	const float s[] = {9.49993801116943359375, numeric_limits<float>::quiet_NaN(), 2.0536382198333740234375, 1};
	const wstring bin[] = {L"1", L"11", L"1000", L"1111"};

	setlocale(LC_ALL, "");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			bool value = false;
			if (i < 2 && j == 0) {
				if (i == 0)
					value = test1_1();
				else if (i == 1)
					value = test2_1();
			}
			else if (i == 0)
				value = test1(data1_1[j-1], data1_2[j-1], even[j-1]);
			else if (i == 1)
				value = test2(data2_1[j-1], data2_2[j-1]);
			else if (i == 2)
				value = test3(x[j], y[j], z[j], b[j], s[j], bin[j]);
			cout << "Test " << i + 1 << "." << j + 1 << " " << (value ? "passed" : "failed") << endl;
		}

	}

	return 0;
}
