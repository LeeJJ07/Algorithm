#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c, res = 0;
    cin >> a >> b >> c;

    if (a == b && a == c) res = 10000 + a * 1000;
    else if (a == b || a == c) res = 1000 + a * 100;
    else if (b == c) res = 1000 + b * 100;
    else res = max(max(a, b), c) * 100;
    
    cout << res;

    return 0;
}