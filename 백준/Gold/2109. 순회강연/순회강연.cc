#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> cor;
int a, b, ret;
vector<cor> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b; v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) pq.pop();
	}
	while (pq.size()) {
		ret += pq.top(); pq.pop();
	}
	cout << ret << '\n';
}