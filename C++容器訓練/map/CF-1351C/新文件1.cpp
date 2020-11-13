#include <bits/stdc++.h>
using namespace std;
map<pair<pair<int, int>,char>, int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int x = 0, y = 0, ans;
    string str;
    cin >> t;
    getline(cin, str);
    while (t--)
    {
        getline(cin, str);
        mp.clear();
        ans = 0;
        x = 0, y = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'N')
            {
                if (mp.count({{x, y + 1},'N'}))
                    ans++;
                else
                    ans += 5;
                mp[{{x, y},'S'}]++;
                mp[{{x, y+1},'N'}]++;
                y += 1;
            }
            if (str[i] == 'S')
            {
                if (mp.count({{x, y - 1},'S'}))
                    ans++;
                else
                    ans += 5;
                mp[{{x, y},'N'}]++;
                mp[{{x, y - 1},'S'}]++;
                y -= 1;
            }
            if (str[i] == 'E')
            {
                if (mp.count({{x+1, y },'E'}))
                    ans++;
                else
                    ans += 5;
                mp[{{x, y},'W'}]++;
                mp[{{x+1, y },'E'}]++;
                x += 1;
            }
            if (str[i] == 'W')
            {
                if (mp.count({{x-1, y},'W'}))
                    ans++;
                else
                    ans += 5;
                mp[{{x, y},'E'}]++;
                mp[{{x-1, y},'W'}]++;
                x -= 1;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
