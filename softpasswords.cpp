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

    
    string p, s;

    cin >> s >> p;

    string prepend = s.substr(0, s.size()-1);
    string append = s.substr(1);

    string reverse = p;
    for(i = 0; i < s.size(); i++)
    {
    	char cpy = p[i];
    	if(tolower(cpy) == p[i])
    	{
    		reverse[i] = toupper(p[i]);
    	}
    	else if(toupper(cpy) == p[i])
    	{
    		reverse[i] = tolower(p[i]);
    	}
    }

    if ((prepend == p && isdigit(s[s.size()-1])) || (append == p && isdigit(s[0])) || reverse == s || p == s)
    {
    	cout << "Yes\n";
    }
    else
    {
    	cout << "No\n";
    }
    return 0;
}
