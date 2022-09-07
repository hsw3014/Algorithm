#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

typedef struct type {
	string name;
	int lan;
	int eng;
	int math;
}entry;

bool cmp(const entry a, const entry b) {
	if (a.lan == b.lan) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.lan > b.lan;
}

void solution()
{
	int n;
	vector <entry> v;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char name[20];
		int lan, eng, math;
		entry temp;

		//공백 기준 입력 별도로 받기위한 scanf
		scanf("%s %d %d %d", name, &lan, &eng, &math);
		temp.name = name;
		temp.lan = lan;
		temp.eng = eng;
		temp.math = math;

		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);

	//string은 printf로 출력할 수 없기에 변형
	for (int i = 0; i < n; i++) {
		char output[20];
		printf("%s\n", strcpy(output, v[i].name.c_str()));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}