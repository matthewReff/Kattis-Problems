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
    cin >> cases;

    string thisString;
    for(i = 0; i < cases; i++)
    {
    	cin >> thisString;
    	bool winner;
    	if(thisString[0] == thisString[thisString.size()-1])
    	{
    		winner = thisString.size() % 2 == 1;
    	}
    	else
    	{
    		winner = thisString.size() % 2 == 0;

    	}
    	if(winner)
    	{
    		cout << "Bash\n";
    	}
    	else
    	{
    		cout << "Chikapu\n";
    	}
    }
    return 0;
}
