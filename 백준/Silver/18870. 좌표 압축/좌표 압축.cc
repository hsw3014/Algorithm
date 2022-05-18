#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int arr[1000005];

bool cmp(const pair <int ,int> a, const pair <int, int> & b)
{
	return a.first < b.first;
}

void solution()
{
	int n, num;
	map < int, int > m;

	cin >> n;
	//중복없이 입력받음
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
		m.insert({num, num});
	}
	
	//오름차순 정렬
	vector < pair <int, int> > v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	//해당번호를 키값으로 0~n 번호매김
	map < int, int > m2;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		m2[v[i].first] = i;
	}

	//키값에 맞는 번호 출력
	for (int i = 0; i < n; i++) {
		cout << m2[arr[i]] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}