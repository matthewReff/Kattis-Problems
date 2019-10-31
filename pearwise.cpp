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
    ll letters, ballots;
    cin >> letters >> ballots;
    vector<vector<int>> voting(letters);
    vector<vector<int>> adj(letters);
    for(i = 0; i < letters; i++)
    {
    	voting[i].resize(letters, 0);
    }

    ll numVotes;
    string order;
    //calculate votes in a matchup
    for(i = 0; i < ballots; i++)
    {
    	cin >> numVotes >> order;
    	for(j = 0; j < letters; j++)
    	{
    		for(k = j + 1; k < letters; k++)
    		{
				voting[order[j]-'A'][order[k]-'A'] += numVotes;
    		}
    	}
    }
    
    //created directed "defeating" graph
    for(i = 0 ; i < letters; i++)
    {
    	for(j = i + 1; j < letters; j++)
    	{
    		if(voting[i][j] > voting[j][i])
    		{
    			adj[i].push_back(j);
    		}
    		else
    		{
    			adj[j].push_back(i);
    		}
    	}
    }

    //navigate directed graph, if able to reach all nodes from a letter, there exists a winning sequence that results in that letter
    for(i = 0; i < letters; i++)
    {
    	stack<int> s;
    	vector<bool> visisted(letters, false);
    	int totalVisited = 1;

    	s.push(i);
    	visisted[i] = true;

    	while(s.size())
    	{
    		int top = s.top();
    		s.pop();
    		for(auto nextTo : adj[top])
    		{
    			if(!visisted[nextTo])
    			{
    				totalVisited++;
    				visisted[nextTo] = true;
    				s.push(nextTo);
    			}
    		}
    	}

    cout << char('A' + i) << ": ";
    if(totalVisited == letters)
    {
    	cout << "can win\n";
    }
    else
    {
    	cout << "can't win\n";
    }
    }
    return 0;
}
