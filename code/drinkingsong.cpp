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

    ll repeats;
    string drink;

    cin >> repeats >> drink;

    for(i = repeats; i > 1; i--)
    {
    	cout << i << " bottles of " << drink << " on the wall, " << i << " bottles of " << drink << ".\n";
    	if(i - 1 != 1)
    	{
		cout << "Take one down, pass it around, " << i-1 <<  " bottles of " << drink << " on the wall.\n\n";
		}
		else
		{
			cout << "Take one down, pass it around, " << 1 <<  " bottle of " << drink << " on the wall.\n\n";
		}
    }

    cout << "1 bottle of " << drink << " on the wall, 1 bottle of " << drink << ".\n";
	cout << "Take it down, pass it around, no more bottles of " << drink << ".\n";
    return 0;
}
