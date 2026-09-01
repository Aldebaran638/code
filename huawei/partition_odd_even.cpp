#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int mid;
        cin >> mid;
        num.push_back(mid);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (num[i] % 2 != 0)
        {
            ans.push_back(num[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i] % 2 == 0)
        {
            ans.push_back(num[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}