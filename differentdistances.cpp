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
	long long i, j, k;
	double x1, y1, x2, y2, p;
	double leftSide, rightSide;

	while (cin >> x1 && x1 != 0)
	{
		cin >> y1 >> x2 >> y2 >> p;
		cout << fixed << setprecision(10);

		leftSide = pow(abs(x1 - x2), p);
		rightSide = pow(abs(y1 - y2), p);
		cout << pow((leftSide + rightSide), 1.0 / p) << "\n";
	}
	return 0;
}