#include <iostream>
#include <queue>
using namespace std;

int n, num;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> num;
        if (pq.empty() && !num) cout << "0\n";
        else if (!num) { cout << pq.top() << '\n'; pq.pop(); }
        else pq.push(num);
    }
}