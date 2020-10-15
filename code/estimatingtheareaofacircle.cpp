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
	double num1, num2,num3;
	double sqArea, percent;
	cout << fixed << setprecision(8);
	while (cin >> num1 >> num2 >> num3)
	{
		if (num1 == 0 && num2 == 0 && num3 == 0)
		{
			return 0;
		}
		sqArea = pow((2 * num1), 2);
		percent = num3 / num2;
		cout << M_PI * pow(num1,2) << " " << sqArea * percent << "\n";
	}
	return 0;
}
