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

    ll numEntries;
    ll numExits;

    cin >> numEntries >> numExits;

    vector<ll> entryTimes(numEntries);
    vector<ll> exitTimes(numExits);
  
    for(ll i = 0; i < numEntries; i++) {
        cin >> entryTimes[i];
    }

    for(ll i = 0; i < numExits; i++) {
        cin >> exitTimes[i];
    }

    map<ll, ll> differenceMap;
    for(vector<ll>::iterator entryIterator = entryTimes.begin(); entryIterator != entryTimes.end(); entryIterator++) {
      for(vector<ll>::iterator exitIterator = exitTimes.begin(); exitIterator != exitTimes.end(); exitIterator++) {
        ll entryTime = *entryIterator;
        ll exitTime = *exitIterator;

        ll difference = exitTime - entryTime;
        differenceMap[difference]++;
      }
    }

    ll mostMatches = -1;
    ll bestTime = 0;
    for(map<ll, ll>::iterator differenceIterator = differenceMap.begin(); differenceIterator != differenceMap.end(); differenceIterator++) {
      auto entry = *differenceIterator;
      ll matches = entry.second;
      ll difference = entry.first;

      if (difference >= 0 && matches > mostMatches) {
        mostMatches = matches;
        bestTime = difference;
      }
      if (difference >= 0 && matches == mostMatches) {
        bestTime = min(difference, bestTime);
      }
    }

    cout << bestTime << "\n";

    return 0;
}