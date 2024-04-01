#include <iostream>
#include <cmath>
using namespace std;
#define y1 xoxoxoxo

int t, x1, y1, x2, y2, n, cx, cy, r, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        res = 0;
        while (n--) {
            cin >> cx >> cy >> r;
            if (pow(cx - x1, 2) + pow(cy - y1, 2) < pow(r, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) > pow(r, 2)) res++;
            else if (pow(cx - x1, 2) + pow(cy - y1, 2) > pow(r, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) < pow(r, 2)) res++;
        }
        cout << res << '\n';
    }
}