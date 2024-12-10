#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C, N;
int m[204][204], temp[204][204];
int mx[4] = { 0, 1, 0, -1 };
int my[4] = { -1, 0, 1, 0 };

void InputData() {
    cin >> R >> C >> N;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C;c++) {
            char input;
            cin >> input;
            if (input == '.') {
                m[r][c] = 0;
                continue;
            }
            m[r][c] = 2;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    InputData();

    for(int n = 1; n < N; n++){
        memset(temp, -1, sizeof(temp));
        for (int r = 0; r < R;r++) {
            for (int c = 0;c < C;c++) {
                if (n & 1 && !m[r][c])
                    m[r][c] = 3;
                else {
                    m[r][c]--;
                    if (!m[r][c]) {
                        temp[r][c] = 0;
                        for (int i = 0; i < 4; i++) {
                            int ny = my[i] + r;
                            int nx = mx[i] + c;
                            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                                continue;
                            temp[ny][nx] = 0;
                        }
                    }
                }
            }
        }
        if (n & 1)
            continue;
        for (int r = 0; r < R;r++) {
            for (int c = 0; c < C;c++) {
                if (temp[r][c]) continue;
                m[r][c] = temp[r][c];
            }
        }
    }

    for (int r = 0; r < R;r++) {
        for (int c = 0; c < C; c++) {
            if (m[r][c] == 0) {
                cout << '.';
                continue;
            }
            cout << 'O';
        }
        cout << '\n';
    }

    return 0;
}