#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 2005;
int n, c;
vector < pair <int, int> > v;

typedef struct node {
	int from;
	int to;
	int len;
}node;

vector <node> nv;
vector <int> parent;

void merge(int x, int y)
{
	if (x != y)
		parent[x] = y;
}

int checking(int cur)
{
	if (cur == parent[cur])	//부모 도달
		return cur;
	return parent[cur] = checking(parent[cur]);
}

bool compare(node a, node b)
{
	return a.len < b.len;
}

int get_length(int x1, int y1, int x2, int y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void solve()
{
	int now_x, now_y;
	int next_x, next_y;
	int length;
	node temp;

	//노드간의 거리 모두 저장
	for (int i = 0; i < n; i++) {
		now_x = v[i].first;
		now_y = v[i].second;
		for (int j = i+1; j < n; j++) {
			next_x = v[j].first;
			next_y = v[j].second;
			length = get_length(now_x, now_y, next_x, next_y);

			temp.from = i;
			temp.to = j;
			temp.len = length;
			
			nv.push_back(temp);
		}
	}

	sort(nv.begin(), nv.end(), compare);

	int cnt = 0;
	int size = nv.size();
	int result = 0;
	int from, to, len;
	int c1, c2;

	for (int i = 0; i < size; i++) {
		from = nv[i].from;
		to = nv[i].to;
		len = nv[i].len;

		if (len < c)
			continue;

		c1 = checking(from);
		c2 = checking(to);

		//부모가 같으면 건너뜀
		if (c1 == c2)
			continue;

		merge(c1, c2);
		cnt++;
		result += len;
	}

	if (cnt == n - 1)
		cout << result;
	else
		cout << "-1";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	int x, y;
	parent.resize(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
		parent[i+1] = i+1;
	}

	solve();
}