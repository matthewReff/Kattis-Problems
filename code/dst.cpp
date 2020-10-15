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
typedef long double ld;
#define endl '\n'
#define pb push_back
#define EPSILON 0.000001

using namespace std;

void fastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

bool mySort(pair<int, int> a, pair<int, int>b) {
	return a.first < b.first;
}


int main()
{
	fastIO();

	ll cases, i, j, k;
	char type;
	ll leap, hour, minute;
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		cin >> type >> leap >> hour >> minute;
		if (type == 'B')
		{
			minute -= leap;
			while (minute < 0)
			{
				hour -= 1;
				minute += 60;
			}
			while (hour < 0)
			{
				hour += 24;
			}
			cout << hour << " " << minute << "\n";
		}
		else
		{
			minute += leap;
			while ((minute - 60) >= 0)
			{
				hour += 1;
				minute -= 60;
			}
			if (hour >= 24)
			{
				hour -= 24;
			}
			cout << hour << " " << minute << "\n";
		}
	}
	return 0;
}



