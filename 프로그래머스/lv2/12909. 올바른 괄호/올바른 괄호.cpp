#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int size = s.size();

    stack <char> st;
    
    for (int i = 0; i < size; i++) {
        char now = s[i];
        
        if (now == '(') {
            st.push(now);
        }
        else {
            if (st.empty()) {
                answer = false;
                break;
            }
            else {
                st.pop();
            }
        }
        
    }

    if (!st.empty()) answer = false;

    return answer;
}