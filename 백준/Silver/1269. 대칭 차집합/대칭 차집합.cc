#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int arr[200005];
int brr[200005];

void solution()
{
	int a, b, n;
	cin >> a >> b;
	map < int, int > ma, mb;

	for (int i = 0; i < a; i++) {
		cin >> n;
		ma.insert({ n, 1 });
		arr[i] = n;
	}

	for (int i = 0; i < b; i++) {
		cin >> n;
		mb.insert({ n, 1 });
		brr[i] = n;
	}

	int A, B;
	map < int, int > ta, tb;
	ta = ma; tb = mb;

	//A - B
	for (int i = 0; i < b; i++) {
		ta.erase(brr[i]);
	}

	//B - A
	for (int i = 0; i < a; i++) {
		tb.erase(arr[i]);
	}

	cout << ta.size() + tb.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}