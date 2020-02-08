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

    ll nums;
    cin >> nums;
    ll highestParity = floor(log2(nums)) + 1;
    vector<ll> answer(nums+1, 0);
    ll currentBit = 0;
    for(i = 0; i < highestParity; i++)
    {
    	ll numResponses = 0;
    	cout << "ASK ";
    	vector<ll> questions;
    	for(j = 1; j <= nums; j++)
    	{
    		vector<ll> question;
    		if((j & (1<<currentBit)) != 0)
    		{
    			questions.push_back(j);
    		}
    	}
    	cout << questions.size() << " ";
    	for(j = 0; j < (int)questions.size(); j++)
    	{
    		cout << questions[j] << " ";
    	}
    	cout << "\n";
    	cout.flush();

    	for(j = questions.size(); j > 0; j--)
    	{
    		ll response;
    		cin >> response;
    		answer[response] += pow(2, currentBit);
    	}
    	currentBit++;
    }

    cout << "ANSWER ";
    for(i = 1; i < (int)answer.size(); i++)
    {
    	cout << answer[i] << " ";
    }
    cout << "\n";
    cout.flush();

    return 0;
}
