#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int board[25][25] = { 0 };

void solution()
{
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> board[i][j];
		}
	}

	//8방향 탐색, 육목이상은 실패이므로 좌우상하 1개씩 더봄
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (board[i][j] == 1 || board[i][j] == 2) {
				int now = board[i][j];
				if (i - 4 >= 1) {	//위로 5개
					if (board[i - 1][j] == now && board[i - 2][j] == now && board[i - 3][j] == now && board[i - 4][j] == now && board[i - 5][j] != now && board[i + 1][j] != now) {
						cout << now << '\n' << i - 4 << " " << j;	//가장 위에것
						return;
					}
					else if(j - 4 >= 1){	//왼쪽위로 5개
						if (board[i - 1][j - 1] == now && board[i - 2][j - 2] == now && board[i - 3][j - 3] == now && board[i - 4][j - 4] == now && board[i - 5][j - 5] != now && board[i + 1][j + 1] != now) {
							cout << now << '\n' << i - 4 << " " << j - 4;
							return;
						}
					}
					else if (j + 4 <= 19) {	//오른쪽위로 5개
						if (board[i - 1][j + 1] == now && board[i - 2][j + 2] == now && board[i - 3][j + 3] == now && board[i - 4][j + 4] == now && board[i - 5][j + 5] != now && board[i + 1][j - 1] != now) {
							cout << now << '\n' << i << " " << j;
							return;
						}
					}
				}
				if (i + 4 <= 19) { //아래로 5개
					if (board[i + 1][j] == now && board[i + 2][j] == now && board[i + 3][j] == now && board[i + 4][j] == now && board[i + 5][j] != now && board[i - 1][j] != now) {
						cout << now << '\n' << i << " " << j;	//가장 위에것
						return;
					}
					else if (j - 4 >= 1) {	//왼쪽아래로 5개
						if (board[i + 1][j - 1] == now && board[i + 2][j - 2] == now && board[i + 3][j - 3] == now && board[i + 4][j - 4] == now && board[i + 5][j - 5] != now && board[i - 1][j + 1] != now) {
							cout << now << '\n' << i + 4 << " " << j - 4;
							return;
						}
					}
					else if (j + 4 <= 19) {	//오른쪽아래로 5개
						if (board[i + 1][j + 1] == now && board[i + 2][j + 2] == now && board[i + 3][j + 3] == now && board[i + 4][j + 4] == now && board[i + 5][j + 5] != now && board[i - 1][j - 1] != now) {
							cout << now << '\n' << i << " " << j;
							return;
						}
					}
				}
				//좌우로 5개
				if (j - 4 >= 1) {
					if (board[i][j - 1] == now && board[i][j - 2] == now && board[i][j - 3] == now && board[i][j - 4] == now && board[i][j - 5] != now && board[i][j + 1] != now) {
						cout << now << '\n' << i << " " << j - 4;
						return;
					}
				}
				if (j + 4 <= 19) {
					if (board[i][j + 1] == now && board[i][j + 2] == now && board[i][j + 3] == now && board[i][j + 4] == now && board[i][j + 5] != now && board[i][j - 1] != now) {
						cout << now << '\n' << i << " " << j;
						return;
					}
				}
			}
		}
	}

	cout << "0";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}