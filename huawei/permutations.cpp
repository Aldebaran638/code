#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n;
int numa[N];
int usedcnt=0;
int used[N];
void dfs(vector<int> num)
{
    if (num.size() == n)
    {
        for (int i = 0; i < num.size(); i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            num.push_back(numa[i]);
            dfs(num);
            num.pop_back();
            used[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numa[i];
    }
    vector<int> num;
    dfs(num);
    return 0;
}