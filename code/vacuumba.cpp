#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <math.h>

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	double angle, distance;
	double angleRad;

	ll cases;
	ll steps;
	cin >> cases;

	cout << fixed << setprecision(4);

	for (i = 0; i < cases; i++)
	{
		cin >> steps;
		double X = 0.0;
		double Y = 0.0;
		double lastAngle = M_PI / 2;
		for (j = 0; j < steps; j++)
		{
			cin >> angle >> distance;
			angleRad = (angle * M_PI / 180);
			angleRad = fmod((lastAngle + angleRad), 360.0);
			lastAngle = angleRad;
			X += cos(angleRad) * distance;
			Y += sin(angleRad) * distance;
		}
		cout << X << " " << Y << "\n";
	}
	
	return 0;
}




