#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void change(string as, vector<int> &av)
{
    int num = 0;
    for (int i = 4; i < as.size(); i++)
    {
        if (as[i] <= '9' && as[i] >= '0')
        {
            num *= 10;
            num += as[i] - '0';
        }
        else if (as[i] == '.')
        {
            av.push_back(num);
            num = 0;
        }
    }
    av.push_back(num);
}

int compare(string as, string bs)
{
    if (as.size() <= 4 || bs.size() <= 4)
    {
        return -2;
    }
    vector<int> av, bv;
    change(as, av);
    change(bs, bv);
    for (int i = 0; i < max(av.size(), bv.size()); i++)
    {
        int anum = 0, bnum = 0;
        anum = (i >= av.size() ? 0 : av[i]);
        bnum = (i >= bv.size() ? 0 : bv[i]);
        cout << "anum=" << anum << " " << "bnum=" << bnum << endl;
        if (anum != bnum)
        {
            return anum > bnum ? 1 : -1;
        }
    }
    return 0;
}

int main()
{
    cout << compare("ver 1.2", "ver 1.3") << endl;
    cout << compare("ver 1.5", "ver 1.0") << endl;
    cout << compare("ver 7.2.0.0", "ver 7.2") << endl;
    cout << compare("ver 1.2324234", "ver 1.3") << endl;
    cout << compare("ver 1.0213", "ver 1.3") << endl;
    cout << compare("ver 1.2.0.0", "ver 1.2") << endl;

    cout << "hello" << endl;
}