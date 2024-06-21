#include <iostream>
#include <vector>

using namespace std;

int level[10004];
int par[10004];

void saveLevel(int index)
{
    if (level[index] != -1) return;
    if (!par[index]) {
        level[index] = 0;
        return;
    }
    saveLevel(par[index]);
    level[index] = level[par[index]] + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, N, a, b;
    cin >> T;
    while (T--) {
        cin >> N;
        fill(&level[0], &level[10004], -1);
        fill(&par[0], &par[10004], 0);
        for(int i = 1;i<N;i++){
            cin >> a >> b;
            par[b] = a;
        }
        
        for (int i = 1; i <= N; i++)
            saveLevel(i);

        cin >> a >> b;
        int la = level[a], lb = level[b];
        if (la > lb) for (int i = 0; i < la - lb; i++) a = par[a];
        else if(la<lb) for (int i = 0; i < lb - la; i++) b = par[b];
        while (a != b)
        {
            a = par[a];
            b = par[b];
        }
        cout << a << '\n';
    }
    return 0;
}