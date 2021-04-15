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

    ll probs, solved;
    cin >> probs >> solved;

    ll diff, estimated;
    cin >> diff >> estimated;

    ll total = probs * diff;

    ll remaining = probs - solved;
    ll current = solved * estimated;

    if(total - current > 100 * remaining)
    {
    	cout << "impossible\n";
    }
    else
    {
    	cout << fixed << setprecision(10);
    	double val = (total - current) / double(remaining);
    	if(val >= 0 && val <= 100)
    	{
    		cout << val << "\n";
    	}
    	else
    	{
    		cout << "impossible\n";
    	}
    }

    return 0;
}
