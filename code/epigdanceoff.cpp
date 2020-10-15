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
    ll height, width;
    ll numFrames = 0;
    cin >> height >> width;
    vector<string> screen(height);
    for(i = 0; i < height; i++)
    {
    	cin >> screen[i];
    }

    for(i = 0; i < width; i++)
    {
    	bool blankSoFar = true;
    	for(j = 0; j < height; j++)
    	{
    		blankSoFar = blankSoFar && screen[j][i] == '_';
    	}
    	if(blankSoFar)
    	{
    		numFrames++;
    	}
    }
    cout << numFrames + 1;
    return 0;
}
