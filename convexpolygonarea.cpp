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

const double EPSILON = 0.0001;


struct point
{
	long double x, y;
	point(long double x_ = 0, long double y_ = 0) : x(x_), y(y_) {}
	// Only < operator is unusual behavior
	bool operator <(const point& other) const
	{
		return (x < other.x ? true : (x == other.x && y < other.y));
	}
	bool operator == (const point& other) const
	{
		return abs(other.x - x) < EPSILON && abs(other.y - y) < EPSILON;
	}
	//Add other operators as needed
};

long double polyArea(const vector<point>& points)
{
	long double result = 0;
	for (int i = 0, j = 1; i<points.size(); i++, j = (j + 1) % points.size())
	{
		result += points[i].x * points[j].y;
		result -= points[i].y * points[j].x;
	}
	return result / 2;
}

int main()
{
	ll i, j, k;
	point temp;
	ll cases;
	ll pairs;

	
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		cin >> pairs;
		vector<point> points;
		for (j = 0; j < pairs; j++)
		{
			cin >> temp.x;
			cin >> temp.y;
			points.push_back(temp);
		}
		cout << polyArea(points) << "\n";
	}
	return 0;
}




