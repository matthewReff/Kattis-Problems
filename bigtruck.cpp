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

struct weightedEdge
{
    ll weight;
    ll src;
    ll dest;
};

struct dijkstraSegment
{
    ll dist = 99999999999;
    ll prev = -1;
    ll visited = 0;
    ll numSteps = 0;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll locations;
    ll edges;
    weightedEdge tempEdge;
    ll minVal;
    ll lastEdge;
    ll nextEdge;
    bool possible = true;
    cin >> locations;
    vector<ll> itemsAtLocation(locations);
    set<ll> vertexSet;
    set<ll>::iterator setIterator;
    for(i = 0; i < locations; i++)
    {
        cin >> itemsAtLocation[i];
    }
    
    cin >> edges;
    
    vector<vector<ll>> adj(locations);
    for(i = 0; i < locations; i++)
    {
        adj[i].resize(locations, -1);
    }
    for(i = 0; i < edges; i++)
    {
        cin >> tempEdge.src >> tempEdge.dest >> tempEdge.weight;
        adj[tempEdge.src - 1][tempEdge.dest - 1] = tempEdge.weight;
        adj[tempEdge.dest - 1][tempEdge.src - 1] = tempEdge.weight;      
    }
    
    vector<dijkstraSegment> dijkstraSegmentVector(locations);
    dijkstraSegmentVector[0].dist = 0;
    dijkstraSegmentVector[0].visited = itemsAtLocation[0];
    for(i = 0; i < locations; i++)
    {
        vertexSet.insert(i);
    }
    
    while(vertexSet.size() && possible)
    {
        //grab shortest distance edge
        //cout << "grabbing edge \n";
        
        setIterator = vertexSet.begin();
        minVal = 99999999999;
        while(setIterator != vertexSet.end())
        {
            if(minVal > dijkstraSegmentVector[*(setIterator)].dist)
            {
                minVal = dijkstraSegmentVector[*(setIterator)].dist;
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
        
        //find distances from found edge
        //cout << "calculating distances from edge " << lastEdge << "\n";
        for(ll next = 0; next < locations; next++)
        {
            //if weight from current edge to next is less than saved at next edge
            if(adj[next][lastEdge] != -1 && 
            adj[next][lastEdge] + dijkstraSegmentVector[lastEdge].dist <= 
            dijkstraSegmentVector[next].dist)
            {   
                //cout << "replacing in dijkstraSegment: " << 
                //adj[*setIterator][lastEdge] + dijkstraSegmentVector[lastEdge].dist
                //<< " " << lastEdge << "\n";
                
                //if equal distance, only change if more items will be touched
                if(adj[next][lastEdge] + dijkstraSegmentVector[lastEdge].dist == 
                dijkstraSegmentVector[next].dist && 
                dijkstraSegmentVector[next].visited < 
                dijkstraSegmentVector[lastEdge].visited + itemsAtLocation[next])
                {
                    dijkstraSegmentVector[next].prev = lastEdge;
                    
                    dijkstraSegmentVector[next].visited = 
                        dijkstraSegmentVector[lastEdge].visited + itemsAtLocation[next];
                        
                        //cout << "update type 1 \n";
                }
                
                //otherwise always change
                else if(adj[next][lastEdge] + dijkstraSegmentVector[lastEdge].dist < 
                dijkstraSegmentVector[next].dist)
                {
                    dijkstraSegmentVector[next].dist = 
                        adj[next][lastEdge] + dijkstraSegmentVector[lastEdge].dist;
                
                    dijkstraSegmentVector[next].prev = lastEdge;
                    
                    dijkstraSegmentVector[next].visited = 
                    dijkstraSegmentVector[lastEdge].visited + itemsAtLocation[next];
                    //cout << "update type 2 \n";
                }
            }
        }
        
        /*
        for(auto segment : dijkstraSegmentVector)
        {
            cout << segment.dist << " " << segment.visited << "\n";
        }
        cout << "\n";
        */
               
    }
    if(dijkstraSegmentVector[locations-1].dist == 99999999999)
    {   
        cout << "impossible\n";
    }
    else
    {
        cout << dijkstraSegmentVector[locations-1].dist << " " << 
            dijkstraSegmentVector[locations-1].visited << "\n";
    }
   
    
    return 0;
}
