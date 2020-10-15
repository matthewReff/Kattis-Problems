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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll modVal = 10000;
    ll left, right;
    vector<ll> vals(32);
    char op;

    while(cin >> left >> op >> right)
    {
    	left %= modVal;

    	switch(op)
    	{
    		case '+':
    		{
    			right %= modVal;
    			cout << (left + right) % modVal << "\n";
    			break;
    		}
    		case '*':
    		{
    			right %= modVal;
    			cout << (left * right) % modVal << "\n";
    			break;
    		}
    		case '^':
    		{
    			ll currentVal = 1;
    			vals[0] = left;
    			for(i = 1; i < 32; i++)
    			{
    				vals[i] = (vals[i-1] * vals[i-1]) % modVal;
    			}

    			for(i = 0; i < 32; i++)
    			{
    				if((right>>i & 1) == 1)
    				{
    					currentVal *= vals[i];
    					currentVal %= modVal;
    				}
    			}
    			cout << currentVal << "\n";
    			break;
    		}
    	}
    }
    return 0;
}
