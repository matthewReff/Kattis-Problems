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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ll p, n, m;
map<string, int> scores;
set<string> names;

	cin >> n >> p >> m;


	for(i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		scores[name] = 0;
	}
	for(j = 0; j < m; j++)
	{
		string name;
		int score;
		cin >>	name >> score;
		scores[name] += score;
		if(scores[name] >= p)
		{
			if(names.find(name) == names.end())
			{
				cout << name << " wins!\n";
				names.insert(name);
			}
		}
	}
	if(names.size() == 0)
	{
		cout << "No winner!\n";
	}
    return 0;
}
