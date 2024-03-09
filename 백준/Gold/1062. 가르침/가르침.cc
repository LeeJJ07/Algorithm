#include <iostream>
using namespace std;

int n, k;
string sarr[51];
int visited[26];
int result = 0;

bool chkStr(int i) {
	for (int j = 4; j < sarr[i].size() - 4; j++) {
		if (!visited[sarr[i][j]-'a']) return false;
	}
	return true;
}

void dfsAlpha(int start, int depth) {
	if (depth == k - 5) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (chkStr(i)) res++;
		}
		if (res > result) result = res;
		return;
	}

	for (int i = start + 1; i < 26; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfsAlpha(i, depth + 1);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char arr[] = { 'a', 'n', 't', 'i', 'c' };
	for (char i : arr) visited[i - 'a'] = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> sarr[i];
	if (k < 5)cout << 0 << '\n';
	else {
		dfsAlpha(0, 0);
		cout << result << '\n';
	}
}