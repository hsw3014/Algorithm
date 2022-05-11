#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void solution()
{
	//map은 레드블랙트리구조에 nlogn의 복잡도
	//map은 중복을 허용하지 않는 특징을 가짐
	//map은 기본적으로 map < key type, value type > 이름으로 선언된다.
	//데이터를 찾을 때 map.find()를 사용하고, 못찾으면 map.end() 반환한다
	//map.erase("key");로 특정 키 삭제도 가능
	int n;
	map <int, int> m;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		m.insert({ n % 42, n });
	}

	cout << m.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}