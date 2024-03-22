#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, M, r, c, s, d, z;
int shark[10004][5];
int a[104][104];
int temp[104][104];

void _move_shark() {
	memset(temp, 0, sizeof(temp));
	for (int i = 1; i <= M; i++) {
		if (shark[i][0] == -1) continue;
		int y = shark[i][0], x = shark[i][1];
		for (int j = 1; j <= shark[i][2]; j++) {
			if (shark[i][3] == 1) {
				if (y == 1) {
					shark[i][3] = 2; y++;
				}
				else y--;
			}
			else if (shark[i][3] == 2) {
				if (y == R) {
					shark[i][3] = 1; y--;
				}
				else y++;
			}
			else if (shark[i][3] == 3) {
				if (x == C) {
					shark[i][3] = 4; x--;
				}
				else x++;
			}
			else if (shark[i][3] == 4) {
				if (x == 1) {
					shark[i][3] = 3; x++;
				}
				else x--;
			}
		}
		if (temp[y][x] == 0) {
			temp[y][x] = i;
			shark[i][0] = y; shark[i][1] = x;
		}
		else {
			if (shark[temp[y][x]][4] < shark[i][4]) {
				shark[temp[y][x]][0] = -1;
				temp[y][x] = i;
				shark[i][0] = y; shark[i][1] = x;
			}
			else shark[i][0] = -1;
		}
	}
	memcpy(a, temp, sizeof(a));
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> shark[i][j];
		}
		a[shark[i][0]][shark[i][1]] = i;
		if (shark[i][3] > 2) { shark[i][2] %= (C - 1) * 2; }
		else { shark[i][2] %= (R - 1) * 2; }
	}
	int result = 0;
	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
			if (a[i][j] != 0) {
				result += shark[a[i][j]][4];
				shark[a[i][j]][0] = -1;
				break;
			}
		}
		if (j == C) break;
		_move_shark();
	}
	cout << result << '\n';
}