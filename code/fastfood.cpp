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

	ll cases;
	cin >> cases;

	ll numPrizes, numStickers;
	ll stickerCost;
	ll val;
	for(i = 0; i < cases; i++)
	{
		cin >> numPrizes;
		cin >> numStickers;
		vector<vector<ll>> prizeData(numPrizes);
		for(j = 0; j < numPrizes; j++)
		{
			cin >> stickerCost;
			for(k = 0; k < stickerCost; k++)
			{
				cin >> val;
				val--;
				prizeData[j].push_back(val);
			}
			cin >> val;
			prizeData[j].push_back(val);
		}

		vector<ll> stickers(numStickers);
		for(j = 0; j < numStickers; j++)
		{
			cin >> stickers[j];
		}

		ll totalMoney = 0;
		for(j = 0; j < numPrizes; j++)
		{
			ll thisAmount = 101;
			//cout << "thisAmount: " << thisAmount << "\n";
			for(k = 0; k < (int)prizeData[j].size() - 1; k++)
			{	
				thisAmount = min(thisAmount, stickers[prizeData[j][k]]);
				//cout << "stickersPull: " << stickers[prizeData[j][k]] << "\n";
				//cout << "thisAmount: " << thisAmount << "\n";
			}
			totalMoney += thisAmount * prizeData[j][prizeData[j].size() - 1];
			//cout << "\n";
		}
		cout << totalMoney << "\n";
	}    
    return 0;
}
