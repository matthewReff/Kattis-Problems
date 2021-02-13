// code adapted from psuedocode https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
// Corrected by https://open.kattis.com/users/luke-videckis-9412
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
	
	
	ll numLines;
	map<string, vector<string>> adj;
	map<string, vector<string>> reverseAdj;
	map<string, bool> used;
	
	vector<string> pySplit(string & splitString, char seperator = ' ')
	{
		int endIndex = 0;
		vector<string > seperated;
		seperated.push_back("");
		for (unsigned int i = 0; i < splitString.size(); i++)
		{
			if (splitString[i] == seperator)
			{
				endIndex++;
				seperated.push_back("");
			}
			else
			{
				seperated[endIndex] += splitString[i];
			}
		}
		return seperated;
	}
	
	stack<string> s;
	stack<string> tS;
	void dfs (string v, map<string, vector<string>> &  adj, bool firstPass)
	{
		tS.push(v);
	    used[v] = true;
	    for (size_t i = 0; i < adj[v].size(); ++i)
	    {
	        if (!used[ adj[v][i] ])
	        {
	            dfs(adj[v][i], adj, firstPass);
	        }
	    }
		if(firstPass)
			s.push(v);
	}
	
	int main()
	{
	    ll i, j, k;
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	
	    cin >> numLines;
	    cin.ignore();
	
	    string inputLine;
	
	    set<string> languages;
	
	    for(i = 0; i < numLines; i++)
	    {
	    	getline(cin, inputLine);
	    	auto stringList = pySplit(inputLine);
	
	    	// Add speaks
	    	adj[stringList[0]].push_back(stringList[1]);
	    	reverseAdj[stringList[1]].push_back(stringList[0]);
	
	    	adj[stringList[1]].push_back(stringList[0]);
	    	reverseAdj[stringList[0]].push_back(stringList[1]);
	
	    	// add understands
	    	for(j = 2; j < (int)stringList.size(); j++)
	    	{
	    		adj[stringList[j]].push_back(stringList[0]);
	    		reverseAdj[stringList[0]].push_back(stringList[j]);
	    	}
	
			//the set "languages" actually stores the people nodes
	    	languages.insert(stringList[0]);
	    }
	
		auto itr = adj.begin();
	    // adj display
	    /*
		while(itr != adj.end())
		{
			cout << itr->first << ":";
			for(auto elem : itr->second)
			{
				cout << elem << " ";
			}
			cout << "\n";
			itr++;
		}
		*/
		while(itr != adj.end())
		{
			used[itr->first] = false;
			itr++;
		}
	
		itr = adj.begin();
		while(itr != adj.end())
		{
			if(!used[itr->first])
			{
				dfs(itr->first, adj, true);
			}
			itr++;
		}
	
		itr = adj.begin();
		while(itr != adj.end())
		{
			used[itr->first] = false;
			itr++;
		}
	
		while(tS.size())
		{
			tS.pop();
		}
	
		ll maxSize = 0;
		while(s.size())
		{
			auto source = s.top();
			s.pop();
			if(!used[source])
			{
				/*here, you need to **not** add any nodes to the stack s (it causes an infinite loop)
				 but also adding to stack s during 2nd dfs is not how the scc alg works*/
				dfs(source, reverseAdj, false);
				// display NEW visited
				vector<string> answers;
				while(tS.size())
				{
					string answer = tS.top();
					if(languages.find(answer) != languages.end())//since the "language" set actually stores people, this is reversed
					{
						answers.push_back(answer);
					}
					tS.pop();
				}
				if((int)answers.size() > maxSize)
				{
					maxSize = answers.size();
				}
				// restore the language nodes
				for(auto elem : languages)
	{
	    used[elem] = false;
	}
			}
		}
		//we want to keep the scc with the max # of people, so the answer is (total # of people) - (max # people in a scc)
		cout << languages.size() - maxSize << "\n";
	    return 0;
	}