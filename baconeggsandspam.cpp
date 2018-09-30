#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;
   
    ll cases;
    string key;
    string value;
    map<string, vector<string>> mappyBoi;

    while (cin >> cases && cases != 0)
    {
        mappyBoi.clear();
        for (i = 0; i < cases; i++)
        {
            cin >> key;
            while (cin.peek() != '\n')
            {
                cin >> value;
                mappyBoi[value].push_back(key);
            }
        }
        for (auto key : mappyBoi)
        {
            cout << key.first << " ";
            sort(mappyBoi[key.first].begin(), mappyBoi[key.first].end());
            for (auto name : mappyBoi[key.first])
            {
                cout << name << " ";
            }
            cout << "\n";
        }
    }


    return 0;
}