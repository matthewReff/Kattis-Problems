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
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;
	ll m, p, l, e, r, s, n;
	ll temp;

	while (cin >> m)
	{
		cin >> p >> l >> e >> r >> s >> n;
		for (i = 0; i < n; i++)
		{
			temp = m;
			m = p / s;
			p = l / r;
			l = temp * e;
		}

		cout << m << "\n";
	}

	return 0;
}