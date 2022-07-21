#include<iostream>
#include<queue>

using namespace std;

const int MAX = 105;
int board[MAX][MAX][MAX] = { 0 };
int visit[MAX][MAX][MAX] = { 0 };

int m, n, h, t;

typedef struct entry {
	int H;
	int N;
	int M;
}entry;

void bfs()
{
	int rest = 0;
	int result = -1;

	queue <entry> q;
	entry temp;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (board[i][j][k] == 0)	//안익은 토마토
					rest++;
				else if (board[i][j][k] == 1) {	//익은 토마토 = 시작점
					temp.H = i; temp.N = j; temp.M = k;
					q.push(temp);
				}
			}
		}
	}

	entry now;

	if (rest == 0) {
		cout << "0";
		return;
	}

	while (q.size() != 0) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			now = q.front();
			q.pop();

			visit[now.H][now.N][now.M] = 1;

			if (board[now.H - 1][now.N][now.M] == 0 && visit[now.H - 1][now.N][now.M] == 0) {
				board[now.H - 1][now.N][now.M] = 1;
				visit[now.H - 1][now.N][now.M] = 1;
				temp.H = now.H - 1; temp.N = now.N; temp.M = now.M;
				q.push(temp);
				rest--;
			}

			if (board[now.H + 1][now.N][now.M] == 0 && visit[now.H + 1][now.N][now.M] == 0) {
				board[now.H + 1][now.N][now.M] = 1;
				visit[now.H + 1][now.N][now.M] = 1;
				temp.H = now.H + 1; temp.N = now.N; temp.M = now.M;
				q.push(temp);
				rest--;
			}

			if (board[now.H][now.N - 1][now.M] == 0 && visit[now.H][now.N - 1][now.M] == 0) {
				board[now.H][now.N - 1][now.M] = 1;
				visit[now.H][now.N - 1][now.M] = 1;
				temp.H = now.H; temp.N = now.N - 1; temp.M = now.M;
				q.push(temp);
				rest--;
			}

			if (board[now.H][now.N + 1][now.M] == 0 && visit[now.H][now.N + 1][now.M] == 0) {
				board[now.H][now.N + 1][now.M] = 1;
				visit[now.H][now.N + 1][now.M] = 1;
				temp.H = now.H; temp.N = now.N + 1; temp.M = now.M;
				q.push(temp);
				rest--;
			}

			if (board[now.H][now.N][now.M - 1] == 0 && visit[now.H][now.N][now.M - 1] == 0) {
				board[now.H][now.N][now.M - 1] = 1;
				visit[now.H][now.N][now.M - 1] = 1;
				temp.H = now.H; temp.N = now.N; temp.M = now.M - 1;
				q.push(temp);
				rest--;
			}

			if (board[now.H][now.N][now.M + 1] == 0 && visit[now.H][now.N][now.M + 1] == 0) {
				board[now.H][now.N][now.M + 1] = 1;
				visit[now.H][now.N][now.M + 1] = 1;
				temp.H = now.H; temp.N = now.N; temp.M = now.M + 1;
				q.push(temp);
				rest--;
			}
		}
		result++;
	}

	if (rest > 0)
		cout << "-1";
	else
		cout << result;
}

int main()
{
	cin >> m >> n >> h;

	for (int i = 0; i <= h+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			for (int k = 0; k <= m+1; k++) {
				board[i][j][k] = -1;
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> board[i][j][k];
			}
		}
	}

	bfs();
}