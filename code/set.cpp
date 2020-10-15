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

	vector<string> cards(12);

	for(i = 0; i < 12; i++)
	{
		cin >> cards[i];
	}    

	bool foundOne = false;
	for(i = 0; i < 12; i++)
	{
		for(j = i + 1; j < 12; j++)
		{
			for(k = j + 1; k < 12; k++)
			{
				vector<set<int>> checker(4);
				for(int index = 0; index < 4; index++)
				{
					checker[index].insert(cards[i][index]);
					checker[index].insert(cards[j][index]);
					checker[index].insert(cards[k][index]);
				}
				bool valid = true;
				for(int index = 0; index < 4; index++)
				{
					if(checker[index].size() != 1 && checker[index].size() != 3)
					{
						valid = false;
					}
				}
				if(valid)
				{
					cout << i+1 << " " << j+1 << " " << k+1 << "\n";
					foundOne = true;
				}
				
			}
		}
	}

	if(!foundOne)
	{
		cout << "no sets\n";
	}
    return 0;
}
