#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int i = 0, j = s.size() - 1;
    bool flag = 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            flag = 0;
            break;
        }
        i++, j--;
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}