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
#include <unordered_set>

#define EPSILON 0.00001
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

//return index of set that contains the element in vector of sets
int findSet(vector< set< int > > vertSets, int element)
{
    for (unsigned int i = 0; i < vertSets.size(); i++)
    {
        set<int>::iterator j = vertSets[i].begin();
        while (j != vertSets[i].end())
        {
            if ((*j) == element)
            {
                return i;
            }
            j++;
        }
    }
    return -1;
}


vector<mstEdge> kruskal(priority_queue<mstEdge> q, int verticies)
{
    vector< set< int > > vertSets(verticies);
    unordered_map<int, int> setLoc;
    for (int i = 0; i < verticies; i++)
    {
        vertSets[i].insert(i);
        setLoc[i] = i;
    }
    vector<mstEdge> mst;
    mstEdge temp;
    int index1, index2;
    while (mst.size() != verticies - 1)
    {
        temp = q.top();
        q.pop();
        index1 = setLoc[temp.src];
        index2 = setLoc[temp.dest];
        //index1 = findSet(vertSets, temp.dest);
        //index2 = findSet(vertSets, temp.src);
        
        if (index1 != index2)
        {
            mst.push_back(temp);
            for (set<int>::iterator i = vertSets[index2].begin(); i != vertSets[index2].end(); i++)
            {
                vertSets[index1].insert((*i));
                setLoc[*i] = index1;
            }
            //vertSets.erase(vertSets.begin() + index2);
        }
    }

    return mst;
}

struct sata
{
    int rad;
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ull i, j, k;
    ll sats;
    cin >> sats;
    sata temp;
    mstEdge tempEdge;
    priority_queue<mstEdge> q;
    vector<mstEdge> mst;
    vector<sata> satList;
    for (i = 0; i < sats; i++)
    {
        cin >> temp.x;
        cin >> temp.y;
        cin >> temp.rad;
        satList.push_back(temp);
    }
    
    for (i = 0; i < satList.size(); i++)
    {
        for (j = i + 1; j < satList.size(); j++)
        {
            tempEdge.distance = sqrt((satList[i].x - satList[j].x) * 
                (satList[i].x - satList[j].x) +
                (satList[i].y - satList[j].y) *
                (satList[i].y - satList[j].y)) - satList[i].rad - satList[j].rad;
            tempEdge.src = i;
            tempEdge.dest = j;
            q.emplace(tempEdge);
        }
    }
    mst = kruskal(q, sats);

    ld total = 0;
    for (auto element : mst)
    {
        total += element.distance;
    }
    cout << fixed << setprecision(10);
    cout << total << "\n";
    return 0;
}

