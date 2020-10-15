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


struct weightedEdge
{
    ll weight;
    ll src;
    ll dest;
};

struct dijkstraSegment
{
    ll prev = -1;
    bool visited = false;
    ll numCars = 99999999999;
};

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    ll rows, cols;
    cin >> rows >> cols;

    vector<string> showRoom(rows);
    vector<vector<vector<pair<ll, ll>>>> adj(rows);
    vector<vector<dijkstraSegment>> dijkstraSegmentVector(rows);
    set<pair<ll, pair<ll, ll>>> validPoints;
    for(i = 0; i < rows; i++)
    {
    	cin >> showRoom[i];
    	adj[i].resize(cols);
    	dijkstraSegmentVector[i].resize(cols, dijkstraSegment());
    }

    ll startingRow, startingCol;
    cin >> startingRow >> startingCol;	
    startingCol--;
    startingRow--;
    for(i = 0; i < rows; i++)
    {
    	for(j = 0; j < cols; j++)
    	{
    		if(showRoom[i][j] != '#')
    		{
    			validPoints.insert(make_pair(99999999999,make_pair(i, j)));
    		}

    		ll tempRow, tempCol;
		    for (ll k = 0; k < 4; k++)
		    {
		        switch (k) {
		        case 0:
		            tempRow = i - 1;
		            tempCol = j;
		            break;
		            break;
		        case 1:
		            tempRow = i;
		            tempCol = j + 1;
		            break;
		        case 2:
		            tempRow = i + 1;
		            tempCol = j;
		            break;
		            break;
		        case 3:
		            tempRow = i;
		            tempCol = j - 1;
		            break;
		        };


		        if (tempRow >= 0 && tempRow < rows && tempCol >= 0 && tempCol < cols &&
		        	(showRoom[tempRow][tempCol] != '#' && showRoom[i][j] != '#'))
		        {
		        	adj[tempRow][tempCol].push_back(make_pair(i, j));
		        }
		    }	
    	}
    }

    validPoints.erase(make_pair(99999999999, make_pair(startingRow, startingCol)))	;
    validPoints.insert(make_pair(1, make_pair(startingRow, startingCol)));

	dijkstraSegmentVector[startingRow][startingCol].numCars = 1;    
    while(validPoints.size())
    {
        //grab shortest distance edge
        pair<ll, ll> lastEdge;
        auto setIterator = validPoints.begin();
        auto thing = (*setIterator);
        lastEdge = thing.second;
        validPoints.erase(thing);
        
        for(auto nextTo : adj[lastEdge.first][lastEdge.second])
        {
        	int modifer = 0;
        	if(showRoom[nextTo.first][nextTo.second] == 'c')
        	{
        		modifer = 1;
        	}
        	if(dijkstraSegmentVector[nextTo.first][nextTo.second].numCars > dijkstraSegmentVector[lastEdge.first][lastEdge.second].numCars + modifer)
        	{
        		validPoints.erase(make_pair(dijkstraSegmentVector[nextTo.first][nextTo.second].numCars, make_pair(nextTo.first, nextTo.second)));
        		dijkstraSegmentVector[nextTo.first][nextTo.second].numCars = dijkstraSegmentVector[lastEdge.first][lastEdge.second].numCars + modifer;
        		validPoints.insert(make_pair(dijkstraSegmentVector[nextTo.first][nextTo.second].numCars, make_pair(nextTo.first, nextTo.second)));
        	}
        }
    }

    ll minAmount = 99999999999;
    for(i = 0; i < rows; i++)
    {
    	for(j = 0; j < cols; j++)
    	{
    		
    		if( (i == 0 || i == rows - 1) || (j == 0 || j == cols - 1) && showRoom[i][j] == 'D')
    		{
    		//	cout << i << " " << j << "\n";
    		//cout << dijkstraSegmentVector[i][j].numCars << "\n";
    			if(dijkstraSegmentVector[i][j].numCars < minAmount)
    			{
    				minAmount = dijkstraSegmentVector[i][j].numCars;
    			}
    		}
    	}
    }


    cout << minAmount << "\n";
    return 0;
}
