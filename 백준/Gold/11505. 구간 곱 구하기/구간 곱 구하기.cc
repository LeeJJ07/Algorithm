#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;
static int MOD = 1000000007;
long getMul(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int Length = N;

	while (Length != 0) {
		Length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int startLeftIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), 1);

	for (int i = startLeftIndex + 1; i <= startLeftIndex + N; i++) {
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++) {
		int a, s, e;
		cin >> a >> s >> e;
		if (a == 1) {
			changeVal(startLeftIndex + s, e);
		}
		else if (a == 2) {
			s += startLeftIndex;
			e += startLeftIndex;
			cout << getMul(s, e) << "\n";
		}
	}
}
long getMul(int s, int e) {
	long partMul = 1;

	while (s <= e) {
		if (s % 2 == 1) {
			partMul = partMul * tree[s] % MOD;
			s++;
		}
		if (e % 2 == 0) {
			partMul = partMul * tree[e] % MOD;
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return partMul;
}
void changeVal(int index, long val) {
	tree[index] = val;
	while (index > 1) {
		index /= 2;
		tree[index] = tree[index * 2] % MOD * tree[index * 2 + 1] % MOD;
	}
}
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] = tree[i / 2] * tree[i] % MOD;
		i--;
	}
}