#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void solution()
{
	int t, a, b, mod, answer, mod2;
	int c2[4] = { 2, 4, 8, 6 };
	int c3[4] = { 3, 9, 7, 1 };
	int c4[2] = { 4, 6 };
	int c7[4] = { 7, 9, 3, 1 };
	int c8[4] = { 8, 4, 2, 6 };
	int c9[2] = { 9, 1 };

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;

		mod = a % 10;
		b--;

		switch (mod)
		{
		case 0:
			answer = 10;
			break;
		case 1:
			answer = 1;
			break;
		case 2:
			mod2 = b % 4;
			answer = c2[mod2];
			break;
		case 3:
			mod2 = b % 4;
			answer = c3[mod2];
			break;
		case 4:
			mod2 = b % 2;
			answer = c4[mod2];
			break;
		case 5:
			answer = 5;
			break;
		case 6:
			answer = 6;
			break;
		case 7:
			mod2 = b % 4;
			answer = c7[mod2];
			break;
		case 8:
			mod2 = b % 4;
			answer = c8[mod2];
			break;
		case 9:
			mod2 = b % 2;
			answer = c9[mod2];
			break;
		default:
			break;
		}

		cout << answer << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}