#include <cmath>
#include <string>
#include "ModulesYasinitskiy.h"

using namespace std;

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
