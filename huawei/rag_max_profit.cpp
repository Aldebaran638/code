#include <bits/stdc++.h>
using namespace std;

int n, d;

vector<vector<int>> num;

vector<unordered_map<int, int>> state;

double dfs(int t, int pd)
{
    if (t >= n)
    {
        return 0;
    }
    if (state[t].find(pd) != state[t].end())
    {
        return state[t][pd];
    }
    double maxearn = 0;
    // find
    maxearn = max(((pd >= 0 ? num[t][1] : 0) + dfs(t + 1, max(pd - 1,0))), maxearn);
    // insert
    maxearn = max(-num[t][0] + dfs(t + 1, max(d-1,0)), maxearn);
    // find+insert;
    maxearn = max(num[t][1] - num[t][0] + dfs(t + 1, max(d-1,0)), maxearn);
    state[t][pd] = maxearn;
    return maxearn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        num.push_back(vector<int>());
        double a;
        cin >> a;
        num[i].push_back(a);
        state.push_back(unordered_map<int, int>());
    }
    for (int i = 0; i < n; i++)
    {
        double a;
        cin >> a;
        num[i].push_back(a);
    }
    cout << (int)dfs(0, 0);
    return 0;
}