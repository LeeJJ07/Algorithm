#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, result = 987654321;
int s[2][14];

int GetValue(int num) {
    int res1 = 0, res2 = 1;
    for (int i = 0;i < N;i++)
    {
        res1 += s[1][i] * ((num >> i) & 1);
        res2 *= (((num >> i) & 1) == 1 ? s[0][i] : 1);
    }
    return abs(res1 - res2);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0;i < N;i++)
        cin >> s[0][i] >> s[1][i];
    
    for (int i = 1; i < pow(2, N); i++)
        result = min(result, GetValue(i));

    cout << result << '\n';
    return 0;
}