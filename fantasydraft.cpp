#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <list>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll owners, teamSize;
    ll prefSize;
    ll numPlayers;
    string playerName;

    cin >> owners >> teamSize;

    vector<list<string>> ownerPrefs;
    vector<list<string>::iterator> ownerIters;
    unordered_map<string, bool> used;
    for(i = 0; i < owners; i++)
    {
    	cin >> prefSize;
    	list<string> mylinkedList;
    	for(j = 0; j < prefSize; j++)
    	{
    		cin >> playerName;
    		mylinkedList.push_back(playerName);
    	}
    	ownerPrefs.push_back(mylinkedList);
    }

    cout << "prefs: \n";

    cin >> numPlayers;
    list<string> baseList;
    for(i = 0; i < numPlayers; i++)
    {
    	cin >> playerName;
    	baseList.push_back(playerName);
    	used[playerName] = false;
    }

    cout << "base list: \n";
    for(i = 0; i < owners; i++)
    {
    	ownerPrefs[i].insert(ownerPrefs[i].end(), baseList.begin(), baseList.end());
    	ownerIters.push_back(ownerPrefs[i].begin());
    }

    cout << "appended: \n";

    vector<vector<string>> players;
    for(i = 0; i < teamSize * owners; i++)
    {
    	ll ownerIndex = i % owners;
    	cout << "AAA\n";
    	while(used[(*ownerIters[ownerIndex])])
    	{
    		cout << (*ownerIters[ownerIndex]) << "\n";
    		ownerIters[ownerIndex]++;
    	}
    	players[ownerIndex].push_back(*ownerIters[ownerIndex]);
    	used[*ownerIters[ownerIndex]] = true;
    }

    for(auto subList : players)
    {
    	for(auto player : subList)
    	{
    		cout << player << " ";
    	}
    	cout << "\n";
    }
    return 0;
}
