#include <bits/stdc++.h>
using namespace std;
const int M = 100, N = 100;
int m, n;
int num[N][M];
int ans;
void dfs(int i, int j)
{
    if ((i < 0 || j < 0 || i >= n || j >= m) || num[i][j] == 0 || num[i][j] == 2)
    {
        return;
    }
    if (num[i][j] == 1)
    {
        num[i][j] = 2;
    }
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 1)
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}