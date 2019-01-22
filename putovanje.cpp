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
    
    ll n, c;
    ll currentCapacity;
    ll fruitsEaten;
    ll maxFruitsEaten = 0;
    cin >> n >> c;
    vector<ll> fruits(n);
    
    for(i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }
    
    for(i = 0; i < n; i++)
    {
        fruitsEaten = 0;
        currentCapacity = 0;
        for(j = i; j < n; j++)
        {
            if(currentCapacity + fruits[j] <= c)
            {
                currentCapacity += fruits[j];
                fruitsEaten++;
            }
        }
        if(fruitsEaten > maxFruitsEaten)
        {
            maxFruitsEaten = fruitsEaten;
        }
    }
    
    cout << maxFruitsEaten << "\n";
    return 0;
}
