
#include <bits/stdc++.h>
using namespace std;

// 链表用while就是快啊

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;

    while (head != nullptr)
    {
        ListNode *next = head->next;
        head->next = pre;
        pre = head;
        cout << head->next << endl;
        head = next;
    }
    cout << pre << endl;
    return pre;
}

void print(ListNode *head)
{
    if (head != nullptr)
    {
        cout << head->val << " -> ";
        print(head->next);
    }
    else
    {
        cout << "nullptr";
        return;
    }
}
int n;
ListNode *l;
ListNode *pre;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int mid;
        cin >> mid;
        ListNode *tmp = new ListNode(mid);
        tmp->val = mid;
        if (i > 0)
        {
            pre->next = tmp;
        }
        else if (i == 0)
        {
            l = tmp;
        }
        pre = tmp;
    }
    print(l);
    cout << endl;
    l = reverseList(l);
    print(l);
    cout << endl;
    return 0;
}