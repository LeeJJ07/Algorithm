#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

bool cmp(node a, node b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<node> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end(), cmp);
	for (node i : a)
		cout << i.first << ' ' << i.second << '\n';
}