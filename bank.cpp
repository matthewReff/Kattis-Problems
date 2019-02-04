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

struct person
{
    ll money;
    ll waitTime;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll time, numPeople;
    ll peopleServed = 0;
    ll bestMoney = 0;
    ll bestPersonIndex = 0;
    ll totalMoney = 0;
    ll bestIndex;
    
    cin >> numPeople >> time;
    vector<person> line(numPeople);
    vector<bool> used(numPeople, false);
    for(i = 0; i < numPeople; i++)
    {
        cin >> line[i].money;
        cin >> line[i].waitTime;
    }
       
    
       
    for(i = min(time, numPeople); i >= 0; i--)
    {
        bestMoney = 0;
        bestIndex = -1;
        for(j = 0; j < numPeople; j++)
        {
            if(!used[j] && line[j].money > bestMoney && line[j].waitTime >= i)
            {
                bestMoney = line[j].money;
                bestIndex = j;
            }
        }
        totalMoney += bestMoney;
        if(bestIndex != -1)
        {
            used[bestIndex] = true;
        }
    }
    
    cout << totalMoney << "\n";
    return 0;
}
