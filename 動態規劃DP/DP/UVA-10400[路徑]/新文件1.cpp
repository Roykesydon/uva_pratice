#include <bits/stdc++.h>
using namespace std;
int f[101][64000 + 1];
bool dp[101][64000 + 1];
int n;
vector<int> arr;
vector<char> ch_vec;
void dfs(int x)//actually this is not dfs
{
    for (int i = n - 1; i >= 1; i--)
    {
        //cerr<<"x-32000= "<<x-32000<<'\n';
        if (f[i][x] == 1)
        {
            ch_vec.push_back('+');
            x-=32000;
            x -= arr[i];
            x+=32000;
        }
        else if (f[i][x] == 2)
        {
            ch_vec.push_back('-');
            x-=32000;
            x += arr[i];
            x+=32000;
        }
        else if (f[i][x] == 3)
        {
            ch_vec.push_back('*');
            x-=32000;
            x /= arr[i];
            x+=32000;
        }
        else if (f[i][x] == 4)
        {
            ch_vec.push_back('/');
            x-=32000;
            x *= arr[i];
            x+=32000;
        }
    }
}
bool safe(int x)
{
    if (x >= -32000 && x <= 32000)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,  tar;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> tar;
        memset(dp, 0, sizeof(dp));
        memset(f, 0, sizeof(f));
        dp[0][arr[0] + 32000] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 64000; j++)
            {
                if (dp[i - 1][j])
                {
                    if (safe(j - 32000 + arr[i]))
                    {
                        dp[i][arr[i] + j] = 1;
                        f[i][arr[i] + j] = 1;
                    }
                    if (safe(j - 32000 - arr[i]))
                    {
                        dp[i][j - arr[i]] = 1;
                        f[i][j - arr[i]] = 2;
                    }
                    if (safe((j - 32000) * arr[i]))
                    {
                        dp[i][(j - 32000) * arr[i] + 32000] = 1;
                        f[i][(j - 32000) * arr[i] + 32000] = 3;
                    }
                    if (j - 32000 >= arr[i] && ((j - 32000)+arr[i]) % arr[i] == 0)
                    {
                        dp[i][(j - 32000) / arr[i] + 32000] = 1;
                        f[i][(j - 32000) / arr[i] + 32000] = 4;
                    }
                }
            }
        }
        ch_vec.clear();
        if (dp[n - 1][tar + 32000])
        {
            dfs(tar + 32000);
            for (int i = 0; i < n; i++)
            {
                if(i!=0)
                    cout << ch_vec[n - 1 - i];
                cout << arr[i];
            }
            cout<<"=";
            cout<<tar<<'\n';
        }
        else
            cout << "NO EXPRESSION\n";
    }

    return 0;
}
/*
3
3 5 7 4 3
2 1 1 2000
5 12 2 5 1 2 4
*/
