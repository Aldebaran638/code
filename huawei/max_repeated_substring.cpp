#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;
string ans = "";
int ansnum;
int main()
{
    cin >> s;

    for (int i = 1; i <= s.size() / 2 + 1; i++)
    {
        for (int j = 0; j < s.size() - i + 1; j++)
        {
            int cnt = 1;
            int k = j;
            while ((k + i + i - 1 < s.size()) && (s.substr(k, i) == s.substr(k + i, i)))
            {
                cnt++;
                k += i;
            }
            if (cnt == ansnum)
            {
                if (ans.size() < i)
                {
                    ans = s.substr(j, i);
                }
                else if (ans.size() == i)
                {
                    if (ans > s.substr(j, i))
                    {
                        ans = s.substr(j, i);
                    }
                }
            }
            else if (cnt > ansnum)
            {
                cnt > ansnum;
                ans = s.substr(j, i);
            }
        }
    }
    cout << ans;
}
