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

    ll numValues;
    cin >> numValues;
    vector<ll> values(numValues, -1);
    for(int i = 0; i < numValues; i++)
    {
    	cin >> values[i];
    }

    auto itr = values.rbegin();
    while(itr != values.rend())
    {
    	cout << *itr << "\n";
    	itr++;
    }
    return 0;
}
