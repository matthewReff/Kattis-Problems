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
    string line;
    vector<string> chart;
    vector<string> transposedChart;

    int tempNum;
    vector<vector<string>> numbers= { {"+---+",
                                       "|   |",
                                       "|   |",
                                       "+   +",
                                       "|   |",
                                       "|   |",
                                       "+---+"},

                                      { "    +",
                                        "    |",
                                        "    |",
                                        "    +",
                                        "    |",
                                        "    |",
                                        "    +"},

                                       {"+---+",
                                        "    |",
                                        "    |",
                                        "+---+",
                                        "|    ",
                                        "|    ",
                                        "+---+"},
                                
                                       {"+---+",
                                        "    |",
                                        "    |",
                                        "+---+",
                                        "    |",
                                        "    |",
                                        "+---+"},

                                       {"+   +",
                                        "|   |",
                                        "|   |",
                                        "+---+",
                                        "    |",
                                        "    |",
                                        "    +"},

                                       {"+---+",
                                        "|    ",
                                        "|    ",
                                        "+---+",
                                        "    |",
                                        "    |",
                                        "+---+"},

                                       {"+---+",
                                        "|    ",
                                        "|    ",
                                        "+---+",
                                        "|   |",
                                        "|   |",
                                        "+---+"},
            
                                       {"+---+",
                                        "    |",
                                        "    |",
                                        "    +",
                                        "    |",
                                        "    |",
                                        "    +"},

                                       {"+---+",
                                        "|   |",
                                        "|   |",
                                        "+---+",
                                        "|   |",
                                        "|   |",
                                        "+---+"},

                                       {"+---+",
                                        "|   |",
                                        "|   |",
                                        "+---+",
                                        "    |",
                                        "    |",
                                        "+---+"},

                                       {" ",
                                        " ",
                                        "o",
                                        " ",
                                        "o",
                                        " ",
                                        " "}


                                        };
                            
    string time;
    while (cin >> time && time != "end")
    {
        for (i = 0; i < 7; i++)
        {
            for(j = 0; j < time.size(); j++)
            {
                if (time[j] == ':')
                {
                    tempNum = 10;
                }
                else
                {
                    tempNum = time[j] - '0';
                }
                for (auto littleChar : numbers[tempNum][i])
                {
                    cout << littleChar;
                }
                if(j != time.size() -1)
                {
                    cout << "  ";
                }

            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    cout << time << "\n";
    return 0;
}

