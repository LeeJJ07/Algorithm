#include <iostream>
#include <set>

using namespace std;

int N, M, num, i, x;
int trains[100004];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while (M--) {
        cin >> num;
        switch (num) {
        case 1:
            cin >> i >> x;
            trains[i] |= (1 << (x - 1));
            break;
        case 2:
            cin >> i >> x;
            trains[i] &= (~(1 << (x - 1)));
            break;
        case 3:
            cin >> i;
            trains[i] <<= 1;
            trains[i] &= (~(1 << 20));
            break;
        case 4:
            cin >> i;
            trains[i] >>= 1;
            break;
        }
    }
    set<int> result;
    for (int i = 1; i <= N;i++)
        result.insert(trains[i]);
    cout << result.size();
    return 0;
}