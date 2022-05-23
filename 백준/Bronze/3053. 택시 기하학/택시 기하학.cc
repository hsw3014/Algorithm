#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pi 3.1415926535897932

void solution()
{
	int n;
	double a, b;
	scanf("%d", &n);
	a = n * n * pi;
	b = n * n * 2;
	printf("%.6f\n%.6f", a, b);
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	solution();
}