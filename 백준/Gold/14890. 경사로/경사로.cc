#include <iostream>
using namespace std;

int N, L;
int result;
int n[104][104];
int visited[104];
bool chk1(int i) {
	int prev = 0;
	int prevNum = n[i][0];
	int prevCount = 1;
	for (int j = 1; j < N; j++) {
		if (n[i][j] == prevNum) prevCount++;
		else if (n[i][j] > n[i][prev] + 1) return false;
		else if (n[i][j] == n[i][prev] + 1) {
			if (prevCount >= L) {
				for (int k = 0; k < L; k++) {
					visited[prev - k] = 1;
				}
			}
			else return false;
			prevNum = n[i][j];
			prevCount = 1;
		}
		else if (n[i][j] < n[i][prev]) {
			prevNum = n[i][j];
			prevCount = 1;
		}
		prev = j;
	}
	return true;
}
bool chk2(int i) {
	int prev = N-1;
	int prevNum = n[i][N-1];
	int prevCount = 1;
	for (int j = N-2; j >= 0; j--) {
		if (n[i][j] == prevNum) prevCount++;
		else if (n[i][j] > n[i][prev] + 1) return false;
		else if (n[i][j] == n[i][prev] + 1) {
			if (prevCount >= L) {
				for (int k = 0; k < L; k++) {
					if (visited[prev + k] == 1) return false;
					visited[prev + k] = 1;
				}
			}
			else return false;
			prevNum = n[i][j];
			prevCount = 1;
		}
		else if (n[i][j] < n[i][prev]) {
			prevNum = n[i][j];
			prevCount = 1;
		}
		prev = j;
	}
	return true;
}
bool chk3(int j) {
	int prev = 0;
	int prevNum = n[0][j];
	int prevCount = 1;
	for (int i = 1; i < N; i++) {
		if (n[i][j] == prevNum) prevCount++;
		else if (n[i][j] > n[prev][j] + 1) return false;
		else if (n[i][j] == n[prev][j] + 1) {
			if (prevCount >= L) {
				for (int k = 0; k < L; k++) {
					visited[prev - k] = 1;
				}
			}
			else return false;
			prevNum = n[i][j];
			prevCount = 1;
		}
		else if (n[i][j] < n[prev][j]) {
			prevNum = n[i][j];
			prevCount = 1;
		}
		prev = i;
	}
	return true;
}
bool chk4(int j) {
	int prev = N-1;
	int prevNum = n[N-1][j];
	int prevCount = 1;
	for (int i = N-2; i >= 0; i--) {
		if (n[i][j] == prevNum) prevCount++;
		else if (n[i][j] > n[prev][j] + 1) return false;
		else if (n[i][j] == n[prev][j] + 1) {
			if (prevCount >= L) {
				for (int k = 0; k < L; k++) {
					if (visited[prev + k] == 1) return false;
					visited[prev + k] = 1;
				}
			}
			else return false;
			prevNum = n[i][j];
			prevCount = 1;
		}
		else if (n[i][j] < n[prev][j]) {
			prevNum = n[i][j];
			prevCount = 1;
		}
		prev = i;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cin >> n[i][j];
	}

	for (int i = 0; i < N; i++) {
		fill(&visited[0], &visited[104], 0);
		if (chk1(i) && chk2(i))result++;
	}
	for (int j = 0; j < N; j++) {
		fill(&visited[0], &visited[104], 0);
		if (chk3(j) && chk4(j))result++;
	}
	cout << result << '\n';
}