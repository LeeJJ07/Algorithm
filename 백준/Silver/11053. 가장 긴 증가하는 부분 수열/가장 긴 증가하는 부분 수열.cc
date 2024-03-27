#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 10000;
int n, lis[1001], len, num;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(lis, lis + 1001, INF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lowerPos - lis);
        if (*lowerPos == INF) len++;
        *lowerPos = num;
    }
    cout << len << '\n';
}