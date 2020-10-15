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
    
    ll numNames;
    bool sorted;
    string tempString;
    
    
    while(cin >> numNames && numNames != 0)
    {
        vector<string> studentNames(numNames);
        for(i = 0; i < numNames; i++)
        {
            cin >> studentNames[i];
        }
        
        sorted = false;
        while(!sorted)
        {
            sorted = true;
            for(i = 0; i < numNames - 1; i++)
            {
                if(studentNames[i][0] > studentNames[i+1][0])
                {
                    tempString = studentNames[i];
                    studentNames[i] = studentNames[i+1];
                    studentNames[i+1] = tempString;
                    sorted = false;
                }
                else if(studentNames[i][0] == studentNames[i+1][0] &&
                studentNames[i][1] > studentNames[i+1][1])
                {
                    tempString = studentNames[i];
                    studentNames[i] = studentNames[i+1];
                    studentNames[i+1] = tempString;
                    sorted = false;
                }
            }
        }
        
        
        for(auto name : studentNames)
        {
            cout << name << "\n";
        }
        cout << "\n";
    }
    return 0;
}
