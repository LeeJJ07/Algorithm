#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int H, W, N;
		cin >> H >> W >> N;
		int f, b;
		if (N % H == 0) {
			f = H;
			b = N / H;
		}
		else {
			f = N % H;
			b = N / H+1;
		}
		printf("%d%02d\n", f, b);
	}
}