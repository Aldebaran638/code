#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
const int M = 1000;
bool dis[N];
int n;
int maxdis;

int stat[M][N];
int dfs(int lastJ, int pos)
{
    int tmpdis = 0;
    if (stat[lastJ][pos])
    {
        return stat[lastJ][pos];
    }
    if (dis[pos + lastJ + 1])
        tmpdis = max(tmpdis, dfs(lastJ + 1, pos + lastJ + 1));
    if (dis[pos + lastJ])
        tmpdis = max(tmpdis, dfs(lastJ, pos + lastJ));
    if (dis[pos + lastJ - 1] && lastJ > 1)
        tmpdis = max(tmpdis, dfs(lastJ - 1, pos + lastJ - 1));
    tmpdis = max(pos, tmpdis);
    stat[lastJ][pos] = tmpdis;
    return tmpdis;
}

int main()
{

    cin >> n;
    int mid;
    for (int i = 0; i < n; i++)
    {
        cin >> mid;
        dis[mid] = 1;
    }
    if (!dis[1])
    {
        cout << 0;
    }
    else
    {
        cout << dfs(1, 1);
    }
}
