#include <bits/stdc++.h>
using namespace std;

// 矩阵乘法
// 矩阵转置
// 变量类型可能导致的错误(要用double就全double)
// 有时候core error (illegal introduction)可能是有个函数忘记return 了
// 这题有更加简单的技巧.Y=V

int n, m, h;

vector<vector<double>> multi(vector<vector<double>> a, vector<vector<double>> b)
{
    if (a.size() == 0 || b.size() == 0 || (a[0].size() != b.size()))
    {
        cout << "error" << endl;
        return vector<vector<double>>();
    }
    vector<vector<double>> result;
    for (int i = 0; i < a.size(); i++)
    {

        result.push_back(vector<double>());
        for (int j = 0; j < b[0].size(); j++)
        {
            double sum = 0;
            for (int k = 0; k < b.size(); k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i].push_back(sum);
        }
    }
    return result;
}

vector<vector<double>> divide(vector<vector<double>> a, double divider)
{
    vector<vector<double>> result;
    for (int i = 0; i < a.size(); i++)
    {
        result.push_back(vector<double>());
        for (int j = 0; j < a[i].size(); j++)
        {
            result[i].push_back(a[i][j] / divider);
        }
    }
    return result;
}

vector<vector<double>> trans(vector<vector<double>> a)
{
    if (a.size() == 0)
    {
        cout << "error" << endl;
        return a;
    }
    vector<vector<double>> ans;
    for (int j = 0; j < a[0].size(); j++)
    {
        ans.push_back(vector<double>());
        for (int i = 0; i < a.size(); i++)
        {
            ans[j].push_back(a[i][j]);
        }
    }
    return ans;
}

void print(vector<vector<double>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int simplify(double a)
{
    if (a > ((int)a + (int)a + 1) / 2.0)
    {
        return (int)a + 1;
    }
    else
    {
        return (int)a;
    }
}

vector<vector<double>> softmax_(vector<vector<double>> a)
{
    vector<vector<double>> result;
    for (int i = 0; i < a.size(); i++)
    {
        result.push_back(vector<double>());
        double sum = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            sum += a[i][j];
        }
        for (int j = 0; j < a[i].size(); j++)
        {
            result[i].push_back(a[i][j] / sum);
        }
    }
    // cout<<"softmax"<<endl;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;
    vector<vector<double>> x;
    vector<vector<double>> W1;
    vector<vector<double>> W2;
    vector<vector<double>> W3;
    for (int i = 0; i < n; i++)
    {
        x.push_back(vector<double>());
        for (int j = 0; j < m; j++)
        {
            x[i].push_back(1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        W1.push_back(vector<double>());
        for (int j = 0; j < h; j++)
        {
            if (i <= j)
            {
                W1[i].push_back(1);
            }
            else
            {
                W1[i].push_back(0);
            }
        }
    }
    W2 = W3 = W1;
    vector<vector<double>> Q = multi(x, W1);
    vector<vector<double>> K = multi(x, W2);
    vector<vector<double>> V = multi(x, W3);
    vector<vector<double>> qkt = multi(Q, trans(K));
    vector<vector<double>> bqkt = divide(qkt, sqrt(h));
    vector<vector<double>> softmax_result = softmax_(bqkt);
    vector<vector<double>> y = multi(softmax_(bqkt), V);
    int ans = 0;
    for (int i = 0; i < y.size(); i++)
    {
        for (int j = 0; j < y[i].size(); j++)
        {
            ans += llround(y[i][j]);
        }
    }
    cout << ans;
    return 0;
}