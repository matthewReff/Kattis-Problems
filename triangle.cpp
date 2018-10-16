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


int main()
{
	ll i, j, k;
	i = 0;
	while (cin >> j)
	{
		i++;
		cout << "Case " << i << ": ";
		cout << ceil(log10(3) + log10(1.5) * j) << "\n";
	}
	return 0;
}




