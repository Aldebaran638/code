#include <bits/stdc++.h>
using namespace std;
//枚举,但是思路绕一点.
const int N = 1000;
int n, k;
vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int mid;
        cin >> mid;
        a.push_back(mid);
    }
    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++)
    {
        int newmax = max(a[i] + k, a[n - 1] - k);
        int newmin = min(a[0] + k, a[i + 1] - k);
        ans = min(newmax - newmin, ans);
    }
    cout << ans;
    return 0;
}