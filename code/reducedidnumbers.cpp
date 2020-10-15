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
    
    ll numIds;
    ll m = 0;
    ll temp;
    set<ll> usedMods;
    bool found;
    
    cin >> numIds;
    vector<ll> idVector(numIds);
   
    for(i = 0; i < numIds; i++)
    {
        cin >> idVector[i];
    }
    
    while(!found)
    {
        m++;
        found = true;
        usedMods.clear();
        for(i = 0; found && i < numIds; i++)
        {
            temp = idVector[i] % m;
            if(usedMods.find(temp) == usedMods.end())
            {
                usedMods.insert(temp);
            }
            else
            {
                found = false;
            }
        }
    }
    
    cout << m << "\n";
    return 0;
}
