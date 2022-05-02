#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int size = priorities.size();

    queue < pair < int, int> > q;
    priority_queue <int> mxq;
    vector <int> result;

    //우선순위와 그 위치 큐에 담으며 mxq엔 가장 높은 우선순위만 나오도록 함 
    for (int i = 0; i < size; i++) {
        q.push({ priorities[i], i});
        mxq.push(priorities[i]);
    }

    while (!q.empty()) {
        int p = q.front().first;
        int l = q.front().second;
        int max_p = mxq.top();

        q.pop();

        //뽑아야하면 결과로
        if (p == max_p) {
            result.push_back(l);
            mxq.pop();
        }
        else {
            q.push({ p, l });
        }
    }

    int rsize = result.size();
    for (int i = 0; i < rsize; i++) {
        if (result[i] == location) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}