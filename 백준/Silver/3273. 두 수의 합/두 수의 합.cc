#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, X;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> X;

    sort(arr.begin(), arr.end());

    int s = 0, e = N - 1;

    int res = 0;
    while (s < e)
    {
        if (arr[s] + arr[e] == X)
        {
            s++;
            e--;
            res++;
        }
        else if (arr[s] + arr[e] > X)
            e--;
        else
            s++;
    }
    cout << res << '\n';

	return 0;
}