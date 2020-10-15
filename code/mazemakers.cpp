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

    map<char, int> adjs;
    vector<pair<ll, ll>> offSets = {make_pair(0, -1), make_pair(1, 0),
    	make_pair(0, 1), make_pair(-1, 0)};
    /*
    vector<pair<ll, ll>> offSets = {make_pair(-1, 0), make_pair(0, 1),
    	make_pair(1, 0), make_pair(0, -1)};
    	*/
    //it's just binary counting, and I did it manually
    //also it's backwards from the example
    //oof
    adjs['0'] = 0b1111;
    adjs['1'] = 0b1110;
    adjs['2'] = 0b1101;
    adjs['3'] = 0b1100;

    adjs['4'] = 0b1011;
    adjs['5'] = 0b1010;
    adjs['6'] = 0b1001;
    adjs['7'] = 0b1000;

    adjs['8'] = 0b0111;
    adjs['9'] = 0b0110;
    adjs['A'] = 0b0101;
    adjs['B'] = 0b0100;

    adjs['C'] = 0b0011;
    adjs['D'] = 0b0010;
    adjs['E'] = 0b0001;
    adjs['F'] = 0b0000;

    ll rows, cols;
    while(cin >> rows >> cols && (rows != 0 || cols != 0))
    {
    	map< pair<ll, ll>, vector<pair<ll, ll>> > thisAdj;
    	vector<vector<int>> used(rows);
    	set<pair<ll, ll>> outFacing;
    	char thisChar;
    	for(i = 0; i < rows; i++)
    	{
    		used[i].resize(cols, 0);
    		for(j = 0; j < cols; j++)
    		{
    			cin >> thisChar;
    			ll num = adjs[thisChar];
    			for(k = 0; k < 4; k++)
    			{
    				if(((num>>k) & 1) == 1)
    				{
    					ll newRow = i + offSets[k].first;
    					ll newCol = j + offSets[k].second;
    					if(newCol >= 0 && newCol < cols && newRow >= 0 && newRow < rows)
    					{
    						thisAdj[make_pair(i, j)].push_back(make_pair(newRow, newCol));
    					}
    					else
    					{
    						outFacing.insert(make_pair(i, j));			
    					}
    				}
    			}
    		}
    	}

    	queue<pair<ll, ll>> q;
    	ll touched = 0;
    	pair<ll, ll> firstExit = (*outFacing.begin());
    	q.push(firstExit);
    	used[firstExit.first][firstExit.second] = 2;
    	bool valid = true;
    	while(q.size())
    	{
    		pair<ll, ll> front = q.front();
    		q.pop();
    		used[front.first][front.second] = 2;
    		//cout << front.first << " " << front.second << "\n";
    		touched++;
    		for(auto nextTo : thisAdj[front])
    		{
    			//cout << nextTo.first << ", " << nextTo.second << ", " << used[nextTo.first][nextTo.second] << "\n";
    			if(used[nextTo.first][nextTo.second] == 0)
    			{
    				q.push(nextTo);
    				used[nextTo.first][nextTo.second] = 1;
    			}
    			else if(used[nextTo.first][nextTo.second] == 1)
    			{
    				valid = false;
    			}
    		}
    		/*
    		for(auto thing : used)
    		{
    			for(auto subChar : thing)
    			{
    				cout << subChar;
    			}
    			cout << "\n";
    		}
    		cout << "\n";
    		*/
    	}
    	//cout << touched << " " << rows * cols << "\n";
    	auto itr = outFacing.begin();
    	itr++;
    	pair<ll, ll> lastExit = (*itr);
    	if(used[lastExit.first][lastExit.second] != 2)
    	{
    		cout << "NO SOLUTION\n";
    	}
    	else if(touched != rows * cols)
    	{
    		cout << "UNREACHABLE CELL\n";
    	}
    	else if(!valid)
    	{
    		cout << "MULTIPLE PATHS\n";
    	}
    	else
    	{
    		cout << "MAZE OK\n";
    	}
    }
    return 0;
}
