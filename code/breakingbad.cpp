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

    ll numItems;
    ll numPairs;
    string temp;
    string temp2;
    string front;
    bool valid = true;
    bool possible = true;
    cin >> numItems;
    unordered_map<string, bool> itemLoc;
    unordered_set<string> allItems;
    unordered_map<string, bool> used;
    unordered_map<string, set<string>> dependant;
    queue<string> q;
    for (i = 0; i < numItems; i++)
    {
        cin >> temp;
        allItems.insert(temp);
        itemLoc[temp] = false;
        used[temp] = false;
    }

    cin >> numPairs;
    for (i = 0; i < numPairs; i++)
    {
        cin >> temp >> temp2;
        dependant[temp].insert(temp2);
        dependant[temp2].insert(temp);
    }

    if (dependant.size() != 0)
    {
        for (unordered_set<string>::iterator itr = allItems.begin(); itr != allItems.end(); itr++)
        {
            //unordered_map<string, set<string>>::iterator itr = dependant.begin();
            //used[itr->first] = true;
            if (!used[*(itr)])
            {
                q.push(*(itr));
            }
            while (valid && q.size())
            {
                front = q.front();
                q.pop();
                for (auto element : dependant[front])
                {
                    if (used[element])
                    {
                        if (itemLoc[element] == itemLoc[front])
                        {
                            valid = false;
                        }
                    }
                    else
                    {
                        itemLoc[element] = !itemLoc[front];
                        used[element] = true;
                        q.push(element);
                    }
                }
            }
        }
    }
    else
    {
        for (auto item : allItems)
        {
            cout << item << " ";
        }
        return 0;
    }
    if (valid)
    {
        for (auto thing : itemLoc)
        {
            if (thing.second)
            {
                cout << thing.first << " ";
            }
        }
        cout << "\n";
        for (auto thing : itemLoc)
        {
            if (!thing.second)
            {
                cout << thing.first << " ";
            }
        }
    }
    else
    {
        cout << "impossible\n";
    }
    return 0;
}
