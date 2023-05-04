#include <codecvt>
#include <locale>
#include <iostream>
#include "ModulesYasinitskyi.h"
#include "ModulesMedvedieva.h"
#include "ModulesLytvyn.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    wcin.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    vector<Media> medias;

    read(medias, "data.tsv");

    while (true) {
        int choice;

        wcout << L"Електронний реєстр друкованих ЗМІ та інформаційних агентств" << endl <<
            L"1. Пошук запису" << endl <<
            L"2. Виведення реєстру на екран" << endl <<
            L"3. Зберігання реєстру у заданий файл" << endl <<
            L"4. Додавання нового запису до реєстру" << endl <<
            L"5. Вилучення запису із реєстру" << endl <<
            L"6. Завершення роботи програми і запис даних" << endl <<
            L"Введіть необхідну дію: ";

        wcin >> choice;
        wcin.ignore();
        switch (choice) {
            case 1:
            {
                wstring record;
                wcout << L"Введіть серію та номер видання або його назву: ";
                getline(wcin, record);
                search(medias, record);
                break;
            }
            case 2:
            {
                output(medias);
                break;
            }
            case 3:
            {
                wstring path;
                wcout << L"Введіть шлях до файла: ";
                getline(wcin, path);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
                string converted_path = converter.to_bytes(path);
                save(medias, converted_path);
                break;
            }
            case 4:
            {
                wstring number;
                wstring type;
                wstring name;
                wstring date;
                wstring founders;
                wstring registrar;

                wcout << L"Введіть серію та номер видання: ";
                getline(wcin, number);
                wcout << L"Введіть вид видання: ";
                getline(wcin, type);
                wcout << L"Введіть назву видання: ";
                getline(wcin, name);
                wcout << L"Введіть дату реєстрації: ";
                getline(wcin, date);
                wcout << L"Введіть відомості про засновників: ";
                getline(wcin, founders);
                wcout << L"Введіть орган, який здійснив реєстрацію: ";
                getline(wcin, registrar);
                add(medias, number, type, name, date, founders, registrar);
                break;
            }
            case 5:
            {
                wstring record;
                wcout << L"Введіть серію та номер видання або його назву: ";
                getline(wcin, record);
                remove(medias, record);
                break;
            }
            case 6:
            {
                save(medias, "data.tsv");
                return 0;
            }
            default:
                wcout << L"Помилкові дані." << endl;
        }
    }
}
