#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;
const int INF = 1e9 + 4;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(lis, lis + 1000004, INF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if (*lowerPos == INF) len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }
    cout << len << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            stk.push(ans[i].second); len--;
        }
    }
    while (stk.size()) {
        cout << stk.top() << ' '; stk.pop();
    }
}