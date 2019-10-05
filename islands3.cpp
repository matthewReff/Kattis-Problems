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

void floodFill(ll i, ll j, vector<string> &image, vector<vector<bool>> &found, ll height, ll width)
{
    found[i][j] = true;
    ll tempi, tempj;
    for (ll k = 0; k < 4; k++)
    {
        switch (k) {
        case 0:
            tempi = i - 1;
            tempj = j;
            break;
            break;
        case 1:
            tempi = i;
            tempj = j + 1;
            break;
        case 2:
            tempi = i + 1;
            tempj = j;
            break;
            break;
        case 3:
            tempi = i;
            tempj = j - 1;
            break;
        };


        if (tempi >= 0 && tempi < height && tempj >= 0 &&
            tempj < width && !found[tempi][tempj] &&
            (image[tempi][tempj] == 'L' || image[tempi][tempj] == 'C'))
        {
            floodFill(tempi, tempj, image, found, height, width);
            //cout << k << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;

    ll height, width;
    ll islands;
    ll tracker = 1;
    cin >> height >> width;
    
    vector<string> image(height);
    vector < vector<bool> > found(height);
    islands = 0;
    for (i = 0; i < height; i++)
    {
        found[i].resize(width);
        cin >> image[i];
    }


    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (image[i][j] == 'L' && !found[i][j])
            {
                floodFill(i, j, image, found, height, width);
                islands++;
            }
        }
    }
    cout << islands << "\n";
    tracker++;
    return 0;
}