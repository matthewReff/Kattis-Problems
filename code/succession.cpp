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
    
    ll numChildren, claimants;
    ld bestBlood;
    ll numZeros;
    string temp;
    string bestHeir = "";
    string kingName;
    string child, parent1, parent2;
    map<string, ll > inDegree;
    map<string, vector<string>> children;
    map<string, ld> bloodPercent;
    set<string> people;
    ll tracker = 0;
    
    cin >> numChildren >> claimants;
    cin >> kingName;
    
    for(i = 0; i < numChildren; i++)
    {
        cin >> child >> parent1 >> parent2;
        people.insert(child);
        people.insert(parent1);
        people.insert(parent2);
        children[parent1].push_back(child);
        children[parent2].push_back(child);
        inDegree[child] += 2;
    }
    
    
    bloodPercent[kingName] = 1.0;
    
    numZeros = 1;
    vector<string> zeros;
    while(numZeros != 0)
    {
        zeros.clear();
        numZeros = 0;
        for(set<string>::iterator itr = people.begin(); itr != people.end(); itr++)
        {
            if (inDegree.find(*(itr)) == inDegree.end() || inDegree[*(itr)] == 0)
            {
                numZeros++;
                zeros.push_back(*(itr));
                inDegree[*(itr)]--;
            }
        }
        
        for(i = 0; i < numZeros; i++)
        {
            for(auto thisChild : children[zeros[i]])
            {
                bloodPercent[thisChild] += (bloodPercent[zeros[i]] / 2); 
                inDegree[thisChild]--; 
            }
        }
    }   
    
    bestBlood = 0.0;
    for(i = 0; i < claimants; i++)
    {
        cin >> temp;
        if(bloodPercent[temp] > bestBlood)
        {
            bestBlood = bloodPercent[temp];
            bestHeir = temp;
        }   
    }

    cout << bestHeir << "\n";
    return 0;
}
