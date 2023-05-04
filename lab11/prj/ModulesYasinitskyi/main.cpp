#include <iostream>
#include <string>
#include "ModulesYasinitskyi.h"

using namespace std;

void add(vector<Media> &vec, wstring number, wstring type, wstring name, wstring date, wstring founders, wstring registrar) {
    vec.push_back({});
    Media& back = vec.back();
    back.number = number;
    back.type = type;
    back.name = name;
    back.date = date;
    back.founders = founders;
    back.registrar = registrar;
}

void remove(vector<Media> &vec, wstring record) {
    bool found = false;
    for (vector<Media>::iterator it = vec.begin(); it != vec.end();) {
        if (it->number == record || it->name == record) {
            found = true;
            it = vec.erase(it);
        } else
            ++it;
    }

    if (found)
        wcout << L"Видалено." << endl;
    else
        wcout << L"Не знайдено." << endl;
}
