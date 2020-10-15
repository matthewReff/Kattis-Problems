#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll shapes;
	cin >> shapes;
	cout << fixed << setprecision(10);

	double sides, length, expands, expandLength;
	for(i = 0; i < shapes; i++)
	{
		cin >> sides >> length >> expands >> expandLength;
		double basePolygon = ((sides * length * length)) / (4 * tan(M_PI / sides))	;
		double addedRectangles = sides * length * expands * expandLength;
		double addedPartialCircles = ((180 - (sides - 2) * 180.0 / sides) / 360.0) *
			 M_PI * pow((expands * expandLength), 2) * sides;
		//cout << basePolygon << "\n";
		//cout << addedRectangles << "\n";
		//cout << addedPartialCircles << "\n";
		cout << basePolygon + addedRectangles + addedPartialCircles << "\n";
	}    
    return 0;
}
