#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, a;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; v.push_back(a);
	}
	cin >> x;
	sort(v.begin(), v.end());
	int s = 0, e = v.size() - 1;
	int ret = 0;
	while (s < e) {
		if (v[s] + v[e] == x) {
			ret++;
			s++; e--;
		}
		else if (v[s] + v[e] > x) e--;
		else s++;
	}
	cout << ret << '\n';
}