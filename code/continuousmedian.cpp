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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cases;
	ll listLength;
	ll thisVal;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
    	vector<ll> tempList;
    	cin >> listLength;
    	double total = 0;
    	for(int j = 0; j < listLength; j++)
    	{
    		cin >> thisVal;
    		tempList.push_back(thisVal);
    		if(tempList.size() % 2 == 0)
    		{
    			total += (tempList[tempList.size() / 2] +  tempList[tempList.size() / 2 - 1])  / 2;
    			cout << (tempList[tempList.size() / 2] +  tempList[tempList.size() / 2 - 1])  / 2 << "\n";
    		}
    		else
    		{
    			total += tempList[tempList.size() / 2];
    			cout << tempList[tempList.size() / 2] << "\n";
    			
    		}
    	}
    	cout << total << "\n";
    }

    return 0;
}
