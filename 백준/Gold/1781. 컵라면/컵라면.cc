#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b; v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) pq.pop();
	}
	int ret = 0;
	while (pq.size()) {
		ret += pq.top(); pq.pop();
	}
	cout << ret << '\n';
}