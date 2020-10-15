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
#include <unordered_map>
#include <set>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    string inputSequence;
    string parsed = "";
    unordered_map<char, bool> used;
    unordered_map<char, char> counter;

    cin >> inputSequence;
    inputSequence += "  ";
    //vector<bool> usedSequence(inputSequence.size(), false);

    used['R'] = false;
    used['B'] = false;
    used['L'] = false;
    counter['R'] = 'S';
    counter['B'] = 'K';
    counter['L'] = 'H';
    counter[' '] = 'Q';

    for(i = 0; i < inputSequence.length()-2; i++)
    {
    	used[inputSequence[i]] = true;
    	used[inputSequence[i+1]] = true;
    	used[inputSequence[i+2]] = true;
    	if(used['R'] && used['B'] && used['L'])
    	{
    		parsed += 'C';
    		i+=2;
    	}
    	else
		{
    		parsed += counter[inputSequence[i]];
		}
    	used['R'] = false;
    	used['B'] = false;
    	used['L'] = false;
    }
    cout << parsed << "\n";
    return 0;
}
