#include <iostream>
#include <vector>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    char c;
    int len = 0, res = 0;
    bool ioi = false;
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (!ioi && c == 'I') {
            ioi = !ioi;
            len++;
        }
        else if (ioi && c == 'O') {
            ioi = !ioi;
            len++;
        }
        else {
            int num = n * 2 + 1;
            len -= (len % 2 == 0) ? 1 : 0;
            if (len >= num) res += (len - num) / 2 + 1;
            if (c == 'I') { ioi = true; len = 1; }
            else { ioi = false; len = 0; }
        }
    }
    int num = n * 2 + 1;
    len -= (len % 2 == 0) ? 1 : 0;
    if (len >= num) res += (len - num) / 2 + 1;
    cout << res << '\n';
}