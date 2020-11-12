#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> arr;
stack<pair<ll, ll>> st;
int main()
{
    ll n;
    ll ans = 0;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    st.push(make_pair(0, arr[0]));
    for (int i = 1; i < n; i++)
    {
        int tmp=i;
        while (!st.empty()&&arr[i] < st.top().second)
        {
            ans = max(ans, st.top().second * (i - st.top().first));
            tmp=st.top().first;
            st.pop();
        }
        if (st.empty() || arr[i] > st.top().second)
            st.push(make_pair(tmp, arr[i]));
    }
    while (!st.empty())
    {
        ans = max(ans, st.top().second * (n - st.top().first ));
        st.pop();
    }
    cout<<ans<<'\n';
    return 0;
}
