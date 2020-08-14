#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 4000001
ll phi[MAXN];
ll f[MAXN];
ll s[MAXN];
void init()
{
    for (int i = 0; i < MAXN; i++)
        phi[i] = i;
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = phi[i] * (i - 1) / i;
            for (int j = i + i; j < MAXN; j += i)
            {
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    init();
    memset(f, 0, sizeof(f));
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = i * 2; j < MAXN; j += i)
        {
            f[j] += phi[j / i] * i;
        }
    }
    s[2] = f[2];
    for (int i = 3; i < MAXN; i++)
        s[i] = s[i - 1] + f[i];
    while (cin >> n && n)
        cout << s[n] << '\n';
    return 0;
}
/*
q: gcd(1,2)+gcd(1,3)+gcd(1,4)+...+gcd(1,n)     +    gcd(2,3)+gcd(2,4)+...+gcd(2,n)         +....+gcd(n-1,n) = s(n)
f(n)=gcd(1,n)+gcd(2,n)+gcd(3,n)+...+gcd(n-1,n);
S(n)=f(2)+f(3)+..+f(n);
S(n)=S(n-1)+f(n);
g(n,i) the total number that satisfy " gcd(x,n)=i " 1<=x<n
f(n)=sum{i * g(n,i)}
gcd(x/i,n/i)=1 => Euler;
*/
