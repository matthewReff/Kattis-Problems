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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll process(ll input)
{
	if(input < 10)
	{
		return input;
	}
	else
	{
		vector<ll> vals;
		while(input != 0)
		{
			ll next = input % 10;
			input /= 10;
			if(next != 0)
			{
				vals.push_back(next);
			}
		}
		ll total = vals[0];
		for(ll i = 1; i < vals.size(); i++)
		{
			total *= vals[i];
		}
		return process(total);
	}
}


int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll input;
    cin >> input;
    cout << process(input) << "\n";


    return 0;
}
