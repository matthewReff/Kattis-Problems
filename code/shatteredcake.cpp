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

typedef long long ll;
using namespace std;

int main()
{
	int i, j, k;
	int width;
	int chunks;
	int area = 0;
	int dim1, dim2;
	scanf("%d", &width);
	scanf("%d", &chunks);

	for (i = 0; i < chunks; i++)
	{
		scanf("%d %d", &dim1, &dim2);
		area += dim1 * dim2;
	}
	printf ( "%d\n", area / width);
	return 0;
}
