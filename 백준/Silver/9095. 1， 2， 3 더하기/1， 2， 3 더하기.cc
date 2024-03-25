#include <iostream>
using namespace std;
int res;

void dfs(int num) {
    if (num == 0) {
        res++;
        return;
    }
    else if (num < 0) return;
    dfs(num - 3);
    dfs(num - 2);
    dfs(num - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, t; cin >> t;
    while (t--) {
        res = 0;
        cin >> n; dfs(n);
        cout << res << '\n';
    }
}