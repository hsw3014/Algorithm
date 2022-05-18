#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

typedef struct entry {
	int age;
	string name;
	int when;
}entry;

bool cmp(const entry& a, const entry& b)
{
	if (a.age == b.age) return a.when < b.when;
	return a.age < b.age;
}

void solution()
{
	int n, age;
	string str;
	vector < entry > v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> str;
		v.push_back({ age, str, i });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].age << " " << v[i].name << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}