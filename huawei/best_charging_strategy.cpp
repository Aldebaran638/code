#include <bits/stdc++.h>
using namespace std;

int n, h;
vector<int> num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        int mid;
        cin >> mid;
        num.push_back(mid);
    }
    int left = 0, right = h - 1;
    int sum = 0;
    for (int i = 0; i <= right; i++)
    {
        sum += num[i];
    }
    int minsum = sum, ans = 0;
    for (right = right + 1, left = left + 1; right < n; left++, right++)
    {
        sum -= num[left - 1], sum += num[right];
        if (sum < minsum)
        {
            minsum = sum;
            ans = left;
        }
    }
    cout << ans;
    return 0;
}