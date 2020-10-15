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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll commands;
    ll type, val;
    bool isStack, isQueue, isPQueue;
    while(cin >> commands)
    {
        isStack = true;
        isQueue = true;
        isPQueue = true;
        queue<ll> q;
        stack<ll> s;
        priority_queue<ll> pq;
        for(i = 0; i < commands; i++)
        {
            cin >> type >> val;
            if (type == 1)
            {
                s.push(val);
                pq.emplace(val);
                q.push(val);
            }
            else
            {
                if(s.size() != 0)
                {
                    if(s.top() != val)
                    {
                        isStack = false;
                    }
                    if(q.front() != val)
                    {
                        isQueue = false;
                    }
                    if(pq.top() != val)
                    {
                        isPQueue = false;
                    }
                    s.pop();
                    q.pop();
                    pq.pop();
                }
                else
                {
                    isStack = false;
                    isQueue = false;
                    isPQueue = false;
                }
            }
        }
        
        if(isStack || isQueue || isPQueue)
        {
            if(isStack && !isQueue && !isPQueue)
            {
                cout << "stack\n";
            }
            else if (!isStack && isQueue && !isPQueue)
            {
                cout << "queue\n";
            }
            else if (!isStack && !isQueue && isPQueue)
            {
                cout << "priority queue\n";
            }
            else
            {
                cout << "not sure\n";
            }
        }
        else
        {
            cout << "impossible\n";
        }
    }
    
    
    
    return 0;
}
