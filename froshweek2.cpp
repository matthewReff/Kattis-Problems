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
    
    ll tasks, quiets;
    ll pin = 0;
    //ll complete = 0;
    cin >> tasks >> quiets;
    vector<ll> taskList(tasks);
    vector<ll> quietList(quiets);
    
    for(i = 0; i < tasks; i++)
    {
        cin >> taskList[i];
    }
    for(i = 0; i < quiets; i++)
    {
        cin >> quietList[i];
    }
    
    sort(taskList.rbegin(), taskList.rend());
    sort(quietList.rbegin(), quietList.rend());
    
    for(i = 0; i < taskList.size(); i++)
    {
        if(quietList[pin] >= taskList[i])
        {
            pin++;
            //complete++;
        }   
    }
    
    cout << pin << "\n";
    return 0;
}
