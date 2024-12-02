#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    stack<pair<int, char>> stk;
    for (int i = 0; i < number.size();i++) {
        if (stk.empty())
            stk.push({ i, number[i] });
        else {
            while (stk.size() && k && stk.top().second < number[i]) {
                stk.pop();
                k--;
            }
            stk.push({ i, number[i] });
            if (k == 0) {
                while (++i < number.size())
                    stk.push({ i, number[i] });
                break;
            }
        }
    }
    while (stk.size())
    {
        if (k) {
            k--;
            stk.pop();
            continue;
        }
        answer = stk.top().second + answer;
        stk.pop();
    }

    return answer;
}