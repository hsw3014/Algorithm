#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n, x1, y1, l1, x2, y2, l2;
	double d, r1, r2, rsum, rdif;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		rsum = r1 + r2;
		rdif = abs(r1 - r2);
		
		//동심원이고 같은원일경우
		if (d == 0 && rdif == 0) {
			cout << "-1";
		}
		//두점에서 만날경우
		else if (rdif < d && d < rsum) {
			cout << "2";
		}
		//한 점에서 만날경우(외접, 내접)
		else if (rsum == d || rdif == d) {
			cout << "1";
		}
		//만나지 않을 경우(포함관계, 동심원)
		else if(rsum < d || d < rdif || d == 0){
			cout << "0";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}