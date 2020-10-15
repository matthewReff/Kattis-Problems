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
typedef long double ld;
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

vector<mstEdge> kruskal(vector<pair<double, double> > points)
{
    priority_queue<mstEdge> q;
    int verticies = points.size();
    vector< set< int > > vertSets(verticies);
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
    while (mst.size() != verticies - 1)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ull i, j, k;
    ll cases;
    ll numPoints;
    double src, dest;

    cin >> cases;
    for (i = 0; i < cases; i++)
    {
        mstEdge temp;
        vector<mstEdge> mst;
        priority_queue<mstEdge> q;
        vector<pair<double, double > > points;
        double total = 0.0;
        cin >> numPoints;
        
        for (j = 0; j < numPoints; j++)
        {
            cin >> src >> dest;
            points.push_back(make_pair(src, dest));
        }

     
        mst = kruskal(points);
        
        for (auto element : mst)
        {
            total += element.distance;
        }
        
        cout << fixed << setprecision(2);
        cout << total << "\n";
    }
    
    return 0;
}
