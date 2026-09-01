#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);
    set<int> st;
    int maxlen = 0;
    for (int i = 0, j = 0; j < s.size();)
    {
        while (st.find(s[j]) != st.end())
        {
            maxlen = max(maxlen, (int)st.size());
            st.erase(s[i]);
            i++;
        }
        st.insert(s[j]);
        j++;
    }
    maxlen = max(maxlen, (int)st.size());
    cout << maxlen;
    return 0;
}