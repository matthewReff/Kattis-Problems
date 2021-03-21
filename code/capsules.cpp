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

bool isValid(vector<vector<int>> &grid, pair<int, int> loc, int num)
{
	int rows = grid.size();
	int cols = grid[0].size();

	vector<pair<int, int>> offsets = {make_pair(-1, 0), make_pair(-1, -1), make_pair(-1, 1), make_pair(0, -1), make_pair(0, 1), make_pair(1, -1), make_pair(1, 0), make_pair(1, -1)};
	bool valid = true;
	for(int i = 0; i < (int)offsets.size(); i++)
	{
		int newRow = loc.first + offsets[i].first;
		int newCol = loc.second + offsets[i].second;

		if(newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0)
		{
			if (grid[newRow][newCol] == num)
			{
				valid = false;
			}
		}
	}
	return valid;
}
bool recurse( vector<vector<int>> &grid, vector<vector<pair<int, int>>> & groupCoords, vector<vector<bool>> groupUsed, vector<vector<bool>> & groupNum, int groupIndex, int trackNum, int maxNum)
{
	bool solved;
	for(auto row : grid)
		{
			for(auto entry : row)
			{
				cout << entry << " ";
			}
			cout << "\n";
		}	
		cout << "\n";
	//cout << trackNum << "\n";
	// output
	
	if(groupIndex == (int)groupCoords.size())
	{
		return false;
	}

	if(trackNum == maxNum)
	{
		for(auto row : grid)
		{
			for(auto entry : row)
			{
				cout << entry << " ";
			}
			cout << "\n";
		}	
		//cout << "returned true, found\n";
		return true;
	}

	int size = groupCoords[groupIndex].size();
	int totalInGroup = 0;
	for(int i = 0; i < size; i++)
	{
		if(groupUsed[groupIndex][i])
		{
			totalInGroup++;
		}
	}
	
	if(totalInGroup == size)
	{
		solved = recurse(grid, groupCoords, groupUsed, groupNum, groupIndex+1, trackNum, maxNum);
		if(solved)
		{
			return true;
		}
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			// Haven't used this entry yet
			if(!groupUsed[groupIndex][i])
			{
				for(int j = 0; j < size; j++)
				{
					// Haven't used this number yet
					if(!groupNum[groupIndex][j])
					{
						int row = groupCoords[groupIndex][i].first;
						int col = groupCoords[groupIndex][i].second;
						// Can be added here
						if(isValid(grid, make_pair(row, col), j+1))
						{
							groupNum[groupIndex][j] = true;
							groupUsed[groupIndex][i] = true;
							
							grid[row][col] = j+1;
							//cout << "Going down:" << groupIndex << " " << trackNum << "\n";
							solved = recurse(grid, groupCoords, groupUsed, groupNum, groupIndex, trackNum+1, maxNum);
							if(!solved)
							{
								groupNum[groupIndex][j] = false;
								groupUsed[groupIndex][i] = false;
								grid[row][col] = 0;
							}
							else
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll cols, rows;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++)
    {
    	for(int j = 0; j < cols; j++)
    	{
    		char temp;
    		cin >> temp;
    		if(temp != '-')
    		{
    			grid[i][j] = temp - '0';

    		}
    		else
    		{
    			grid[i][j] = 0;

    		}
    	}
    }

    ll groups;
    cin >> groups;
    vector<vector<pair<int, int>>> groupCoords(groups, vector<pair<int, int>>());
    vector<vector<bool>> usedCoords(groups, vector<bool>());
    vector<vector<bool>> groupNum(groups, vector<bool>());
    for(int i = 0; i < groups; i++)
    {
    	int size;
    	cin >> size;
    	for(int j = 0; j < size; j++)
    	{
    		//cout << size << j << " " << "\n";
    		string temp;
    		cin >> temp;
    		//cout << temp << "\n";
    		pair<int, int> coord;
    		coord.first = temp[1] - '1';
    		coord.second = temp[3] - '1';
    		groupCoords[i].push_back(coord);
    		usedCoords[i].push_back(false);
    		groupNum[i].push_back(false);
   			//cout << "AAAA\n\n\n";

    	}
    }


    int used = 0;

    for(int i = 0; i < groups; i++)
    {
    	for(int j = 0; j < (int)groupCoords[i].size(); j++)
    	{
    		int row = groupCoords[i][j].first;
    		int col = groupCoords[i][j].second;

	    	if(grid[row][col] != 0)
	    	{
	    		//cout << row << " " << col << "\n";
	    		usedCoords[i][j]  = true;
	    		groupNum[i][grid[row][col]-1]  = true;
	    		used++;
	    	}
    	}
    }

    recurse(grid, groupCoords, usedCoords, groupNum, 0, used, rows*cols);
	
    return 0;
}
