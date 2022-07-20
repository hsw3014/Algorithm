#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int good[105] = { 0 }; // 추천수 배열
int t[105] = { 0 }; // 게시 기간 배열

bool comp(const int o1, const int o2) {
	if (good[o1] == good[o2]) {
		if (t[o1] < t[o2]) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (good[o1] > good[o2]) {
		return true;
	}
	else {
		return false;
	}
}

void solution() {
	int n, c;
	vector<int> photo;

	cin >> n >> c;

	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;

		good[x]++;

		for (int j = 0; j < photo.size(); j++) {
			t[photo[j]]++;
		}

		bool exist = false;

		for (int j = 0; j < photo.size(); j++) {
			if (photo[j] == x) {
				exist = true;
				break;
			}
		}

		if (!exist) {
			if (photo.size() < n) {
				photo.push_back(x);
			}
			else {
				sort(photo.begin(), photo.end(), comp);
				// 재정의한 정렬 기준에 따라 사진틀 정렬
				good[photo.back()] = 0;
				t[photo.back()] = 0;
				photo.back() = x;
			}
		}

	}

	sort(photo.begin(), photo.end()); // 후보 오름차순 정렬

	for (int i = 0; i < photo.size(); i++) {
		cout << photo[i] << " ";
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}