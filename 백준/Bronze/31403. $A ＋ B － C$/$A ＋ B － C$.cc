#include <iostream>

using namespace std;

int A, B, C, num = 1, tmp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    tmp = B;
    while (tmp > 0)
    {
        tmp /= 10;
        num *= 10;
    }

    cout << A + B - C << '\n';
    cout << A * num + B - C;

    return 0;
}