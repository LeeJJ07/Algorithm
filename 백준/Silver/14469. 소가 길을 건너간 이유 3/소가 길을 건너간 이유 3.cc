#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b; v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (pair<int, int> next : v) {
		if (next.first > ret) ret = next.first + next.second;
		else ret += next.second;
	}
	cout << ret << '\n';
}