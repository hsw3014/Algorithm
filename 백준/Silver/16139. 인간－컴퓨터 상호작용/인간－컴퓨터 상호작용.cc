#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[30][200005];	//dp[알파벳][범위]
string str;
int q, l, r;
char c;

void solution()
{
	int size;
	cin >> str;
	size = str.size();

	for (int i = 0; i < 27; i++) {
		for (int j = 1; j <= size; j++) {
			//a~z까지 문자가 존재
			dp[i][j] = dp[i][j - 1];
			if (str[j - 1] - 0 == 'a' + i) {
				dp[i][j]++;	//문자가 있으니 1 증가
			}
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> c >> l >> r;
		cout << dp[c - 'a'][r + 1] - dp[c - 'a'][l] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}