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

struct Toy
{
    string name;
    ll quantity;
    bool operator<(Toy other)
    {
        if(quantity == other.quantity)
        {
            return name > other.name;
        }
        else
        {
            return quantity < other.quantity;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ll entries;
    ll numToys;
    Toy temp;
    string toy;
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
        map<string, ll> toyStock;
        map<string, ll>::iterator itr;
        cin >> entries;
        for(j = 0; j < entries; j++)
        {
            cin >> toy >> numToys;
            toyStock[toy] += numToys;
        }
        cout << toyStock.size() << "\n";
        vector<Toy> toySortingVector;
        itr = toyStock.begin();
        while(itr != toyStock.end())
        {
            temp.name = itr->first;
            temp.quantity = itr->second;
            toySortingVector.push_back(temp);
            itr++;
        }
        
        sort(toySortingVector.rbegin(), toySortingVector.rend());
        
        for(auto thing : toySortingVector)
        {
            cout << thing.name << " " << thing.quantity << "\n";
        }
    }
    
    return 0;
}
