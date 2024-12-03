#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> input(N);
    for (int idx = 0;idx < N;idx++)
        cin >> input[idx];

    vector<int> line(N, 0);

    for (int idx = 0; idx < N; idx++) {
        for (int j = 0; j < N; j++) {
            if (line[j])
                continue;
            if (!input[idx]) {
                line[j] = idx + 1;
                break;
            }
            input[idx]--;
        }
    }
    for (int idx = 0; idx < N; idx++)
        cout << line[idx] << ' ';

    return 0;
}