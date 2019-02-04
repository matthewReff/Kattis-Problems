#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>-
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
#include <unordered_set>
#include <bitset>

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
	int i, j, k;
	

	ll n;
	ll moveCounter = 0;
	stack<ll> mainStack;
	stack<ll> auxStack;
	ll boundsChecker;
	ll matchesFound = 0;
	cin >> n;
	vector<ll> socks(2*n);
	for (i = 0; i < 2*n; i++)
	{
		cin >> socks[i];
	}

	for (i = 0; i < 2 * n; i++)
	{
		mainStack.push(socks[i]);
	}

	while (mainStack.size() > 0)
	{
		if (auxStack.size() && mainStack.top() == auxStack.top())
		{
			
			mainStack.pop();
			auxStack.pop();
			matchesFound++;
		}
		else
		{
			auxStack.push(mainStack.top());
			mainStack.pop();
		}
		moveCounter++;
	}

	if (matchesFound == n)
	{
		cout << moveCounter << "\n";
	}
	else
	{
		cout << "impossible\n";
	}

	return 0;
}
