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

bool tempSort(pair<int, int> first, pair<int, int> second)
{
	if(first.first == second.first)
	{
		return first.second < second.second;
	}
	return first.first < second.first;
}

pair<int, int> rotate(pair<int, int> inPair, int size)
{
	// Rotate a "point" by 90,
	// then shift it back up to the quadrant we are about
	int newX = inPair.second;
	int newY = -inPair.first + (size - 1);
	return make_pair(newX, newY);
}
int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll size;
    cin >> size;
    char temp;
    vector<pair<int, int>> opens;
    vector<vector<char>> grid(size, vector<char>(size));
    vector<vector<bool>> used(size, vector<bool>(size, false));

    for(int i = 0; i < size; i++)
    {
    	for(int j = 0; j < size; j++)
    	{
    		cin >> temp;
    		if(temp == '.')
    		{
    			opens.push_back(make_pair(i, j));
    		}
    	}
    }

    string inString;
    cin >> inString;
    string outString = "";
    int stringIndex = 0;
    for(int j = 0; j < 4; j++)
    {
    	sort(opens.begin(), opens.end(), tempSort);
	    for(int i = 0; i < (int)opens.size(); i++)
	    {
	    	if(used[opens[i].first][opens[i].second])
	    	{
	    		cout << "invalid grille\n";
	    		return 0;
	    	}
    		grid[opens[i].first][opens[i].second] = inString[stringIndex];
    		stringIndex++;
    		used[opens[i].first][opens[i].second] = true;
	    	opens[i] = rotate(opens[i], size);
	    }
    }

    bool allUsed = true;
    for(int i = 0; i < size; i++)
    {
    	for(int j = 0; j < size; j++)
    	{
    		allUsed &= used[i][j];
    		outString += grid[i][j];
    	}
    }

    if(allUsed)
    {
	    cout << outString << "\n";
	}
	else
	{
		cout << "invalid grille\n";
	}
    return 0;
}
