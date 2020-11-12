#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull tmp[3];
//C(n,3)-n*C((n-1)/2,2)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull A, B, C, n, ans;
    cin >> A >> B >> C >> n;
    if (n <= 2)
    {
        cout << "0\n";
        return 0;
    }
    tmp[0] = n;
    tmp[1] = n - 1;
    tmp[2] = n - 2;
    for (int j = 2; j <= 3; j++)
        for (int i = 0; i < 3; i++)
            if (tmp[i] % j == 0)
            {
                tmp[i] /= j;
                break;
            }
    ans = tmp[0] * tmp[1] * tmp[2];
    if ((n - 1) / 2 >= 2)
    {
        tmp[0] = (n - 1) / 2;
        tmp[1] = tmp[0] - 1;
        tmp[2] = n;
        for (int i = 0; i <= 1; i++)
            if (tmp[i] % 2 == 0)
            {
                tmp[i] /= 2;
                break;
            }
        ans -= tmp[0] * tmp[1] * tmp[2];
    }
    tmp[0]=A,tmp[1]=B,tmp[2]=C;
    set<ull> st;
    for (int i = 0; i < 3; i++)
        st.insert(tmp[i]);
    if (st.size() == 3)
        ans *= 6;
    else if (st.size() == 2)
        ans *= 3;
    cout << ans << '\n';
    return 0;
}
