#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, K, a, b, res = 0;
    cin >> N >> K;

    int cl[6][2] = { 0 };
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        cl[b - 1][a]++;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res += cl[i][j] / K + (cl[i][j] % K ? 1 : 0);
        }
    }

    cout << res << '\n';
    
	return 0;
}