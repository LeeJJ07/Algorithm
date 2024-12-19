#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> cats;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    cats.resize(N);
    for (int i = 0;i < N;i++) {
        cin >> cats[i];
    }
    sort(cats.begin(), cats.end());

    int result = 0;
    int s = 0, e = N - 1;
    while (s < e) {
        if (cats[s] + cats[e] <= K) {
            result++;
            s++, e--;
        }
        else
            e--;
    }
    cout << result;
    return 0;
}