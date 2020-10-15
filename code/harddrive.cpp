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
    ll size, changes, broken;
    cin >> size >> changes >> broken;
    vector<bool> bits(size, false);
    vector<bool> brokenBits(size, false);
    for(i = 0; i < broken; i++)
    {
    	ll thing;
    	cin >> thing;
    	brokenBits[thing-1] = true;
    }

    for(i = size-1; i > 0; i--)
    {
    	if(!brokenBits[i] && changes > 1)
    	{
    		bits[i] = true;
    		changes -= 2;
    		i--;
    	}
    }
    if(changes == 1)
    {
    	bits[0] = true;
    }


    for(i = 0; i < size; i++)
    {
    	if(bits[i])
    	{
    		cout << "1";
    	}
    	else
    	{
    		cout << "0";
    	}
    }
    cout << "\n";
    return 0;
}
