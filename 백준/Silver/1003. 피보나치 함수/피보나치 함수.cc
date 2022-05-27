#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
	int t;
    int n;
    pair <int, int> pa[45];
    pa[0] = { 1, 0 };
    pa[1] = { 0, 1 };

    for (int i = 2; i <= 40; i++) {
        int now_x = pa[i - 2].first + pa[i - 1].first;
        int now_y = pa[i - 2].second + pa[i - 1].second;
        pa[i] = { now_x, now_y };
    }
	cin >> t;
	for (int i = 0; i < t; i++) {
        cin >> n;
        cout << pa[n].first << " " << pa[n].second << "\n";
	}
}

int main()
{
	solve();
}