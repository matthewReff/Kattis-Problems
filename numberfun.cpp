#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;

int main() {
	int sets;
	double num1, num2, num3;
	bool poss;
	cin >> sets;
	for (int i = 0; i < sets; i++)
	{
		poss = false;
		cin >> num1 >> num2 >> num3;
		if ((num1 + num2) == num3)
		{
			poss = true;
		}
		if ((num1 + num2) == num3)
		{
			poss = true;
		}
		if ((num1 - num2) == num3)
		{
			poss = true;
		}
		if ((num2 - num1) == num3)
		{
			poss = true;
		}
		if ((num1 * num2) == num3)
		{
			poss = true;
		}
		if ((num1 / num2) == num3)
		{
			poss = true;
		}
		if ((num2 / num1) == num3)
		{
			poss = true;
		}
		if (poss)
		{
			cout << "possible\n";
		}
		else
		{
			cout << "impossible\n";
		}
	}
	return 0;
}
