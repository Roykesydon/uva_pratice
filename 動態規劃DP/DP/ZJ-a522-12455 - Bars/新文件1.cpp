#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> dp;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, p;
    while (cin >> t)
    {
        while (t--)
        {
            cin >> n;
            cin >> p;
            arr.resize(p + 1);
            dp.resize(p + 1);
            dp[0].resize(1000 + 1, 0);
            dp[0][0] = 1;
            for (int i = 1; i <= p; i++)
                dp[i].resize(1000 + 1);
            for (int i = 1; i <= p; i++)
                cin >> arr[i];
            sort(arr.begin()+1,arr.end());
            for (int i = 1; i <= p; i++)
            {
                for(int j=0;j<=1000;j++)
                {
                    //cout<<i<<","<<j<<'\n';
                    if(arr[i]>j)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        if(dp[i-1][j-arr[i]]==1)
                        {
                            dp[i][j]=1;
                            //cout<<j<<" is ok\n";
                        }

                        else
                            dp[i][j]=0;
                    }
                }
            }
            if(dp[p][n]==1)cout<<"YES\n";
            else cout<<"NO\n";
            arr.clear();
            dp.clear();
        }
    }

    return 0;
}
