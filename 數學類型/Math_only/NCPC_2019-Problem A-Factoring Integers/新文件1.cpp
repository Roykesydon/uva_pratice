#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int p)
{
    while (1)
    {
        if (n < p)
            swap(n, p);
        //cout<<"p= "<<p<<"n= "<<n<<endl;
        if (n % p == 0)
            return p;
        n %= p;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m, i, x;
    bool flag;
    long long n, p;
    cin >> m;
    while (m--)
    {
        cin >> n;
        flag = 0;
        p = 4;
        //cout<<gcd(n,p)<<endl;
        i = 1;
        //p = 0;

        while (1)
        {
            if (i & 1 == 1)
            {
                if (i == 1)
                    p = 3;
                else
                    p = (3 + 5 * p) % n;
            }
            else
            {
                p = n - p;
            }
            i++;
            if (p != 0)
            {
                x = gcd(n, p);
                if (x != 1&&x!=n)
                {
                    flag = 1;
                    break;
                }
                if (i >= 1000000)
                    break;
            }
        }
        if (flag)
            cout << n << " = " << x << " * " << n / x<<'\n';
        else
            cout << n << " = " << 1 << " * " << n<<'\n';
    }

    return 0;
}
