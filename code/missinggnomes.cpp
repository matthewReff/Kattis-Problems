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
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	ll len, seqLen, temp, index1, index2;
	cin >> len >> seqLen;
	vector<bool> in(len, false);
	vector<bool> out(len, true);
	vector<int> seq1, seq2;
	vector<ll> outSeq;
	for (i = 0; i < seqLen; i++)
	{
		cin >> temp;
		seq1.push_back(temp);
		out[temp - 1] = false;
	}

	for (i = 0; i < len; i++)
	{
		if (out[i])
		{
			seq2.push_back(i + 1);
		}
	}
	//reverse(seq1.begin(), seq1.end());
	//reverse(seq2.begin(), seq2.end());
	seq1.push_back(99999999);
	seq2.push_back(99999999);
	index1 = 0;
	index2 = 0;

	while (len--)
	{
		if (seq1[index1] < seq2[index2])
		{
			outSeq.push_back(seq1[index1]);
			index1++;
		}
		else
		{
			outSeq.push_back(seq2[index2]);
			index2++;
		}
	}

	for (auto element : outSeq)
	{
		cout << element << "\n";
	}
	return 0;
}
