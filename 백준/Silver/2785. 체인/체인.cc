#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> chains;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    chains.resize(N);
    for (int i = 0;i < N;i++)
        cin >> chains[i];
    
    sort(chains.begin(), chains.end());

    N--;
    int start = 0;
    int result = 0;
    while (start < N) {
        if (N - start > chains[start]) {
            result += chains[start];
            N -= chains[start];
            start++;
        }
        else {
            result += N - start;
            break;
        }
    }

    cout << result << '\n';
    return 0;
}