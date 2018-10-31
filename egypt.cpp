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
	ll a, b, c;
	while (cin >> a >> b >> c && (a != 0 || b != 0 || c != 0))
	{
		vector<ll> tempVec;
		tempVec.push_back(a);
		tempVec.push_back(b);
		tempVec.push_back(c);
		sort(tempVec.begin(), tempVec.end());
		if (tempVec[0] * tempVec[0] + tempVec[1] * tempVec[1] == 
			tempVec[2] * tempVec[2] && a != 0 && b != 0 && c != 0)
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	return 0;
}
