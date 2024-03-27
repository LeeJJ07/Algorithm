#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1001], prev_list[1001], cnt[1001], ret = 1, idx;
void go(int idx) {
    if (idx == -1)return;
    go(prev_list[idx]);
    cout << a[idx] << ' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill(prev_list, prev_list + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    cout << ret << '\n';
    go(idx);
}