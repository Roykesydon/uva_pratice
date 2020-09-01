#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    long long ans = 0;
    int sumw = 0, curw = 0;
    for (int i = 0; i < str.size(); i++)
        if (str[i] == 'v' && i != 0 && str[i - 1] == 'v')
            sumw++;
    for (int i = 0; i <= str.size(); i++)
        if (str[i] == 'o')
            ans += (long long)curw * (long long)(sumw - curw);
        else if (i != 0 && str[i - 1] == 'v')
            curw++;
    cout << ans << '\n';
    return 0;
}
