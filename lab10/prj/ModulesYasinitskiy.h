#ifndef MODULESYASINITSKIY_H_INCLUDED
#define MODULESYASINITSKIY_H_INCLUDED

#include <string>

using namespace std;

float s_calculation(int, int, int);

typedef struct Bonus {
	int bonusBalance;
	float discountedSum;
} Bonus;

Bonus getBonus(float);

float getCelsius(float);

int t9_3(int);

int t10_1(string, string);

int t10_2(string);

int t10_3(string, int, int, int, int);

#endif // MODULESYASINITSKIY_H_INCLUDED
