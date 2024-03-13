#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int, string> node;

bool cmp(node a, node b) {
	if (get<1>(a) == get<1>(b))return get<0>(a) < get<0>(b);
	return get<1>(a) < get<1>(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<node> a(n);
	for (int i = 0; i < n; i++) {
		get<0>(a[i]) = i;
		cin >> get<1>(a[i]) >> get<2>(a[i]);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << get<1>(a[i]) << ' ' << get<2>(a[i]) << '\n';
	}
}