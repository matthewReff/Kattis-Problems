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
#include <unordered_set>

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


int main()
{
    ll i, j, k;
    
    ll s, q;
ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char command;
    ll left, right;
    cin >> s >> q;
    parent.resize(s, 0);
    sizeArr.resize(s, 0);
    for(i = 0; i < s; i++)
    {
    	make_set(i);
    }
    for(i = 0; i < q; i++)
    {
        cin >> command >> left >> right;
        if(command == '?')
        {
            if(find_set(left) == find_set(right))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
        else
        {
        	union_sets(left, right);
        }
    }
    return 0;
}
