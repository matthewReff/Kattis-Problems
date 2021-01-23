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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll runners;
    string name;
    double start, normal;

    vector<pair<double, string>> starters;
    vector<pair<double, string>> normals;

    cin >> runners;
    for(int i = 0; i < runners; i++)
    {
    	cin >> name >> start >> normal;
    	starters.push_back(make_pair(start, name));
    	normals.push_back(make_pair(normal, name));
    }

    sort(starters.begin(), starters.end());
    sort(normals.begin(), normals.end());

    double bestTime = 999999.0;
    vector<string> bestTeam;
    for(int i = 0; i < runners; i++)
    {
    	double tempBest = 0.0;
    	string name = starters[i].second;

    	tempBest += starters[i].first;
    	vector<string> tempTeam {name};

    	ll grabbedNum = 0;
    	ll grabIndex = 0;
    	while(grabbedNum != 3)
    	{
    		if(normals[grabIndex].second != name)
    		{
    			grabbedNum++;
    			tempBest += normals[grabIndex].first;
    			tempTeam.push_back(normals[grabIndex].second);
    		}
    		grabIndex++;
    	}

    	if(tempBest < bestTime)
    	{
    		bestTime = tempBest;
    		bestTeam = tempTeam;
    	}
    }

    cout << bestTime << "\n";
    for(auto entry : bestTeam)
    {
    	cout << entry << "\n";
    }
    return 0;
}
