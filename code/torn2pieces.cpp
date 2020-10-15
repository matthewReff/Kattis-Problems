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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

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

struct weightedEdge
{
    ll weight;
    ll src;
    ll dest;
};

struct dijkstraSegment
{
    ll dist = 99999999999;
    string prev = "";
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll edges;
    string line;
    string starting, ending;
    vector<string> allAdj;
    weightedEdge tempEdge;
    string temp;
    ll minVal;
    string lastEdge;
    ll nextEdge;
    bool possible = true;
    set<string> vertexSet;
    set<string>::iterator setIterator;
    cin >> edges;
    cin.ignore();
    map<string, vector<string> > adj;
    map<string, dijkstraSegment> state;
    for(i = 0; i < edges; i++)
    {
        getline(cin, line);
        allAdj = pySplit(line);
        vertexSet.insert(allAdj[0]);
        for(j = 1; j < allAdj.size(); j++)
        {
            vertexSet.insert(allAdj[j]);
            adj[allAdj[0]].push_back(allAdj[j]);
            adj[allAdj[j]].push_back(allAdj[0]);
        }
    }
    for(auto thing : vertexSet)
    {
        state[thing].prev = -1;
    }
    
    cin >> starting >> ending;
    state[starting].dist = 0;
    
    while(vertexSet.size() && possible)
    {
        //grab shortest distance edge
        //cout << "grabbing edge \n";
        
        setIterator = vertexSet.begin();
        minVal = 99999999999;
        while(setIterator != vertexSet.end())
        {
            if(minVal > state[*(setIterator)].dist)
            {
                minVal = state[*(setIterator)].dist;
                lastEdge = *(setIterator);
            }
            setIterator++;
        }
        if(minVal == 99999999999)
        {
            break;
        }
        vertexSet.erase(lastEdge);
        
        //cout << "provessing: " << lastEdge << "\n";
        
        for(auto adjacent : adj[lastEdge])
        {
            if(state[adjacent].dist > state[lastEdge].dist + 1)
            {
                state[adjacent].dist = (state[lastEdge].dist + 1);
                state[adjacent].prev = lastEdge;
            }
        }
        //find distances from found edge
        //cout << "calculating distances from edge " << lastEdge << "\n";
        /*
        for(auto segment : dijkstraSegmentVector)
        {
            cout << segment.dist << " " << segment.visited << "\n";
        }
        cout << "\n";
        */
               
    }
    if(state[ending].dist == 99999999999)
    {   
        cout << "no route found\n";
    }
    else
    {
        vector<string> output;
        temp = ending;
        while(state[temp].prev != "")
        {
            output.push_back(temp);
            temp = state[temp].prev;
        }
        reverse(output.begin(), output.end());
        for(auto thing : output)
        {
            cout << thing << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
