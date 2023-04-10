#ifndef MODULESYASINITSKIY_H_INCLUDED
#define MODULESYASINITSKIY_H_INCLUDED

float s_calculation(int, int, int);

typedef struct Bonus {
	int bonusBalance;
	float discountedSum;
} Bonus;

Bonus getBonus(float);

float getCelsius(float);

int t9_3(int);

#endif // MODULESYASINITSKIY_H_INCLUDED
