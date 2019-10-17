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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ll roll11, roll12, roll21, roll22;
    map<pair<ll, ll>, ll> values;

    ll ticker = 100;
    for(i = 1; i <= 6; i++)
    {
    	for(j = 1; j <=6; j++)
    	{
    		values[make_pair(i, j)] = ticker--;
    	}
    }
    values[make_pair(2, 1)] = 0;
    values[make_pair(1, 1)] = 6;
    values[make_pair(2, 2)] = 5;
    values[make_pair(3, 3)] = 4;
    values[make_pair(4, 4)] = 3;
    values[make_pair(5, 5)] = 2;
    values[make_pair(6, 6)] = 1;

    while(cin >> roll11 >> roll12 >> roll21 >> roll22 && roll21 != 0)
    {
    	pair<ll, ll> pair1;
    	pair<ll, ll> pair2;

    	if(roll12 > roll11)
    	{
    		pair1 = make_pair(roll12, roll11);
    	}
    	else
    	{
    		pair1 = make_pair(roll11, roll12);
    	}

    	if(roll22 > roll21)
    	{
    		pair2 = make_pair(roll22, roll21);
    	}
    	else
    	{
    		pair2 = make_pair(roll21, roll22);	
    	}

    	cerr << values[pair1] << " " << values[pair2] << "\n";
    	if(values[pair1] < values[pair2])
    	{
    		cout << "Player 1 wins.\n";
    	}
    	else if(values[pair2] < values[pair1])
    	{
    		cout << "Player 2 wins.\n";
    	}
    	else
    	{
    		cout << "Tie.\n";
    	}
    }
    return 0;
}
