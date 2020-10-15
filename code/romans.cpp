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
#include <set>

typedef long long ll;
using namespace std;

int main()
{
	ll i, j, k;
	cout << fixed << setprecision(0);
	double n;
	cin >> n;
	n *= 5280;
	n /= 4.854;
	cout << round(n) << "\n";
	return 0;
}
