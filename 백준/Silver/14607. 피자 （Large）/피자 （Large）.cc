#include <iostream>

using namespace std;

long long N;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cout << N * (N - 1) / 2;

    return 0;
}