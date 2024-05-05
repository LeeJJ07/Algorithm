#include <iostream>
using namespace std;

int n, m, u, v, parent[500004], res;
int find_root(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_root(parent[x]);
}

void union_find(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}
bool check(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	return x == y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		if (res) continue;
		if (check(u, v)) res = i;
		union_find(u, v);
	}
	cout << res << '\n';
}