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
    ll strips;
    ll temp;
    cin >> cases;


    for(int i = 0; i < cases; i++)
    {
    	int total = 1;
    	cin >> strips;
    	for(int j = 0; j < strips; j++)
    	{
    		cin >> temp;
    		total += temp-1;
    	}
    	cout << total << "\n";
    }

    return 0;
}
