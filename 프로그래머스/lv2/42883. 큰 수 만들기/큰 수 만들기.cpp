#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    stack <char> s;
    s.push(number[0]);
    int size = number.size();

    for (int i = 1; i < size; i++) {
        char now = number[i];

        while (!s.empty() && s.top() < now && k > 0) {
            s.pop();
            k--;
        }
        
        s.push(now);
    }

    while (k > 0) {
        s.pop();
        k--;
    }

    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer;
}