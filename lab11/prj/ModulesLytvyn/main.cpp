#include <iostream>
#include <string>
#include "ModulesLytvyn.h"

using namespace std;

void search(vector<Media> &vec, wstring record) {
    bool found = false;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i].number == record || vec[i].name == record) {
            found = true;
            wcout << vec[i].number << L'\u0009' << vec[i].type << L'\u0009' << vec[i].name << L'\u0009' << vec[i].date << L'\u0009' << vec[i].founders << L'\u0009' << vec[i].registrar << endl;
        }
    }
    if (!found)
        wcout << L"Не знайдено." << endl;
}

void output(vector<Media> &vec) {
    for (unsigned int i = 0; i < vec.size(); i++)
        wcout << vec[i].number << L'\u0009' << vec[i].type << L'\u0009' << vec[i].name << L'\u0009' << vec[i].date << L'\u0009' << vec[i].founders << L'\u0009' << vec[i].registrar << endl;
}
