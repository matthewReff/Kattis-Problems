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

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	ll capacity, stops;
	ll  left, entered, stayed;
	bool possible = true;
	ll currCap = 0;
	cin >> capacity >> stops;

	for (i = 0; i < stops; i++)
	{
		cin >> left >> entered >> stayed;
		currCap -= left;
		if (currCap < 0)
		{
			possible = false;
		}
		currCap += entered;
		if (currCap > capacity)
		{
			possible = false;
		}
		if (currCap != capacity && stayed > 0)
		{
			possible = false;
		}

	}
	if (currCap != 0)
	{
		possible = false;
	}
	if (possible)
	{
		cout << "possible\n";
	}
	else
	{
		cout << "impossible\n";
	}

		
	return 0;
}


