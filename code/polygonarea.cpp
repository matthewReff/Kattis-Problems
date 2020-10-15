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
#include <set>

typedef long long ll;
using namespace std;

#define EPSILON 0.000001

struct point
{
    long double x, y;
    point(long double x_ = 0, long double y_ = 0) : x(x_), y(y_) {}
    // Only < operator is unusual behavior
    bool operator <(const point& other) const
    {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
    bool operator == (const point& other) const
    {
        return abs(other.x - x) < EPSILON && abs(other.y - y) < EPSILON;
    }
    //Add other operators as needed
};

long double polyArea(const vector<point>& points)
{
    long double result = 0;
    for (int i = 0, j = 1; i<points.size(); i++, j = (j + 1) % points.size())
    {
        result += points[i].x * points[j].y;
        result -= points[i].y * points[j].x;
    }
    return result / 2;
}

int main()
{
    ll i;
    ll points;
    vector<point> myPoints;
    long double ans;

    cout << fixed << setprecision(1);
    while (cin >> points && points != 0)
    {
        myPoints.clear();
        for (i = 0; i < points; i++)
        {
            point temp;
            cin >> temp.x;
            cin >>temp.y;
            myPoints.push_back(temp);
        }
        ans = polyArea(myPoints);
        if (ans > 0)
        {
            cout << "CCW " << ans << "\n";
        }
        else
        {
            cout << "CW " << fabs(ans) << "\n";
        }
    }

    return 0;

}

