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
    cin >> num;
    vector<ll> nums(num);
    for(i = 0; i < num; i++)
    {
    	cin >> nums[i];
    }

    ll index = -1;
    ll minMax = 9999999;
    for(i = 0; i < num-2; i++)
    {
    	if(max(nums[i], nums[i+2]) < minMax)
    	{
    		minMax = max(nums[i], nums[i+2]);
    		index = i+1;
    	}
    }
    cout << index << " " << minMax << "\n";
    return 0;
}
