#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        a.push_back(i);
    }
    int result = 4;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = a[i] * a[i];
        if (sum == n) {
            result = 1; break;
        }
        if (result < 3) continue;
        for (int j = i; j >= 0; j--) {
            int sum1 = sum + a[j] * a[j];
            if (sum1 == n) {
                result = 2; break;
            }
            if (result < 4)continue;
            for (int k = j; k >= 0; k--) {
                int sum2 = sum1 + a[k] * a[k];
                if (sum2 == n) {
                    result = 3; break;
                }
            }
        }
    }
    cout << result << '\n';
}