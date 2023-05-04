#ifndef STRUCT_TYPE_PROJECT_4_H_INCLUDED
#define STRUCT_TYPE_PROJECT_4_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

struct Media {
    wstring number;
    wstring type;
    wstring name;
    wstring date;
    wstring founders;
    wstring registrar;
};

extern vector<Media> medias;

#endif // STRUCT_TYPE_PROJECT_4_H_INCLUDED
