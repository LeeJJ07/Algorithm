#include <iostream>
#include <cmath>
using namespace std;
#define y1 xoxoxoxo

int t, x1, y1, r1, x2, y2, r2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << '\n';
        else if (pow(r2 - r1, 2) == pow(x2 - x1, 2) + pow(y2 - y1, 2)) cout << 1 << '\n';
        else if (pow(r1 + r2, 2) == pow(x2 - x1, 2) + pow(y2 - y1, 2)) cout << 1 << '\n';
        else if (pow(r2 - r1, 2) > pow(x2 - x1, 2) + pow(y2 - y1, 2)) cout << 0 << '\n';
        else if (pow(r1 + r2, 2) < pow(x2 - x1, 2) + pow(y2 - y1, 2)) cout << 0 << '\n';
        else cout << 2 << '\n';
    }
}