#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<pair<int, int>> scores(N);
        for (int i = 0;i < N;i++)
            cin >> scores[i].first >> scores[i].second;
        
        sort(scores.begin(), scores.end());

        int result = 0, maxValue = scores[0].second;
        for (int i = 1;i < N;i++) {
            if (scores[i].second > maxValue)
                result++;
            else
                maxValue = scores[i].second;
        }
        cout << N - result << '\n';
    }
    
    return 0;
}