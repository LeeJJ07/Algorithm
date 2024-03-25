#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    set<int> s;
    int a, b, num;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> num; s.insert(num);
    }
    for (int i = 0; i < b; i++) {
        cin >> num; s.insert(num);
    }
    cout << 2 * s.size() - a - b << '\n';
}