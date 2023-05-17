#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <vector>
#include "ModulesYasinitskiy.h"

using namespace std;

int main() {
    bool inSoftware = false;
    struct stat sb;
    ofstream result;

    if (stat("../../TestSuite", &sb) == 0) // якщо у prj/Teacher
        result.open("../../TestSuite/TestResults.txt");
    else { // якщо у Software
        inSoftware = true;
        result.open("../TestSuite/TestResults.txt");
    }

    if (!result)
        return 1;

    string path = __FILE__;

    if (path.find("\\lab12\\prj") == string::npos) {
        for (int i = 0; i < 100; i++)
            cout << "\a";
        result << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        return 2;
    }

    ifstream testsuite;
    if (!inSoftware) //
        testsuite.open("../../TestSuite/unit.txt");
    else {
        inSoftware = true;
        testsuite.open("../TestSuite/unit.txt");
    }

    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    unsigned int lines = 0;
    bool firstLine = true;

    if (testsuite.is_open()) {
        while(getline(testsuite, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            }

            row.clear();

            stringstream str(line);

            while(getline(str, word, '\u0009'))
                row.push_back(word);
            content.push_back(row);
            lines++;
        }
    } else
        return 3;

    float height[lines];
    float radius[lines];
    float expectedVolume[lines];

    for (unsigned int i = 0; i < content.size(); i++) {
        height[i] = stof(content[i][0]);
        radius[i] = stof(content[i][1]);
        expectedVolume[i] = stof(content[i][2]);
    }

    ClassLab12_Yasinitskiy *classLab = new ClassLab12_Yasinitskiy(height[0], radius[0]);
    for (unsigned int i = 0; i < lines; i++) {
        float volume = classLab->getVolume();
        result << "Test " << i + 1 << " " << (volume == expectedVolume[i] ? "passed" : "failed") << endl;
        if (i + 1 != lines) {
            classLab->setHeight(height[i + 1]);
            classLab->setRadius(radius[i + 1]);
        }
    }
}
