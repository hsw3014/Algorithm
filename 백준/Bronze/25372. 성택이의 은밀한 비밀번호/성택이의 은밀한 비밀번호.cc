#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
 
using namespace std;
 
void solution()
{
	int n;
	string str;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> str;
		if(6 <= str.length() && str.length() <= 9) cout << "yes\n";
		else cout << "no\n";
	}
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	solution();
}