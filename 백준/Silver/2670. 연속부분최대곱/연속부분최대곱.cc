#include <iostream>
using namespace std;
int n;
double psum[10001], a[10001], ret, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    double b = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > b * a[i])b = a[i];
        else b *= a[i];
        ret = max(b, ret);
    }
    printf("%.3lf", ret + 0.00001);
}