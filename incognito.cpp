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
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, k;
    ll cases;
    ll numItems;
    cin >> cases;
    string item, category;
    ll total = 0;
    ll prev;
    for(i = 0; i < cases; i++)
    {
	    unordered_map<string, vector<string>> items;
    	cin >> numItems;
    	for(j = 0; j < numItems; j++)
    	{	
    		cin >> item >> category;
    		items[category].push_back(item);
    	}
    	if(numItems != 0)
    	{
	    auto itr = items.begin();
	    total = itr->second.size();
	  	//cout << itr->first << " " << itr->second.size() << "\n";

	    //cout << total << "\n";
	    itr++;
	  	for(;itr != items.end(); itr++)
	  	{
	  		total = (itr->second.size())* (total +1) + total;
	  		//cout << "here";
	  		//(1 + numPossforward) * num in row
	  	}

	  	cout << total << "\n";
	  }
	  else
	  {
	  	cout << 0 << "\n";
	  }
    }	

    return 0;
}
