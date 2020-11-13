#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tmp;
vector<vector<ll>> operator*(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> vec(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < b.size(); k++)
            {
                vec[i][j] += a[i][k] * b[k][j] % tmp;
                vec[i][j] %= tmp;
            }
        }
    }
    return vec;
}

vector<vector<ll>> arr;
vector<vector<ll>> bas;
vector<vector<ll>> ans;
int main()
{
    ll n, m, x;
    while (cin >> n >> m)
    {
        arr.resize(2);
        for (int i = 0; i < 2; i++)
            arr[i].resize(2);
        bas.resize(2);
        for (int i = 0; i < 2; i++)
            bas[i].resize(1);
        ans.resize(2);
        for (int i = 0; i < 2; i++)
            ans[i].resize(1);
        arr = {{1, 1}, //f(n-1)f(n-2) + f(n-1)
               {1, 0}};

        bas = {{1}, {0}}; //f(n-1)  f(n-2)
                          //cout << (arr * (arr * (arr * bas)))[0][0] << " " << (arr * (arr * (arr * bas)))[1][0] << endl;

        tmp = 1;
        x = 2;
        while (m)
        {
            if (m & 1)
                tmp *= x;
            x *= x;
            m >>= 1;
        }

        if (n == 0)
            ans = {{0}, {-1}};
        else if (n == 1)
            ans = {{1}, {-1}};
        else
        {
            ans = bas;
            n -= 1;
            while (n)
            {
                if (n & 1)
                    ans = arr * ans;
                n >>= 1;
                arr = arr * arr;
            }
            //cout << ans[0][0] << endl;
        }

        cout << ans[0][0] << '\n';

        ans.clear();
        bas.clear();
        arr.clear();
    }

    return 0;
}
