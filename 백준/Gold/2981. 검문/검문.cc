#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void divisor(int n)
{
	vector < int > v;
	int piv = sqrt(n);
	v.push_back(n);

	//약수넣기, 1만 제외
	for (int i = 2; i <= piv; i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (n / i != i) v.push_back(n / i);
		}
	}

	//오름차순
	sort(v.begin(), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
}

void solution()
{
	//어떤 수들을 m으로 나눴을때 나머지 r이 모두 같은 상황
	//a[1] = (a[1] / m) * m + r
	//a[2] = (a[2] / m) * m + r...
	//r = a[1] - (a[1] / m) * m
	//a[2] = (a[2] / m) * m + a[1] - (a[1] / m) * m
	//a[1] - a[2] = (a[1] / m - a[2] / m) * m
	//즉, 같은 나머지 r을 가진다는 전제 하에
	//앞수에서 뒷수를 뺀수는 공통적인 m을 가진다는 의미다.
	//이 말은 a[1] - a[2], a[2] - a[3], ... , a[n-1] - a[n] 총 n-1개의 수가 있고
	//이 수들은 공통된 m들을 가진다는 의미이며
	//공통된 m들은 이 수들의 최대공약수의 약수이다.

	int n, num, temp;
	vector < int > v;
	vector < int > vv;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	//a[1] - a[2]가 양수이기 위한 내림차순 정렬
	sort(v.begin(), v.end(), greater <int>());

	int now_gcd;
	
	//복수개의 최대공약수구하기
	for (int i = 0; i < n - 1; i++) {
		vv.push_back(v[i] - v[i + 1]);
		if (i == 0) {
			now_gcd = vv[i];
			continue;
		}
		now_gcd = gcd(now_gcd, vv[i]);
	}

	//구해진 최대공약수의 약수 중 1을 제외하고 출력하면 정답
	divisor(now_gcd);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}