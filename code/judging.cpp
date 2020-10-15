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
    map<string, int> kattis;
    map<string, int> DOM;
    map<string, int>::iterator kattisIterator;
    map<string, int>::iterator DOMIterator;
    ll problems;
    ll possibleAgreed = 0;
    string temp;
     
    cin >> problems;
    for(i = 0; i < problems; i++)
    {
        cin >> temp;
        kattis[temp]++;
    }
    for(i = 0; i < problems; i++)
    {
        cin >> temp;
        DOM[temp]++;
    }
    
    DOMIterator = DOM.begin();
    
    while(DOMIterator != DOM.end())
    {
        kattisIterator = kattis.find(DOMIterator->first);
        if (kattisIterator != kattis.end())
        {
            possibleAgreed += min(kattisIterator->second, DOMIterator->second);
        }
        DOMIterator++;
    }   
        
    cout << possibleAgreed << "\n";
    return 0;
}
