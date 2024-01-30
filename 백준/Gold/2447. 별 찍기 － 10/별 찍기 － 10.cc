#include <iostream>
#include <climits>
using namespace std;

void DFS(char** map, int length, int x, int y);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	char** map = new char*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = '*';
		}
	}
	DFS( map, N, 0, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void DFS(char** map, int length, int x, int y) {
	if (length == 1)
		return;
	int sliceL = length / 3;
	for (int i = x + sliceL; i < x + sliceL * 2; i++) {
		for (int j = y + sliceL; j < y + sliceL * 2; j++) {
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 1 && i == 1)
				continue;
			DFS(map, sliceL, x+sliceL * i, y+sliceL * j);
		}
	}
}
