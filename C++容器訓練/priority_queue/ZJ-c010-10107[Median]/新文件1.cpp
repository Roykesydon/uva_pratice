#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
priority_queue<int> pqb;
priority_queue<int, vector<int>, cmp> pqs;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, i = 1;
    while (cin >> x)
    {
        if (i == 1)
        {
            pqs.push(x);
            cout << pqs.top() << '\n';
        }
        else if (i == 2)
        {
            if (x > pqs.top())
            {
                auto u = pqs.top();
                pqs.pop();
                pqb.push(u);
                pqs.push(x);
                cout << (pqb.top() + pqs.top()) / 2 << '\n';
            }
            else
            {
                pqb.push(x);
                cout << (pqb.top() + pqs.top()) / 2 << '\n';
            }
        }
        else if (i & 1)
        {
            if (x > pqb.top())
            {
                pqs.push(x);
                cout << pqs.top() << '\n';
            }
            else
            {
                auto u = pqb.top();
                pqb.pop();
                pqs.push(u);
                pqb.push(x);
                cout << pqs.top() << '\n';
            }
        }
        else
        {
            if (x < pqs.top())
            {
                pqb.push(x);
                cout << (pqs.top() + pqb.top()) / 2 << '\n';
            }
            else
            {
                auto u = pqs.top();
                pqs.pop();
                pqs.push(x);
                pqb.push(u);
                cout << (pqs.top() + pqb.top()) / 2 << '\n';
            }
        }

        i++;
    }

    return 0;
}
/*
1 3 4 60 70 50 2

1  
3                 1
4 3               1
60 4            3 1
70 60 4         3 1
70 60 50      4 3 1
70 60 50 4    3 2 1
70 60 50 4  4 3 2 1 

1
3                1
3 3              1
3 3            1 1
3 3 3          1 1
3 3 3        3 1 1

*/
