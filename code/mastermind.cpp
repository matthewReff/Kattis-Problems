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
    
    ll letters;
    ll exact = 0;
    ll similar = 0;
    string guess, key;
    map<char, int> tracker;

    
    cin >> letters >> key >> guess;
    vector<bool> matched(letters, false);
    for(auto element : key)
    {
        tracker[element]++;
    }
    
    for(i = 0; i < key.size(); i++)
    {
        if (key[i] == guess[i])
        {
            exact++;
            tracker[key[i]]--;
            matched[i] = true;
        }
    }
    
    for(i = 0; i < key.size(); i++)
    {
        if (tracker.find(guess[i]) != tracker.end() && tracker[guess[i]] > 0 && !matched[i])
        {
            similar++;
            tracker[guess[i]]--;
        }
    }

    cout << exact << " " << similar << "\n";
    return 0;
}
