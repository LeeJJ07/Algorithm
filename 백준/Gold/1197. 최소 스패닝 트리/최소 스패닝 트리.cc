#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> p;
int n, m, ret, parent[10004];
vector<p> edges;

int find_root(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_root(parent[x]);
}

void union_find(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if (x != y) parent[y] = x;
}
vector<p> kruskal() {
	vector<p> mst;

	for (int i = 0; i < edges.size(); i++) {
		p cur_edge = edges[i];

		int f = cur_edge.second.first;
		int s = cur_edge.second.second;

		if (find_root(f) == find_root(s)) continue;

		mst.push_back(cur_edge);
		union_find(f, s);

		if (mst.size() == n - 1) return mst;
	}
}
void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++) parent[i] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	vector<p> mst = kruskal();

	for (int i = 0; i < mst.size(); i++) {
		ret += mst[i].first;
	}
	cout << ret << '\n';
}