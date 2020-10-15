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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ll numNums;
    ll diff;
    bool permuted, arith;
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
        cin >> numNums;
        vector<ll> numVector(numNums);
        for(j = 0; j < numNums; j++)
        {
            cin >> numVector[j];
        }
        permuted = true;
        arith = true;
        
        diff = numVector[1] - numVector[0];
        for(j = 1; j < numNums - 1; j++)
        {
            if((numVector[j+1] - numVector[j]) != diff)
            {
                arith = false;
            }
        }
        
        sort(numVector.begin(), numVector.end());
        
        diff = numVector[1] - numVector[0];
        for(j = 1; j < numNums - 1; j++)
        {
            if((numVector[j+1] - numVector[j]) != diff)
            {
                permuted = false;
            }
        }
        
        if(arith)
        {
            cout << "arithmetic\n";
        }
        else if(permuted)
        {
            cout << "permuted arithmetic\n";
        }
        else
        {
            cout << "non-arithmetic\n";
        }
    }
    
    return 0;
}
