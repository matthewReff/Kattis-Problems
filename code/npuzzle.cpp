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
	ll scatter;
	ll total = 0;
	map < char, pair < int, int > > locations;
	vector<string > board(4);
	locations['A'] = make_pair(0, 0);
	locations['B'] = make_pair(0, 1);
	locations['C'] = make_pair(0, 2);
	locations['D'] = make_pair(0, 3);
	locations['E'] = make_pair(1, 0);
	locations['F'] = make_pair(1, 1);
	locations['G'] = make_pair(1, 2);
	locations['H'] = make_pair(1, 3);
	locations['I'] = make_pair(2, 0);
	locations['J'] = make_pair(2, 1);
	locations['K'] = make_pair(2, 2);
	locations['L'] = make_pair(2, 3);
	locations['M'] = make_pair(3, 0);
	locations['N'] = make_pair(3, 1);
	locations['O'] = make_pair(3, 2);

	for (i = 0; i < 4; i++)
	{
		cin >> board[i];
	}
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] != '.')
			{
				total += abs(i - locations[board[i][j]].first) + abs(j - locations[board[i][j]].second);
			}
		}
	}
	cout << total << "\n";
	
	
	return 0;
}
