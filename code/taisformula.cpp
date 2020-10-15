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
    ll samples;
    ld time;
    ld value;
    ld total = 0;
    vector<pair<ll, ld>> sampleVector;
    pair<ll, ld> temp;
    
    cout << fixed << setprecision(10);
    cin >> samples;
    for(i = 0; i < samples; i++)
    {
        cin >> temp.first;
        cin >> temp.second;
        temp.first;
        sampleVector.push_back(temp);   
    }
    
    for(i = 0; i < samples - 1; i++)
    {
        total += ((sampleVector[i].second + sampleVector[i+1].second) / 2) * (sampleVector[i+1].first - sampleVector[i].first);
    }
    
    cout << total/1000 << "\n";
    return 0;
}
