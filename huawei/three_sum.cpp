#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int tmp = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int mid;
        cin >> mid;
        num.push_back(mid);
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        int left = i + 1, right = n - 1;
        while (right > left)
        {
            if (num[right] + num[left] + num[i] == 0)
            {
                cout << num[right] << " " << num[left] << " " << num[i] << endl;
                left++;
                while (left + 1 < n && num[left] == num[left - 1])
                    left++;
            }
            else if (num[right] + num[left] + num[i] < 0)
            {
                left++;
                while (left + 1 < n && num[left] == num[left - 1])
                    left++;
            }
            else
            {
                right--;
                while (right - 1 >= 0 && num[right] == num[right + 1])
                    right--;
            }
        }
    }
    return 0;
}