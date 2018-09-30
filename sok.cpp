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
	
	double a, b, c;
	double d, e, f;
	vector<double> ratios;
	ratios.resize(3);

	double ing1, ing2, ing3;
	double ratio1, ratio2, ratio3;

	cin >> a >> b >> c;
	cin >> d >> e >> f;

	cout << fixed << setprecision(10);

	ratios[0] = a / d;
	ratios[1] = b / e;
	ratios[2] = c / f;

	ratio1 = a / d;
	ratio2 = b / e;
	ratio3 = c / f;

	sort(ratios.begin(), ratios.end());

	a -= (d * ratios[0]);
	b -= (e * ratios[0]);
	c -= (f * ratios[0]);

	cout << a << " " << b << " " << c << "\n";
	return 0;
}