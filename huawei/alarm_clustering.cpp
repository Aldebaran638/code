#include <bits/stdc++.h>
using namespace std;

/*
本题错误点 / 复盘：

1. EOF 输入不熟
   本题没有给告警数量 n，需要一直读取到 EOF。
   推荐：
       string line;
       while (getline(cin, line)) {
           stringstream ss(line);
           ...
       }
   每行第一个数是 id，后面的所有数都是 embedding。

2. 并查集合并写得不标准
   我原来写的是：
       father[j] = findfather(i);

   问题：
   j 可能不是一个集合的根。
   如果 j 已经属于某个集合，直接修改 father[j] 有可能只修改一个子节点，
   而不是把两个完整集合合并。

   正确原则：
       “并查集合并永远操作根节点，而不是普通子节点。”

   正确写法：
       int fi = findfather(i);
       int fj = findfather(j);
       if (fi != fj)
           father[fj] = fi;

3. findfather 虽然能正确找到根，但原写法没有路径压缩
   原来：
       return a = findfather(father[a]);

   这里只修改了局部变量 a，
   father 数组本身没有改变。

   正确路径压缩：
       return father[a] = findfather(father[a]);

   例如：
       4 -> 3 -> 2 -> 0
   查询 findfather(4) 后应压缩为：
       4 -> 0
       3 -> 0
       2 -> 0

4. 最后统计集合大小时，也应该统计“真正的根”
   不应该直接：
       mp[father[i]]++;

   因为 father[i] 可能只是中间父节点。

   应该：
       int root = findfather(i);
       mp[root]++;

5. 本题核心建模
   “余弦相似度 >= 0.95”可以看成两条告警之间连了一条无向边。

   题目的弱传递：
       A ~ B
       B ~ C
       => A、B、C 属于同一个类别

   本质就是：
       求无向图的连通分量

   所以：
       两两计算余弦相似度
       -> 相似则 union
       -> 统计每个根节点对应的集合大小
       -> 输出最大连通分量

6. 余弦相似度公式
       cos(A,B) = A·B / (|A| * |B|)

   其中：
       A·B = Σ Ai*Bi
       |A| = sqrt(Σ Ai^2)

7. 工程细节
   culcos() 传入 vector 时最好使用 const 引用：
       double culcos(const Warning& a, const Warning& b)

   否则每次比较都会复制 embedding，虽然本题 n<=1000 可能也能过，
   但没有必要。

总结：
    本题算法不难，真正需要记住的是：

    “相似关系具有传递合并性质”
        -> 连通分量
        -> 并查集

    并查集两条铁律：
        1. union 操作根节点
        2. find 时路径压缩
*/

double culcos(pair<int, vector<double>> warn1, pair<int, vector<double>> warn2)
{
    double ab = 0;
    double a = 0, b = 0;
    for (int i = 0; i < warn1.second.size(); i++)
    {
        ab += warn1.second[i] * warn2.second[i];
        a += warn1.second[i] * warn1.second[i];
        b += warn2.second[i] * warn2.second[i];
    }
    a = sqrt(a), b = sqrt(b);
    return ab / (a * b);
}

vector<int> father;

int findfather(int a)
{
    if (father[a] == a)
    {
        return a;
    }
    else
    {
        return father[a] = findfather(father[a]);
    }
}

vector<pair<int, vector<double>>> warn;
int m = -1;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        int id;
        ss >> id;
        vector<double> emb;
        double x;
        while (ss >> x)
        {
            emb.push_back(x);
        }
        if (m == -1)
            m = emb.size();
        else if (m != emb.size())
        {
            cout << 0 << endl;
            return 0;
        }
        n++;
        warn.push_back(pair<int, vector<double>>(id, emb));
    }
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        father.push_back(i);
    }
    // cout<<n<<" "<<m<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<warn[i].first<<" ";
    //     for(int j=0;j<m;j++){
    //         cout<<warn[i].second[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<culcos(pair<int, vector<double>>(1,{1,2}),pair<int, vector<double>>(1,{2,2}))<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (culcos(warn[i], warn[j]) >= 0.95 - 1e-6)
            {
                father[j] = findfather(i);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << father[i] << " ";
    // }
    // cout << endl;
    int maxnum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[father[i]] += 1;
        if (mp[father[i]] > maxnum)
        {
            maxnum = mp[father[i]];
        }
    }
    cout << maxnum << endl;
    return 0;
}