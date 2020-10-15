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
    
    ll best;
    bool runoff = false;
    map<string, int> votes;
    string person;
    string bestPerson;
    while(getline(cin, person) && person != "***")
    {
        votes[person]++;
    }
    
    map<string, int>::iterator itr = votes.begin();
    best = 0;
    while(itr != votes.end())
    {
        if(itr->second == best)
        {
            runoff = true;
        }
        else if (itr->second > best)
        {
            best = itr->second;
            bestPerson = itr->first;
            runoff = false;
        }
        itr++;
    }
    
    
    if(runoff)
    {
        cout << "Runoff!\n";
    }
    else
    {
        cout << bestPerson << "\n";
    }
    return 0;
}
