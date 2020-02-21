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

	vector<string> board(7);
	vector<pair<ll, ll>> offSets = {make_pair(2, 0), make_pair(0, 2),
		make_pair(-2, 0), make_pair(0, -2)};

	string thisLine;
	for(i = 0; i < 7; i++)
	{
		getline(cin, thisLine);
		board[i] = thisLine;
	}    

	ll moves = 0;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			if(board[i][j] == 'o')
			{
				for(k = 0; k < 4; k++)
				{
					ll newRow = i + offSets[k].first;
					ll newCol = j + offSets[k].second;
					if(newRow >= 0 && newRow < 7 && newCol >= 0 && newCol < 7)
					{
						if(board[newRow][newCol] == '.' && board[i + offSets[k].first / 2][j + offSets[k].second / 2] == 'o')
						moves++;
					}
				}
			}
		}
	}

	cout << moves << "\n";
    return 0;
}
