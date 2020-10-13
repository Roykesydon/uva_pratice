#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int p, q, v;
    friend bool operator<(node a, node b)
    {
        return a.q - a.p < b.q - b.p; // look down
    }
};
vector<int> dp;
vector<node> arr; //dp[n]:item n chooses earlier than n-1...1!!!!!!!!
/*
if can buy a independently and can buy a independently 
if(A=>B)is better than (A<=B)
buy A firstly needs at least p1+q2
buy B firstly needs at least p2+q1;
p1+q2<p2+q1 => q1-p1>q2-p2;
*/ 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        arr.clear();
        arr.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i].p >> arr[i].q >> arr[i].v;
        sort(arr.begin() + 1, arr.end());
        dp.clear();
        dp.resize(m + 1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= arr[i].p && j >= arr[i].q; j--)
                dp[j] = max(dp[j], dp[j - arr[i].p] + arr[i].v);
        cout << dp[m] << '\n';
    }
    return 0;
}
/*
1 10
10 2 1
*/
