#include <iostream>

using namespace std;

int N;
int sz[6];
int T, P;
int res;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0;i < 6;i++)
        cin >> sz[i];
    cin >> T >> P;

    for (int i = 0;i < 6;i++)
        res += (sz[i] - 1) / T + (sz[i] ? 1 : 0);
    
    cout << res << '\n';
    cout << N / P << ' ' << N % P;

    return 0;
}