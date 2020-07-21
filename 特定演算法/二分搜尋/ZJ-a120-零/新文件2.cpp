#include <bits/stdc++.h>
using namespace std;
#define N 500000
pair<long long, long long> DP[N + 1];
bool check(long long mid, long long n)
{
    long long ans = 0;
    long long tmp = 5;
    for (int i = 0; i < 25; i++)
    {
        if (mid / tmp == 0)
            break;
        ans += mid / tmp;
        tmp *= 5;
    }

    return ans >= n;
}
/*
void build()
{

    DP[0]={1,0};
    DP[1]={1,0};
    long long tmp=1;
    long long cnt;
    for(long long i=2;i<N+1;i++)
    {
        //cout<<i<<endl;
        tmp=10;
        cnt=0;
        DP[i].first=DP[i-1].first*i;
        while(DP[i].first%tmp==0)
        {
            cnt++;
            tmp*=10;
        }
        DP[i].second=DP[i-1].second+cnt;
        DP[i].first%=tmp*1000000;
        DP[i].first/=tmp/10;
    }
}
*/
int main()
{
    long long t, n,tmp,ans;
    long long l, r, mid;
    //build();
    /*
    cout<<DP[3].first<<" "<<DP[3].second<<endl;
    cout<<DP[5].first<<" "<<DP[5].second<<endl;
    cout<<DP[7].first<<" "<<DP[7].second<<endl;
    cout<<DP[10].first<<" "<<DP[10].second<<endl;
    cout<<DP[N].first<<" "<<DP[N].second<<endl;
    for(int i=2;i<630;i++)
    {
        cout<<"DP["<<i<<"] : "<<DP[i].first<<" "<<DP[i].second<<endl;
    }
    */
    while (cin >> t)
    {
        while (t--)
        {
            cin >> n;
            l = 5;
            r = 1e13;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (l == r)
                    break;
                if (check(mid, n))
                    r = mid;
                else
                    l = mid + 1;
            }
            tmp=5;
            ans=0;
            for (int i = 0; i < 25; i++)
            {
                if (mid / tmp == 0)
                    break;
                ans += mid / tmp;
                tmp *= 5;
            }
            if(ans!=n)
                mid = -1;
            cout << mid << '\n';
        }
    }

    return 0;
}
