#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    ll ans = 0;
    cin >> str;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if ((str[i] - '0') % 4 == 0)
                ans++;
        }
        else
        {
            if ((str[i] - '0') % 4 == 0)
                ans++;
            if (((str[i - 1] - '0') * 10 + (str[i] - '0')) % 4 == 0)
                ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}
