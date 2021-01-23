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

    ll cases;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
    	ll buttons;
    	ll time;
    	cin >> buttons >> time;
    	map<int, int> distances;

    	vector<int> buttonVals;
    	for(int j = 0; j < buttons; j++)
    	{
    		ll tempVal;
    		cin >> tempVal;
    		buttonVals.push_back(tempVal);
    	}
    	queue<pair<int, int>> q;

    	distances[0] = 0;
    	q.push(make_pair(0, 0));

    	while(q.size())
    	{
    		auto front = q.front();
    		q.pop();
    		//cout << "Pulling:" << front.first << " " << front.second << "\n";
    		for(int j = 0; j < (int)buttonVals.size(); j++)
    		{
    			int nextVal = front.first + buttonVals[j];
    			if (nextVal < 0)
    			{
    				nextVal = 0;
    			}

    			if (nextVal > 3600)
    			{
    				nextVal = 3600;
    			}

    			auto loc = distances.find(nextVal);

    			if (loc == distances.end() )
    			{
    				distances[nextVal] = front.second + 1;
    				q.push(make_pair(nextVal, front.second + 1));
    				//cout << "Added new\n";
    			}
    			else if(front.second + 1 < distances[nextVal]) 
    			{
    				distances[nextVal] = front.second + 1;
    				q.push(make_pair(nextVal, front.second + 1));
    				//cout << "Updated\n";
    			}
    		}
    	}
    	auto loc = distances.find(time);
    	if (loc == distances.end())
    	{
    		ll tempVal = time;
    		while(loc == distances.end())
    		{
    			tempVal += 1;
    			loc = distances.find(tempVal);
    		}
    		cout << distances[tempVal] << " " << tempVal - time << "\n";
    	}
    	else
    	{
    		cout << distances[time] << " 0\n";
    	}
    }
    return 0;
}
