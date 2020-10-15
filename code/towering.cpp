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
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k, l;

	ll a, b, c, d, e, f;
	ll height1, height2;
	ll boxes[6];
	ll stack1[3];
	ll stack2[3];
	bool found = false;
	cin >> a >> b >> c >> d >> e >> f >> height1 >> height2;

	boxes[0] = a;
	boxes[1] = b;
	boxes[2] = c;
	boxes[3] = d;
	boxes[4] = e;
	boxes[5] = f;

	sort(boxes, boxes + 6);

	do
	{
		if (boxes[0] + boxes[1] + boxes[2] == height1 && boxes[3] + boxes[4] + boxes[5] == height2)
		{
			found = true;
			stack1[0] = boxes[0];
			stack1[1] = boxes[1];
			stack1[2] = boxes[2];
			stack2[0] = boxes[3];
			stack2[1] = boxes[4];
			stack2[2] = boxes[5];
		}
	} while (next_permutation(boxes, boxes + 6) && !found);

	sort(stack1, stack1 + 3);
	sort(stack2, stack2 + 3);

	for (i = 0; i < 3; i++)
	{
		cout << stack1[3 - i - 1] << " ";
	}
	for (i = 0; i < 3; i++)
	{
		cout << stack2[3 - i - 1] << " ";
	}

	return 0;
}