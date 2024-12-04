#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int start = n / 5;

    while (start >= 0) {
        if (!((n - start * 5) & 1))
            break;

        start--;
    }
    if (start < 0) {
        cout << -1;
        return 0;
    }
    cout << start + (n - start * 5) / 2;
    return 0;
}