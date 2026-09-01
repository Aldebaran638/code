#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.size() == 0 || (st.top() == '[' && s[i] != ']') || (st.top() == '(' && s[i] != ')') || (st.top() == '{' && s[i] != '}'))
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}