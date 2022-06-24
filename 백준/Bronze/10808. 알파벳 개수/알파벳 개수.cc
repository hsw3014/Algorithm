#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int arr[30] = { 0 };
	string str;
	cin >> str;
	
	int size = str.length();

	for (int i = 0; i < size; i++) {
		arr[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}