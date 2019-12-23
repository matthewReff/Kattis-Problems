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

    string num1, num2;
    while(cin >> num1 >> num2 && (num1 != "0" || num2 != "0"))
    {
    	ll totalCarry = 0;
    	ll prevCarry = 0;

    	vector<ll> nums1(max(num1.size(), num2.size())+1, 0);
    	vector<ll> nums2(max(num1.size(), num2.size())+1, 0);

		reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());

    	for(i = 0; i < num1.size(); i++)
    	{
    		nums1[i] = (num1[i] -'0');
    	}
    	for(i = 0; i < num2.size(); i++)
    	{
    		nums2[i]=(num2[i] - '0');
    	}

    	nums1.push_back(0);
    	nums1.push_back(0);

    	nums2.push_back(0);
    	nums2.push_back(0);

    	for(i = 0; i < nums1.size(); i++)
    	{
    		ll sum = nums1[i] + nums2[i];
    		if(sum >= 10)
    		{
    			//cout << i << " " << sum << "\n";
    			prevCarry = sum/10;
    			nums1[i+1] += prevCarry;
    			totalCarry++;
    		}
    	}

    	if(totalCarry == 0)
    	{
    		cout << "No carry operation.\n";
    	}
    	else if(totalCarry == 1)
    	{
    		cout << "1 carry operation.\n";
    	}
    	else
    	{
    		cout << totalCarry << " carry operations.\n";
    	}
    	//cout << totalCarry << "\n";
    }
    
    return 0;
}
