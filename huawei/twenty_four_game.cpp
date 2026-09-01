#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> num;

int cul(vector<int> mid, int op1, int op2, int op3)
{
    vector<int> op;
    int ans = 0;
    op.push_back(op1), op.push_back(op2), op.push_back(op3);
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] >= 2)
        {
            if (op[i] == 2)
            {
                mid[i] = mid[i] * mid[i + 1];
            }
            else
            {
                mid[i] = mid[i] / mid[i + 1];
            }
            mid.erase(mid.begin() + 1 + i);
            op.erase(op.begin() + i);
        }
    }
    double ans = mid[0];

    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == 0)
            ans += mid[i + 1];
        else
            ans -= mid[i + 1];
    }

    return ans;
}

int main()
{
    int mid;
    for (int i = 0; i < 4; i++)
    {
        cin >> mid;
        num.push_back(mid);
    }
    sort(num.begin(), num.end());
    do
    {
        for (int op1 = 0; op1 < 4; op1++)
        {
            for (int op2 = 0; op2 < 4; op2++)
            {
                for (int op3 = 0; op3 < 4; op3++)
                {
                    if (cul(num, op1, op2, op3) == 24)
                    {
                        cout << "yes";
                        return 0;
                    }
                }
            }
        }
    } while (next_permutation(num.begin(), num.end()));
    cout << "no";
}
