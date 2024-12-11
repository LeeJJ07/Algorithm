#include <iostream>
#include <vector>

using namespace std;

int N, M, a, b;
vector<int> friends[504];
bool visited[504];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0;i < M;i++) {
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0;i < friends[1].size(); i++) {
        visited[friends[1][i]] = true;
        for (int j : friends[friends[1][i]]) {
            if (visited[j])
                continue;
            visited[j] = true;
        }
    }
    int result = 0;
    for (int i = 2;i <= N;i++)
        if (visited[i])
            result++;
    cout << result;
    
    return 0;
}