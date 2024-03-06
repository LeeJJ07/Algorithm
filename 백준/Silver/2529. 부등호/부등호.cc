#include <iostream>
#include <vector>
using namespace std;

int n;
char c[12];
int visited[10];
vector<int> resultMax;
vector<int> resultMin;
vector<int> result1;
vector<int> result2;
bool findMax;
bool findMin;

void dfsMax(int depth, int Prev) {
	if (findMax) return;
	if (depth == n) {
		result1 = resultMax;
		findMax = true;
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (visited[i]) continue;
		if (c[depth] == '>' && Prev < i) continue;
		if (c[depth] == '<' && Prev > i) continue;
		visited[i] = 1;
		resultMax.push_back(i);
		dfsMax(depth+1, i);
		resultMax.pop_back();
		visited[i] = 0;
	}
}
void dfsMin(int depth, int Prev) {
	if (findMin) return;
	if (depth == n) {
		result2 = resultMin;
		findMin = true;
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		if (c[depth] == '>') if (Prev < i) continue;
		if (c[depth] == '<') if (Prev > i) continue;
		visited[i] = 1;
		resultMin.push_back(i);
		dfsMin(depth + 1, i);
		resultMin.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 9; i >= 0; i--) {
		visited[i] = 1;
		resultMax.push_back(i);
		dfsMax(0, i);
		resultMax.pop_back();
		visited[i] = 0;
	}
	fill(&visited[0], &visited[10], 0);
	for (int i = 0; i < 10; i++) {
		visited[i] = 1;
		resultMin.push_back(i);
		dfsMin(0, i);
		resultMin.pop_back();
		visited[i] = 0;
	}
	for (int i : result1) cout << i;
	cout << '\n';
	for (int i : result2) cout << i;
}