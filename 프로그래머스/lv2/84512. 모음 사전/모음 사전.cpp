#include <string>
#include <vector>

using namespace std;

char c[5] = { 'A', 'E', 'I', 'O', 'U' };
int res;
int cnt = -1;
bool out = false;

void dfs(string now, string word)
{
    if (now.size() > 5 || out) return;

    cnt++;
    if (now == word) {
        res = cnt;
        out = true;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (out) break;
        dfs(now + c[i], word);
    }
}

int solution(string word) {
    int answer = 0;

    dfs("", word);

    answer = res;
    return answer;
}