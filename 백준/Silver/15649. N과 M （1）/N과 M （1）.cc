#include<iostream>
#include<vector>

using namespace std;

int num[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
bool visit[8] = { false };
int n, m;
vector <int> q;

void backtrack(int idx)
{
	if (idx >= n) return;

	if (q.size() == m) {	//다 채웠음
		for (int i = 0; i < m; i++) {
			cout << q[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				q.push_back(num[i]);
				backtrack(i);
				visit[i] = false;
				q.pop_back();
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	backtrack(0);
}