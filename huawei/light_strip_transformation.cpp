#include <bits/stdc++.h>
using namespace std;
// 模拟 + 状态记忆 / 判环
string s;
int t;
unordered_map<string, int> seen;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string news = s;
        for (int j = 0; j < s.size(); j++)
        {
            if (j == 0 || j == s.size() - 1)
            {
                news[j] = 'R';
            }
            else
            {
                if (s[j - 1] != s[j + 1])
                {
                    news[j] = 'R';
                }
                else
                {
                    news[j] = 'G';
                }
            }
        }
        s = news;
        if (seen.count(s))
        {
            int cyclet = i - seen[s];
            i += ((t - i - 1) / cyclet) * cyclet;
        }
        else
        {
            seen[s] = i;
        }
    }
    cout << s;
    return 0;
}