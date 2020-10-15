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

    vector<ll> amounts(2, 0);
	string thisSword;
	ll numSwords;

	cin >> numSwords;
	for(i = 0; i < numSwords; i++)
	{
		cin >> thisSword;
		for(j = 0; j < 4; j++)
		{
			if(thisSword[j] == '0')
			{
				amounts[j/2]++;
			}
		}
	}

	ll newSwords = min(amounts[0]/2, amounts[1]/2);
	cout << newSwords << " " << amounts[0] - 2 * newSwords << " " << amounts[1] - 2 * newSwords << "\n";    
    return 0;
}
