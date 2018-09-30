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


int main()
{
	int diameter, volume;
	double fullVolume;
	double removedVolume;
	double frustum;
	double leftSide;

	cin >> diameter >> volume;

	while (diameter != 0 && volume != 0)
	{
		cout << fixed << setprecision(10);
		leftSide = pow(diameter / 2.0, 3) * 2 * M_PI;
		leftSide -= volume;
		leftSide -= (M_PI * pow(diameter / 2.0, 3) * 2.0 / 3.0);
		leftSide /= (2.0 * M_PI);
		leftSide *= (3 / 2.0);
		leftSide = cbrt(leftSide);
		leftSide *= 2;
		cout << leftSide << "\n";
		cin >> diameter >> volume;
	}
	/*
	cout << (pow(frustum / 2.0, 2) * M_PI * frustum)
		+ ((M_PI * pow(diameter / 2.0, 2) * diameter / 3) -
		(M_PI * pow(frustum / 2.0, 2) * frustum / 3));
	
	*/
	return 0;
}