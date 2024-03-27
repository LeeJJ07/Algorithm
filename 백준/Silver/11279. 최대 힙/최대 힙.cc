#include <iostream>
#include <queue>
using namespace std;

int n, num;
priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> num;
        if (num) pq.push(num);
        else if (pq.size()) { cout << pq.top() << "\n"; pq.pop(); }
        else cout << 0 << '\n';
    }
}