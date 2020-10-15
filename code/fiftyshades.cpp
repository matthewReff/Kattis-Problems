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

    ll numInputs;
    cin >> numInputs;
    ll total = 0;

    string thisString;
    for(i = 0; i < numInputs; i++)
    {
    	cin >> thisString;
    	for(j = 0; j < (int)thisString.size(); j++)
    	{
    		thisString[j] = tolower(thisString[j]);
    	}
    	if(thisString.find("pink") != string::npos || thisString.find("rose") != string::npos)
    	{
    		total++;
    	}

    }


    if(total != 0)
    {
    	cout << total << "\n";
    }
    else
    {
    	cout << "I must watch Star Wars with my daughter\n";
    }
    return 0;
}

