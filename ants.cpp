#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
     ll cases;
     ll length, ants;

     cin >> cases;
     for(i = 0; i < cases; i++)
     {
     	cin >> length >> ants;
     	ll least = 0;
     	ll most = 0;
     	ll temp;
     	for(j = 0; j < ants; j++)
     	{
     		cin >> temp;
     		least = max(least, min(length - temp, temp));
     		most = max(most, max(length - temp, temp));
     	}
     	cout << least << " " << most << "\n";
     }
    return 0;
}
