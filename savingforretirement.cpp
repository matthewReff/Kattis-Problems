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
	ll i, j, k, l;
	
	ll b, br, bs, a, as;
	ll numToBeat;

	cin >> b >> br >> bs >> a >> as;

	numToBeat = (br - b) * bs;

	cout << a + 1 + (numToBeat / as);
	return 0;
}