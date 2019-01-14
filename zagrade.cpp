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
    
    ll parenLoc;
    stack<ll> parenStack;
    vector<pair<ll, ll> > parenPairs;
    string originalString;
    string expressionString;
    set<string> uniqueExpressions;
   
    cin >> originalString;
    
    for(i = 0; i < originalString.size(); i++)
    {
        if (originalString[i] == '(')
        {
            parenStack.push(i);
        }
        else if (originalString[i] == ')')
        {
            parenLoc = parenStack.top();
            parenStack.pop();
            parenPairs.push_back(make_pair(parenLoc, i));
        }
    }    
    
    for(i = 1; i < pow(2, parenPairs.size()); i++)
    {
        vector<bool> usedParenLocs;
        usedParenLocs.resize(originalString.size(), true);
        expressionString.clear();
        for(j = 0; j < parenPairs.size(); j++)
        {
            if((i >> j)&1)
            {
                usedParenLocs[parenPairs[j].first] = false;
                usedParenLocs[parenPairs[j].second] = false;
            }
        }
        for(j = 0; j < originalString.size(); j++)
        {
            if(usedParenLocs[j])
            {
                expressionString.push_back(originalString[j]);   
            }
        }
        uniqueExpressions.insert(expressionString);
        
    }
    
    for(auto expression : uniqueExpressions)
    {
       cout << expression << "\n";
    }
    
    return 0;
}
