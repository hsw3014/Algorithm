#include <string>
#include <vector>
#include <stack>

using namespace std;

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int size = prices.size();
    answer.resize(size);
    stack <int> s;
    int before;

    for (int i = 0; i < size; i++) {
        if (s.empty()) s.push(i);
        else {
            while (!s.empty() && prices[s.top()] > prices[i]) {
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }

    while (!s.empty()) {
        int now = s.top();
        answer[now] = size - now - 1;
        s.pop();
    }

    return answer;
}
