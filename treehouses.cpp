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
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;


struct mstEdge
{
    long double distance;
    int src;
    int dest;
    //operator are backwards due to default priority queue
    //placing longer distances higher in queue
    bool operator< (const mstEdge & other) const
    {
        return distance > other.distance;
    }

};

vector<mstEdge> kruskal(vector<pair<double, double> > & points, vector<vector<ll>> &existingAdj)
{
    priority_queue<mstEdge> q;
    int verticies = points.size();
    vector< set< int > > vertSets(verticies);
    vector<bool> used(verticies, false);
    unordered_map<int, int> setLoc;
    vector<mstEdge> mst;
    mstEdge temp;
    int index1, index2;
    
    //create vector of sets with one vertex per set
    //ex: {{0}, {1}, {2}, {3}}
    for (int i = 0; i < verticies; i++)
    {
	    vertSets[i].insert(i);
	    setLoc[i] = i;
    }

    for(int i = 0; i < existingAdj.size(); i++)
    {
    	for(auto element : existingAdj[i])
    	{
    		index1 = setLoc[i];
    		index2 = setLoc[element]; 	
    		if (index1 != index2)
        	{
	            for (set<int>::iterator i = vertSets[index2].begin(); i != vertSets[index2].end(); i++)
	            {
	                vertSets[index1].insert((*i));
	                setLoc[*i] = index1;
	            }
        	}
    	}
    }

//    for(int i = 0; i < vertSets.size(); i++)
 //   {
  //  	cout << i << ": ";
   // 	for(auto thing : vertSets[i])
   // 	{
   // 		cout << thing << " ";
   // 	}
   // 	cout << "\n";
   // }
    //calculate and push all edges into queue
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            temp.distance = sqrt((points[j].first - points[i].first) *
                (points[j].first - points[i].first) + (points[j].second - points[i].second)
                * (points[j].second - points[i].second));
            temp.src = j;
            temp.dest = i;
            q.push(temp);
        }
    }
  
    //starting at shortest edge distance, if edge is across different sets, combine them
    //also add edge to mst, when mst is complete return it
    while (mst.size() != verticies - 1 && q.size())
    {
        temp = q.top();
        q.pop();
        index1 = setLoc[temp.src];
        index2 = setLoc[temp.dest];        
        if (index1 != index2)
        {
            mst.push_back(temp);
            for (set<int>::iterator i = vertSets[index2].begin(); i != vertSets[index2].end(); i++)
            {
                vertSets[index1].insert((*i));
                setLoc[*i] = index1;
            }
        }
    }

    return mst;
}

double distanceForm(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}

int main()
{
    ll i, j, k;
	ll houses, existing, edges;
	double x, y;
	cin >> houses >> existing >> edges;
	vector<pair<double, double>> points;
	vector<vector<ll>> adj(houses);
	vector<mstEdge> result;
	for(i = 0; i < houses; i++)
	{
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	for(i = 0; i < existing; i++)
	{
		for(j = i + 1; j < existing; j++)
		{
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	ll first, second;
	for(i = 0; i < edges; i++)
	{
		cin >> first >> second;
		adj[first-1].push_back(second-1);
		adj[second-1].push_back(first-1);
	}

	result = kruskal(points, adj);
	double total = 0;
	for(mstEdge thing : result)
	{
		total += thing.distance;
		//cout << thing.src << " " << thing.dest << " " << thing.distance << "\n";
	}
	cout << fixed << setprecision(10);
	cout << total << "\n";
    return 0;
}
