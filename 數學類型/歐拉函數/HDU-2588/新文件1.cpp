#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll phi(ll x){
    if(x==1)return 1;
    ll ans=x;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ans=ans*(i-1)/i;
            while(x%i==0)x/=i;
        }
    }
    if(x>1)
        ans=ans*(x-1)/x;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, n, m, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = 0;
        for (ll i = 1; i * i <= n; i++)//find n's factors(not prime factors)
        {
            if (n % i)
                continue;
            if (i >= m)
                ans+=phi(n/i);
            if((n/i)>=m&&i*i!=n)
                ans+=phi(n/(n/i));
        }
        cout<<ans<<'\n';
    }

    return 0;
}
//gcd(x,n)=a  a>=m;
//gcd(x/a,n/a)=1;
//The sum of number that "> sqrt(n)" && is a "prime factor" at most one
