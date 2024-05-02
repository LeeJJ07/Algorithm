#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double, pair<int, int>> p;

int n, parent[104];
double a, b, c, d, dtn, ret, tmp[104][2];
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

		if (find_root(s) == find_root(f)) continue;
		mst.push_back(cur_edge);

		union_find(f, s);

		if (mst.size() == n - 1) return mst;
	}
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i][0] >> tmp[i][1];
	}

	for (int i = 1; i < n; i++) {
		a = tmp[i][0], b = tmp[i][1];
		for (int j = i + 1; j <= n; j++) {
			c = tmp[j][0], d = tmp[j][1];
			dtn = sqrt(pow(c - a, 2) + pow(d - b, 2));
			edges.push_back({ dtn, {i, j} });
		}
	}

	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++) parent[i] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	vector<p> mst = kruskal();

	for (p dis : mst) ret += dis.first;

	cout << ret << '\n';
}