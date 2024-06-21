#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s)
{
    vector<string> res(2); int i;
    for (i = 0; s[i] != ' '; i++);
    res[0] = s.substr(0, i);
    res[1] = s.substr(i + 1);
    return res;
}

int solution(vector<string> friends, vector<string> gifts)
{
    int N = friends.size();

    map<string, int> m;
    for (int i = 0; i < N; i++)
        m[friends[i]] = i;

    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++)
        v[i].resize(N);

    for (int i = 0; i < gifts.size(); i++)
    {
        vector<string> vv = split(gifts[i]);
        v[m[vv[0]]][m[vv[1]]]++;
    }

    vector<int> zisu(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            zisu[i] += v[i][j];
            zisu[j] -= v[i][j];
        }
    }

    vector<int> res(N);
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i][j] == v[j][i])
            {
                if (zisu[i] > zisu[j]) res[i]++;
                else if (zisu[i] < zisu[j]) res[j]++;
            }
            else if (v[i][j] < v[j][i]) res[j]++;
            else res[i]++;
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) answer = max(answer, res[i]);
    return answer;
}