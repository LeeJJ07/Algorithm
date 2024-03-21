#include <iostream>
using namespace std;

int T, K, b, c;
int a[1004][8];
void _rotate_r(int t) {
    int tmp = a[t][7];
    for (int i = 7; i > 0; i--) {
        a[t][i] = a[t][i - 1];
    }
    a[t][0] = tmp;
}
void _rotate_l(int t) {
    int tmp = a[t][0];
    for (int i = 0; i < 7; i++) {
        a[t][i] = a[t][i + 1];
    }
    a[t][7] = tmp;
}

void rdfs(bool bang, int t) {
    if (t != T && a[t][2] != a[t + 1][6]) rdfs(!bang, t + 1);
    if (bang) _rotate_r(t);
    else _rotate_l(t);
}
void ldfs(bool bang, int t) {
    if (t != 1 && a[t - 1][2] != a[t][6]) ldfs(!bang, t - 1);
    if (bang) _rotate_r(t);
    else _rotate_l(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        string str; cin >> str;
        for (int j = 0; j < 8; j++) {
            a[i][j] = str[j] - '0';
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> b >> c; bool bang;
        if (c > 0) bang = true; else bang = false;
        if (b != T && a[b][2] != a[b + 1][6]) rdfs(!bang, b + 1);
        if (b != 1 && a[b][6] != a[b - 1][2]) ldfs(!bang, b - 1);
        if (bang) _rotate_r(b);
        else _rotate_l(b);
    }
    int res = 0;
    for (int i = 1; i <= T; i++) {
        if (a[i][0]) res++;
    }
    cout << res << '\n';
}