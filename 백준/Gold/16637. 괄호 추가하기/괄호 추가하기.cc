#include <iostream>
#include <climits>
using namespace std;

int N;
int a[14];
char b[14];
int c[14];
int result = INT_MIN;

void DFS(int sum, int idx) {
	
	if (idx == N / 2 + 1) {
		result = max(result, sum);
		return;
	}
	if (idx == 0) {
		DFS(sum + a[idx], idx + 1);
		if (idx != N / 2){
			DFS(sum+c[idx], idx + 2);
		}
	}
	else {
		if (b[idx - 1] == '+') {
			DFS(sum + a[idx], idx + 1);
			if (idx != N / 2) {
				DFS(sum+c[idx], idx + 2);
			}
		}
		else if (b[idx - 1] == '-') {
			DFS(sum - a[idx], idx + 1);
			if (idx != N / 2) {
				DFS(sum - c[idx], idx + 2);
			}
		}
		else if (b[idx - 1] == '*') {
			DFS(sum * a[idx], idx + 1);
			if (idx != N / 2) {
				DFS(sum * c[idx], idx + 2);
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N / 2 + 1; i++) {
		cin >> a[i];
		if (i == N / 2) break;
		cin >> b[i];
	}
	for (int i = 0; i < N / 2; i++) {
		if (b[i] == '+') {
			c[i] = a[i] + a[i + 1];
		}
		else if (b[i] == '-') {
			c[i] = a[i] - a[i + 1];
		}
		else if (b[i] == '*') {
			c[i] = a[i] * a[i + 1];
		}
	}
	DFS(0, 0);
	cout << result << '\n';
}