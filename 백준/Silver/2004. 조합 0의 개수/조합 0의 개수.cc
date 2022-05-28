#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	//nPm = n! / (n-m)!
	//nCm = nPm / m!
	//nCm = n! / (n-m)! * m!
	//즉, n!에서 나오는 5의 개수에서 (n-m)!과 m!의 5의 개수를 빼주면 nCm의 5의 개수 파악 가능
	//2도 마찬가지로 파악 가능
	long long piv = 5;

	int a = n; int b = n - m; int c = m;
	long long a1 = 0;
	long long b1 = 0;
	long long c1 = 0;

	//5의 개수 찾기
	while (piv <= n) {
		a1 += a / piv;
		b1 += b / piv;
		c1 += c / piv;
		piv *= 5;
	}

	int five_cnt = a1 - b1 - c1;
	a1 = 0, b1 = 0, c1 = 0;

	piv = 2;
	//2의 개수 찾기
	while (piv <= n) {
		a1 += a / piv;
		b1 += b / piv;
		c1 += c / piv;
		piv *= 2;
	}
	
	int two_cnt = a1 - b1 - c1;
	cout << min(five_cnt, two_cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}