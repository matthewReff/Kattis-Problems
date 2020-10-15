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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cases;
    string path;
    cin >> cases;

    map<char, int> directionMapping;
    directionMapping['F'] = 0;
    directionMapping['R'] = 1;
    directionMapping['B'] = 2;
    directionMapping['L'] = 3;

    map<pair<ll, ll>, int> reverseDirectionMapping;
    reverseDirectionMapping[make_pair(-1, 0)] = 0;
    reverseDirectionMapping[make_pair(0, 1)] = 1;
    reverseDirectionMapping[make_pair(1, 0)] = 2;
    reverseDirectionMapping[make_pair(0, -1)] = 3;

    // clockwise from 'up' is 0-4, first entry being current direction and second being new
    vector<vector<pair<ll, ll>>> newDirections(4);

    newDirections[0].push_back(make_pair(-1, 0));
    newDirections[0].push_back(make_pair(0, 1));
    newDirections[0].push_back(make_pair(1, 0));
    newDirections[0].push_back(make_pair(0, -1));

    newDirections[1].push_back(make_pair(0, 1));
    newDirections[1].push_back(make_pair(1, 0));
    newDirections[1].push_back(make_pair(0, -1));
    newDirections[1].push_back(make_pair(-1, 0));

    newDirections[2].push_back(make_pair(1, 0));
    newDirections[2].push_back(make_pair(0, -1));
	newDirections[2].push_back(make_pair(-1, 0));
    newDirections[2].push_back(make_pair(0, 1));

    newDirections[3].push_back(make_pair(0, -1));
	newDirections[3].push_back(make_pair(-1, 0));
    newDirections[3].push_back(make_pair(0, 1));
    newDirections[3].push_back(make_pair(1, 0));

    cout << cases << "\n";
    for(i = 0; i < cases; i++)
    {
    	cin >> path;
    	ll lastDirection = 1;
    	vector<pair<ll, ll>> reached;
    	reached.push_back(make_pair(0, 0));
    	pair<ll, ll> currentLoc = make_pair(0, 0);
    	for(auto step : path)
    	{
    		pair<ll, ll> nextMove = newDirections[lastDirection][directionMapping[step]];
    		currentLoc.first += nextMove.first;
    		currentLoc.second += nextMove.second;
    		reached.push_back(currentLoc);
    		lastDirection = reverseDirectionMapping[nextMove];
    	}

    	ll furthestUp = 999999;
    	ll furthestdown = -999999;
    	ll furthestright = -999999;
    	for(auto locPair : reached)
    	{

    		furthestUp = min(furthestUp, locPair.first);
    		furthestdown = max(furthestdown, locPair.first);
    		furthestright = max(furthestright, locPair.second);
    	}

    	for(j = 0; j < (int)reached.size(); j++)
    	{
    		reached[j].first += -furthestUp;
    	}

    	ll rowResult = -furthestUp + furthestdown + 3;
    	ll colResult = furthestright + 2;
    	vector<string> outArr(rowResult);
    	for(j = 0; j < rowResult; j++)
    	{
    		outArr[j].resize(colResult, '#');
    	}

    	for(auto locPair : reached)
    	{
    		outArr[locPair.first+1][locPair.second] = '.';
    	}

    	cout << rowResult << " " << colResult << "\n";
    	for(auto rowString : outArr)
    	{
    		cout << rowString << "\n";
    	}
    }
    return 0;

}
