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

    ll people;
    cin >> people;
    vector<int> classes(5);
    unordered_map<string, int> schedules;
    for(i = 0; i < people; i++)
    {
    	for(j = 0; j < 5; j++)
    	{
    		cin >> classes[j];
    	}
    	sort(classes.begin(), classes.end());
    	string thing = "";
    	for(j = 0; j < 5; j++)
    	{
    		thing += to_string(classes[j]);
    	}
    	schedules[thing]++;
    	//cout << thing << "\n";
    }
    
    int mostPopular = 0;
    int maxSoFar = 0;
    for(auto thing : schedules)
    {
    	if(thing.second > maxSoFar)
    	{
    		maxSoFar = thing.second;
    		mostPopular = thing.second;
    	}
    	else if(thing.second == maxSoFar)
    	{
    		mostPopular += thing.second;
    	}
    }

    cout << mostPopular << "\n";
    return 0;
}
