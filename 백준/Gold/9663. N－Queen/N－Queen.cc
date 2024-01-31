#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

static int N;
static int result;
void DFS(int h, vector<int> check);
bool possible(int h, int j, vector<int> check);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<int> check(N, -1);
	result = 0;
	for (int i = 0; i < N; i++) {
		check[i] = 0;
		DFS(1, check);
		check[i] = -1;
	}
	cout << result << "\n";

}

void DFS(int h, vector<int> check) {
	if (h == N) {
		result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] != -1)
			continue;
		if (!possible(h, i, check))
			continue;
		check[i] = h;
		DFS(h + 1, check);
		check[i] = -1;
	}
}
bool possible(int h, int j, vector<int> check) {
	for (int i = 0; i < N; i++) {
		if (check[i] == -1)
			continue;
		if (abs(check[i] - h) == abs(i - j))
			return false;
	}
	return true;
}
