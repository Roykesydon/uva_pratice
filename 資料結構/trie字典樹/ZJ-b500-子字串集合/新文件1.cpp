#include <bits/stdc++.h>
using namespace std;
int sum = 1;
bool flag;
class node
{
public:
    int cnt;
    int id;

    node *nxt[26];
    node()
    {
        cnt = 0;
        memset(nxt, 0, sizeof(nxt));
    }
};
void DFS(node *cur)
{
    for (int i = 0; i < 26; i++)
    {
        if (cur->nxt[i] != NULL)
            DFS(cur->nxt[i]);
        delete cur->nxt[i];
        cur->nxt[i] = NULL;
    }
}
void find(node *cur, string str)
{
    if (cur->cnt == 1)
        cout << str << '\n';
    for (int i = 0; i < 26; i++)
    {
        if (cur->nxt[i] != NULL)
        {
            find(cur->nxt[i], str + (char)(i + 'A'));
        }
    }
}
int query(string str, node *cur)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (cur->nxt[str[i] - 'A'] == NULL)
        {
            cur->nxt[str[i] - 'A'] = new node;
        }
        cur = cur->nxt[str[i] - 'A'];
    }

    if (cur->cnt == 0)
    {
        cur->cnt = 1;
        cur->id = sum++;
        flag = true;
        return cur->id;
    }
    flag = false;
    return cur->id;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, id;
    string str;
    node *root = new node();

    sum = 1;
    cin >> str;
    for (int len = 1; len <= str.size(); len++)
    {
        for (int i = 0; i + len <= str.size(); i++)
        {
            //cout << str.substr(i, len) << endl;
            query(str.substr(i, len), root);
        }
    }
    find(root, "");
    DFS(root);

    return 0;
}
