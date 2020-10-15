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

    for(i = 0; i < cases; i++)
    {
    	ll trades;
    	cin >> trades;
    	string type, garb;
    	ll numShares, priceShares;
    	ll tradePrice = -1;
    	map<int, int, greater<int>> buyPrices;
    	map<int, int> sellPrices;
    	for(j = 0; j < trades; j++)
    	{
    		//input step
    		cin >> type >> numShares >> garb >> garb >> priceShares;
    		if(type == "buy")
    		{
    			buyPrices[priceShares] += numShares;
    		}
    		else
    		{
    			sellPrices[priceShares] += numShares;
    		}

    		//parse trades step
    		while(buyPrices.size() && sellPrices.size() && buyPrices.begin()->first >= sellPrices.begin()->first)
    		{
    			tradePrice = sellPrices.begin()->first;
    			ll transactionAmount = min(sellPrices.begin()->second, buyPrices.begin()->second);
    			sellPrices.begin()->second -= transactionAmount;
    			if(sellPrices.begin()->second == 0)
    			{
    				sellPrices.erase(sellPrices.begin());
    			}
    			buyPrices.begin()->second -= transactionAmount;
    			if(buyPrices.begin()->second == 0)
    			{
    				buyPrices.erase(buyPrices.begin());
    			}
    		}

    		//print step
    		if(sellPrices.size())
    		{
    			cout << sellPrices.begin()->first << " ";
    		}
    		else
    		{
    			cout << "-" << " ";
    		}

    		if(buyPrices.size())
    		{
    			cout << buyPrices.begin()->first << " ";
    		}
    		else
    		{
    			cout << "-" << " ";
    		}

    		if(tradePrice != -1)
    		{
    			cout << tradePrice << " ";
    		}
    		else
    		{
    			cout << "-" << " ";
    		}
    		cout << "\n";
    	}
    }
    return 0;
}
