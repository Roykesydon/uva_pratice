#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
#define ll long long
vector<ll> arr;
vector<ll> id;
vector<ll> bit;
void modify(ll index, ll value)
{
    while (index <= bit.size())
    {
        bit[index] += value;
        index += lowbit(index);
    }
}
ll query(ll index)
{
    ll ans = 0;
    while (index)
    {
        ans += bit[index];
        index -= lowbit(index);
    }
    return ans;
}
int main()
{
    ll n, x;
    ll ans;
    while (cin >> n && n)
    {
        arr.resize(n);
        bit.resize(n + 1, 0);
        id.resize(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        id = arr;
        sort(id.begin(), id.end());
        id.resize(unique(id.begin(), id.end()) - id.begin());
        for (ll i = 0; i < n; i++)
        {
            arr[i] = (lower_bound(id.begin(), id.end(), arr[i]) - id.begin() + 1);
        }

        // for (ll i = 0; i < n; i++)
        //     cout << arr[i] << ' ';
        ans = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            ans += query(arr[i] - 1);
            modify(arr[i], 1);
        }
        cout << ans << '\n';
        id.clear();
        bit.clear();
        arr.clear();
    }
    return 0;
}
