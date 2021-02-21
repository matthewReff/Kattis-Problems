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

    ll letters;
    cin >> letters;
    vector<string> answers;
    string inputChar;
    for(int i = 0; i < letters; i++)
    {
    	cin >> inputChar;
    	answers.push_back(inputChar);
    }

    ll total = 0;
    for(int i = 0; i < letters-1; i++)
    {	
    	if(answers[i] == answers[i+1])
    	{
    		total++;
    	}
    }

    cout << total << "\n";
    return 0;
}
