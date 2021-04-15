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

struct dataHolder
{
	ll time;
	ll index;
	bool visiting;

	bool operator < (const dataHolder& str) const
    {
    	// We want leavers to be sorted last
    	if(time == str.time)
    	{
    		if(!visiting && str.visiting)
    		{
    			return false;
    		}
    		else
    			return true;
    	}
        return (time > str.time);
    }
};
 
bool runner(vector<ll> & travelTimes, vector<vector<ll>> & visits, int startA, int startB, int startC, int maxAmount)
{
	//cout << "\n\n\nNew CALL:";
	vector<ll> lastUpdateTime = {0, 0, 0};
	vector<ll> currentLocs = {startA, startB, startC};
	vector<ll> starts = {startA, startB, startC};

	std::priority_queue<dataHolder> q;

	dataHolder temp;

	temp.index = 0;
	temp.time = visits[temp.index][currentLocs[temp.index]];
	temp.visiting = true;
	q.push(temp);

	temp.index = 1;
	temp.time = visits[temp.index][currentLocs[temp.index]];
	q.push(temp);

	temp.index = 2;
	temp.time = visits[temp.index][currentLocs[temp.index]];
	q.push(temp);

	while(q.size())
	{
		auto top = q.top();
		q.pop();

		//cout << top.time << " " << top.index << " " << top.visiting << "\n";
		//cout << currentLocs[top.index] << "\n\n";

		if(top.visiting)
		{
			ll endingLoc = starts[top.index] - 1;
			if(endingLoc < 0)
			{
				endingLoc += maxAmount;
			}

			lastUpdateTime[top.index] = top.time;

			for(int i = 0; i < 3; i++)
			{
				if(i != top.index)
				{
					if(currentLocs[top.index] == currentLocs[i] && lastUpdateTime[top.index] > lastUpdateTime[i])
					{
						return false;
					}
				}
			}
			// If we're not on the last place in the tour, update it
			if(currentLocs[top.index] != endingLoc)
			{
				top.visiting = false;
				ll newIndex = (currentLocs[top.index] + 1) % maxAmount;
				top.time += travelTimes[newIndex];
				q.push(top);
			}
		}
		else
		{
			lastUpdateTime[top.index] = top.time;

			ll newIndex = (currentLocs[top.index] + 1) % maxAmount;
			currentLocs[top.index] = newIndex;
			top.visiting = true;
			top.time += visits[top.index][currentLocs[top.index]];
			q.push(top);
		}

	}

	cout << startA + 1 << " " << startB + 1 << " " << startC + 1 << "\n";
	return true;
}

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    
    ll places;
    cin >> places;
    vector<ll> travelTimes;
    vector<ll> visitA;
    vector<ll> visitB;
    vector<ll> visitC;


    ll temp;
    for(int i = 0; i < places; i++)
    {
    	cin >> temp;
    	travelTimes.push_back(temp);
    }
    for(int i = 0; i < places; i++)
    {
    	cin >> temp;
    	visitA.push_back(temp);
    }
    for(int i = 0; i < places; i++)
    {
    	cin >> temp;
    	visitB.push_back(temp);
    }
    for(int i = 0; i < places; i++)
    {
    	cin >> temp;
    	visitC.push_back(temp);
    }

    vector<vector<ll>> visits = {visitA, visitB, visitC};

    for(int i = 0; i < places; i++)
    {
    	for(int j = 0; j < places; j++)
    	{
    		for(int k = 0; k < places; k++)
    		{
    			if(i != j && j != k && i != k)
    			{
    				if(runner(travelTimes, visits, i, j, k, places))
    				{
    					return 0;
    				}
    			}
    		}
    	}
    }

    cout << "impossible\n";
    return 0;
}
