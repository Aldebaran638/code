#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<string>> num;
vector<set<string>> ans;
int M = 1e5 + 20;

bool issml(set<string> a, set<string> b)
{
    int sizea = a.size();
    for (auto it = b.begin(); it != b.end(); it++)
    {
        a.insert(*it);
    }
    if (a.size() < sizea + b.size())
    {
        return true;
    }
    return false;
}

vector<int> father;
int findfather(int a)
{
    if (a == father[a])
    {
        return a;
    }
    return father[a] = findfather(father[a]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    num = vector<set<string>>(n);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        stringstream ss(s);
        string x;
        while (ss >> x)
        {
            num[i].insert(x);
        }
        father.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (issml(num[i], num[j]))
            {
                int fai = findfather(i), faj = findfather(j);
                if (i != j)
                    father[faj] = fai;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int fathernum = father[findfather(i)];
        if (fathernum != i)
        {
            for (auto it = num[i].begin(); it != num[i].end(); it++)
            {
                num[fathernum].insert(*it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (father[i] == i)
        {
            ans.push_back(num[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it = ans[i].begin(); it != ans[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}