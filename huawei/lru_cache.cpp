#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *pre;
    Node(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}
};

struct LRUCache
{
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            int ans = mp[key]->val;
            Node *tailpre = tail->pre;
            tail->pre->next = nullptr;
            tail->pre = nullptr;
            tail->next = head;
            head->pre = tail;
            head = tail;
            tail = tailpre;
            return ans;
        }
    }
    void put(int key, int value)
    {
        if (capacity == mp.size())
        {
            removeNode(tail->key);
        }
        else if (mp.size() == 0)
        {
            mp[key] = new Node(key, value);
            head = tail = mp[key];
        }
        else
        {
            mp[key] = new Node(key, value);
            mp[key]->next = head;
            head->pre = mp[key];
            head = mp[key];
        }
    }
    void printList()
    {
        Node *mid = head;
        while (mid != nullptr)
        {
            cout << mid->val << " ";
        }
        cout << endl;
    }
    void removeNode(int key)
    {
        Node *target = mp[key];
        if (mp[key] == nullptr)
        {
            cout << "remove false" << endl;
        }
        if (mp[key]->pre)
            mp[key]->pre->next = mp[key]->next;
        if (mp[key]->next)
            mp[key]->next->pre = mp[key]->pre;
        delete mp[key];
        mp.erase(key);
    }
    void moveToHead(int key)
    {
        Node *target = mp[key];
        if (mp[key] == nullptr)
        {
            cout << "moveToHear false" << endl;
        }
        if (mp[key]->pre)
            mp[key]->pre->next = mp[key]->next;
        if (mp[key]->next)
            mp[key]->next->pre = mp[key]->pre;
        if (tail->key == mp[key]->key)
            tail = mp[key]->pre;
        mp[key]->next = head;
        head->pre = mp[key];
        mp[key]->pre = nullptr;
        head = mp[key];
    }
    void addNodeToTail(int key, int value)
    {
        Node *newnode = new Node(key, value);
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}