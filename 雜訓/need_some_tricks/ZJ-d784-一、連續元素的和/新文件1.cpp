#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> dp;
int main()
{
    int n, t, maxd;
    int tmp;
    while (cin >> t)
    {
        while (t--)
        {
            cin >> n;
            maxd = -1e9;
            arr.resize(n);
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            tmp=0;
            for(int i=0;i<n;i++)
            {
                tmp+=arr[i];
                maxd=max(maxd,tmp);
                if(tmp<0)tmp=0;
            }
            cout<<maxd<<'\n';
            arr.clear();
        }
    }
    return 0;
}
