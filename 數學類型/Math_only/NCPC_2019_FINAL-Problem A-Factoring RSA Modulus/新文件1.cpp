#include <bits/stdc++.h>
using namespace std;
long long a, b;
bool check(long long n, long long x)
{
    int tmp;
    for (long long i = 1; i < x; i++)
    {
        if ((n - x * x + i * x) % (x - i) != 0)
            continue;
        tmp = (n - x * x + i * x) / (x - i);
        if ((x - i) * (x + tmp) == n&&tmp-i-1>=0&&tmp-i-1<x&&x-tmp*i>=0&&x-tmp*i<x)
        {
            a = i;
            b = tmp;
            return true;
        }
    }
    return false;
}
int main()
{
    int m;
    bool flag;
    long long n;
    long long x;
    cin >> m;
    while (m--)
    {
        cin >> n;
        flag = 0;
        x = (int)sqrt((double)n);
        if (x * x <= n)
        {
            if (check(n, x))
            {
                cout << n << " = " << x-a << " * " << x+b << '\n';
                continue;
            }
        }
        x--;
        if (x * x <= n)
        {
            if (check(n, x))
            {
                cout << n << " = " << x-a << " * " << x+b << '\n';
                continue;
            }
        }
        x += 2;
        if (x * x <= n)
        {
            if (check(n, x))
            {
                cout << n << " = " << x-a << " * " << x+b << '\n';
                continue;
            }
        }
        cout << n << " = " << 1 << " * " << n << '\n';
    }

    return 0;
}
