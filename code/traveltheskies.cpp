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

struct flight
{
	int src;
	int dest;
	int day;
	int amount;
};

struct arrival
{
	int airport;
	int day;
	int customers;
};

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll airports, days, flights;
    cin >> airports >> days >> flights;
    flight temp;
    vector<int> amount(airports, 0);
    vector<vector<flight>> flightVec(days, vector<flight>());
    vector<vector<arrival>> arrivalVec(days, vector<arrival>());

    for(int i = 0; i < flights; i++)
    {
    	cin >> temp.src >> temp.dest >> temp.day >> temp.amount;
    	temp.src--;
    	temp.dest--;
    	temp.day--;
    	flightVec[temp.day].push_back(temp);
    }

    arrival newArrival;
    for(int i = 0; i < airports; i++)
    {
    	for(int j = 0; j < days; j++)
    	{
    		cin >> newArrival.airport >> newArrival.day >> newArrival.customers;
    		newArrival.day--;
    		newArrival.airport--;
    		arrivalVec[newArrival.day].push_back(newArrival);
    	}
    }

    for(int i = 0; i < days; i++)
    {
    	// Arrival phase
    	for(auto thisArrival : arrivalVec[i])
    	{
    		amount[thisArrival.airport] += thisArrival.customers;
    	}

    	// Check if flights can be resolved
    	for(auto thisFlight : flightVec[i])
    	{
    		amount[thisFlight.src] -= thisFlight.amount;
    		if(amount[thisFlight.src] < 0)
    		{
    			cout << "suboptimal\n";
    			return 0;
    		}
    	}

    	// If they can, move them along
    	for(auto thisFlight : flightVec[i])
    	{
    		amount[thisFlight.dest] += thisFlight.amount;
    	}
    }

	cout << "optimal\n";
    return 0;
}
