#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i, j, k;

	ll students, commands;
	ll loc = 0;
	ll num;
	cin >> students >> commands;

	stack<ll> s;
	string val;
	for (i = 0; i < commands; i++)
	{
		cin >> val;
		if (val == "undo")
		{
			cin >> num;
			for (j = 0; j < num; j++)
			{
				ll thing = s.top();
				s.pop();
				loc -= thing;
			}
		}
		else
		{
			ll thing = stoi(val);
			s.push(thing);
			loc += thing;
		}
		
	}
	loc += 1000 * students;
	cout << loc % students << "\n";
	return 0;
}