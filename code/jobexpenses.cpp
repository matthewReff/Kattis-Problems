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
    ll numNumbers;
    ll currentNum;
    ll total = 0;
    cin >> numNumbers;
    
    for(i = 0; i < numNumbers; i++)
    {
    	cin >> currentNum;
    	if(currentNum < 0)
    	{
    		total += abs(currentNum);
    	}
    	
    }
    
    cout << total;
    return 0;
}
