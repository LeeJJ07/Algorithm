#include <iostream>
#include <string>
using namespace std;

const int r = 31;
const int M = 1234567891;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l, i;
    long long hash = 0, R = 1;
    string str;

    cin >> l >> str;
    for (i = 0; i < str.length(); i++) {
        hash += ((str[i] - 'a' + 1) * R) % M; hash %= M;
        R = (R * r) % M;
    }
    cout << hash;
}