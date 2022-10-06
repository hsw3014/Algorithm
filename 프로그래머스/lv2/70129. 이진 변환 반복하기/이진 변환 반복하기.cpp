#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zcnt = 0;

    while(s != "1") {
        int size = s.size();
        string temp;

        int zero = 0;
        int one = 0;

        for (int i = 0; i < size; i++) {
            if (s[i] == '0') zero++;
            else one++;
        }

        zcnt += zero;

        while (one > 0) {
            int mod = one % 2;
            one /= 2;
            if (mod == 1) {
                temp += '1';
            }
            else {
                temp += '0';
            }
        }

        reverse(temp.begin(), temp.end());
        s = temp;
        cnt++;
    }

    answer.push_back(cnt);
    answer.push_back(zcnt);

    return answer;
}