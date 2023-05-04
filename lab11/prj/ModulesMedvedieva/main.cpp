#include <codecvt>
#include <fstream>
#include <sstream>
#include <string>
#include "ModulesMedvedieva.h"

using namespace std;

bool read(vector<Media> &vec, string file) {
    vector<vector<wstring>> content;
    vector<wstring> row;
    wstring line, word;

    wifstream data;
    data.open(file);

    data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    if (data.is_open()) {
        while(getline(data, line)) {
            row.clear();

            wstringstream str(line);

            while(getline(str, word, L'\u0009'))
                row.push_back(word);
            content.push_back(row);
        }
    } else
        return false;

    for (unsigned int i = 0; i < content.size(); i++) {
        vec.push_back({});
        Media& back = vec.back();
        back.number = content[i][0];
        back.type = content[i][1];
        back.name = content[i][2];
        back.date = content[i][3];
        back.founders = content[i][4];
        back.registrar = content[i][5];
    }

    return true;
}

bool save(vector<Media> &vec, string file) {
    wofstream data;
    data.open(file);

    data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    if (!data)
        return false;

    for (unsigned int i = 0; i < vec.size(); i++)
        data << vec[i].number << L'\u0009' << vec[i].type << L'\u0009' << vec[i].name << L'\u0009' << vec[i].date << L'\u0009' << vec[i].founders << L'\u0009' << vec[i].registrar << endl;

    return true;
}
