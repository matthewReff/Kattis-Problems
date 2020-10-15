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

	vector<string> vals(5);
	set<ll> answers;
	bool escaped = true;
	for (i = 0; i < 5; i++)
	{
		cin >> vals[i];
	}

	for (i = 0; i < 5; i++)
	{
		auto thing = vals[i].find("FBI");
		if (thing != string::npos)
		{
			answers.insert(i+1);
			escaped = false;
		}
	}

	if (escaped)
	{
		cout << "HE GOT AWAY!\n";
	}
	else
	{
		for (auto thing : answers)
		{
			cout << thing << " ";
		}
	}
		return 0;
}