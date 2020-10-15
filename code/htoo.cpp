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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    map<char, ll> inMolecule;
    ll numIn;
    map<char, ll> outMolecule;

    while(cin.peek() != ' ')
    {
    	char element;
    	ll numElement = 1;
    	cin >> element;
    	if(isdigit(cin.peek()))
    	{
    		cin >> numElement;
    	}
    	inMolecule[element] += numElement;
    	//cout << "added: " << char(element) << " " << numElement << "\n";
    }

    cin >> numIn;
    cin.ignore();
    auto inItr = inMolecule.begin();
    while(inItr != inMolecule.end())
    {
    	inItr->second *= numIn;
    	inItr++;
    }

	while(isalpha(cin.peek()))
    {
    	char element;
    	ll numElement = 1;
    	cin >> element;
    	if(isdigit(cin.peek()))
    	{
    		cin >> numElement;
    	}
    	outMolecule[element] += numElement;
    	//cout << "added: " << char(element) << " " << numElement << "\n";
    }

    

    bool valid = true;
    ll maxSoFar = 2000000000;
    auto outItr = outMolecule.begin();
    while(valid && outItr != outMolecule.end())
    {
    	if(inMolecule.find(outItr->first) != inMolecule.end())
    	{
    		//cout << "char : " << char(inItr->first) << "\n";
    		//cout << "inNum: " << inMolecule[inItr->first] << "\n";
    		//cout << "outNum: " << outMolecule[inItr->first] << "\n";
    		maxSoFar = min(maxSoFar, inMolecule[outItr->first] / outMolecule[outItr->first]);
    	}
    	else
    	{
    		valid = false;
    	}
    	outItr++;
    }

    if(!valid)
    {
    	cout << 0 << "\n";
    }
    else
    {
    	cout << maxSoFar << "\n";
    }
    return 0;
}
//Start: Wed Feb 19 13:20:38 MST 2020
