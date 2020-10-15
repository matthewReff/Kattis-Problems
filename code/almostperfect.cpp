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

    ll num;
    while(cin >> num)
    {
    	ll total = 1;
    	ll maxVal = sqrt(num);
    	for(i = 2; i <= maxVal; i++)
    	{
    		if(num % i == 0)
    		{
    			total += i;
    			//cout << i << ", ";
    			if(i != num/i)
    			{
    				total += num/i;
    				//cout << num/i << "\n";
    			}
    		}
    	}
    	//cout << total << "\n";
    	cout << num << " ";
    	if(total == num)
    	{
    		cout << "perfect\n";
    	}
    	else if(abs(num - total) <= 2)
    	{
    		cout << "almost perfect\n";
    	}
    	else
    	{
    		cout << "not perfect\n";
    	}
    }
    
    return 0;
}
//Start: Wed Jan 29 09:31:46 MST 2020
//Stop: Wed Jan 29 09:45:26 MST 2020
