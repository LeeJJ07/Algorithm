#include <iostream>
#include <vector>

using namespace std;

int n, m, h;
int a, b;
int mp[31][11];
int num;

bool findRes;
bool checkRes() {
	
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (mp[j][start] == 1) start++;
			else if (mp[j][start] == 2) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void DFS(int here, int depth) {
	if (findRes) return;
	if (depth == num) {
		if (checkRes()) findRes = true;
		return;
	}
	for (int i = here; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (mp[i][j] == 0 && mp[i][j + 1] == 0) {
				mp[i][j] = 1; mp[i][j + 1] = 2;
				DFS(i, depth + 1);
				mp[i][j] = 0; mp[i][j + 1] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mp[a][b] = 1;
		mp[a][b + 1] = 2;
	}

	for (num = 0; num <= 3; num++) {
		DFS(1, 0);
		if (findRes) break;
	}
	if (num == 4)cout << -1;
	else cout << num;
}