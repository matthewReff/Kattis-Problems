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

vector<ll> parent;
vector<ll> sizeArr;

//shamelessly stolen from
//https://cp-algorithms.com/data_structures/disjoint_set_union.html
void make_set(int v) {
    parent[v] = v;
    sizeArr[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizeArr[a] < sizeArr[b])
            swap(a, b);
        parent[b] = a;
        sizeArr[a] += sizeArr[b];
    }
}

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

vector<mstEdge> kruskal(priority_queue<mstEdge> q, int verticies)
{
	parent.resize(verticies, 0);
	sizeArr.resize(verticies, 0);

	for(int i = 0; i < verticies; i++)
	{
		make_set(i);
	}
    vector<mstEdge> mst;
    mstEdge temp;
    int index1, index2;
    while ((int)mst.size() != verticies - 1)
    {
        temp = q.top();
        q.pop();
        index1 = find_set(temp.src);
        index2 = find_set(temp.dest);
        
        if (index1 != index2)
        {
            mst.push_back(temp);
            union_sets(index1, index2);
            //vertSets.erase(vertSets.begin() + index2);
        }
    }

    return mst;
}

struct point
{
    double x, y;
};

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll cases;
    ll numPoints;
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
    	cin >> numPoints;

    	parent.clear();
    	sizeArr.clear();
    	priority_queue<mstEdge> q;
    	vector<mstEdge> mst;
		vector<point> pointList;
		point temp;
		mstEdge tempEdge;
    	for (j = 0; j < numPoints; j++)
	    {
	        cin >> temp.x;
	        cin >> temp.y;
	        pointList.push_back(temp);
	    }

    	for (j = 0; j < numPoints; j++)
	    {
			for (k = j + 1; k < numPoints; k++)
	        {
	        	tempEdge.distance = sqrt((pointList[j].x - pointList[k].x) * 
	            	(pointList[j].x - pointList[k].x) +
	            	(pointList[j].y - pointList[k].y) *
	            	(pointList[j].y - pointList[k].y));
	        	tempEdge.src = j;
	        	tempEdge.dest = k;
	        	//cout << tempEdge.distance << " " << tempEdge.src << " " << tempEdge.dest << "\n";
	        	q.emplace(tempEdge);
	    	}
		}

     	mst = kruskal(q, numPoints);


	    double total = 0;
	    for (auto element : mst)
	    {
	    	//cout << "dist: " << element.distance << "\n";
	        total += element.distance;
	    }
	    cout << fixed << setprecision(10);
	    cout << total << "\n";
    }

    return 0;
}
