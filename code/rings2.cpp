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

    ll rows, cols;
    cin >> rows >> cols;

    vector<pair<int, int>> offsets = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
    vector<vector<int>> grid(rows+2, vector<int>(cols+2, 0));
    vector<vector<int>> lastGrid(rows+2, vector<int>(cols+2, 0));
    set<pair<int, int>> remainingLocs;
    set<pair<int, int>> lastRemainingLocs;

    char temp;

    for(int i = 0; i < rows; i++)
    {
    	for(int j = 0; j < cols; j++)
    	{
    		cin >> temp;
    		if(temp == 'T')
    		{
    			grid[i+1][j+1] = 999;
    			remainingLocs.insert(make_pair(i+1, j+1));
    		}
    	}
    }

    int deepestRing = -1;
    while(remainingLocs.size())
    {
    	lastRemainingLocs = remainingLocs;
    	lastGrid = grid;
    	auto itr = lastRemainingLocs.begin();
    	while(itr != lastRemainingLocs.end())
    	{
    		int least = 999;
    		for(int i = 0; i < 4; i++)
    		{
    			int newRow = (*itr).first + offsets[i].first;
    			int newCol = (*itr).second + offsets[i].second;
    			if(newRow < rows+2 && newRow >= 0 && newCol < cols+2 && newCol >= 0)
    			{
    				if(lastGrid[newRow][newCol] < least)
    				{
    					least = lastGrid[newRow][newCol];
    				}
    			}
    		}
    		if(least < 999)
			{
				//cout << "Setting:" << (*itr).first << " " << (*itr).second << "\n";
				grid[(*itr).first][(*itr).second] = least + 1;
				remainingLocs.erase((*itr));
				if(deepestRing < least + 1)
				{
					deepestRing = least + 1;
				}
			}
    		itr++;
    	}
    	/*
		for(int i = 1; i < rows+1; i++)
		{
			for(int j = 1; j < cols+1; j++)
			{
				if(grid[i][j] == 0)
				{
					cout << "..";
				}
				else if(grid[i][j] < 10)
				{
					cout << "." << grid[i][j];
				}
				else
				{
					cout << grid[i][j];
				}
			}
			cout << "\n";
		}
		cout << "\n\n";
	    */
    }


    for(int i = 1; i < rows+1; i++)
    {
    	for(int j = 1; j < cols+1; j++)
    	{
    		if(deepestRing >= 10)
    		{
    			cout << ".";
    		}
    		if(grid[i][j] == 0)
    		{
    			cout << "..";
    		}
    		else if(grid[i][j] < 10)
    		{
    			cout << "." << grid[i][j];
    		}
    		else
    		{
    			cout << grid[i][j];
    		}
    	}
    	cout << "\n";
    }
    return 0;
}
