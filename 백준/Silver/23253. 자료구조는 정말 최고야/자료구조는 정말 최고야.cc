#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

void solution()
{
	bool answer = true;
	int n, m, num, size, before;
	int idx = 0;
	cin >> n >> m;

	//idx값에따라 별도의 벡터스택에 담는다.
	//모든 더미가 내림차순인지 확인하면 된다.
	for (int i = 1; i <= 2 * m; i++) {
		if (i % 2 == 1) {
			cin >> size;
			idx++;
			before = 999999;
		}
		else {
			for (int j = 1; j <= size; j++) {
				cin >> num;
				if (num > before) {
					answer = false;
				}
				else {
					before = num;
				}
			}
		}
	}

	if (answer) cout << "Yes";
	else cout << "No";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}