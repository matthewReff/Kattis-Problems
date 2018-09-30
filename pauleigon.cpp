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

	ll n, p, q;
	ll num;

	cin >> n >> p >> q;
	num = (p + q) % (2 * n);
	if (num >= n)
	{
		cout << "opponent\n";
	}
	else
	{
		cout << "paul\n";
	}
	return 0;
}