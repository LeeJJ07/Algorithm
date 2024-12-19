#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b;
vector<int> sw;

void boy()
{
	int num = b;
	while (num <= N)
	{
		sw[num - 1] = 1 - sw[num - 1];
		num += b;
	}
}

void girl()
{
	b--;
	sw[b] = 1 - sw[b];
	for (int i = 1; i <= N / 2; i++)
	{
		int left = b - i;
		int right = b + i;
		if (left < 0 || right < 0 || left >= N || right >= N) break;
		if (sw[left] != sw[right]) break;
		sw[left] = 1 - sw[left];
		sw[right] = 1 - sw[right];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	sw.resize(N);
	for (int i = 0; i < N; i++) cin >> sw[i];
	cin >> M;
	while (M--)
	{
		cin >> a >> b;
		if (a == 1)
			boy();
		else
			girl();
	}

	for (int i = 0; i < N; i++)
	{
		cout << sw[i] << ' ';
		if (!((i + 1) % 20)) cout << '\n';
	}

	return 0;
}