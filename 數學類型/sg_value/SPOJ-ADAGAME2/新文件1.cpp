#include <bits/stdc++.h>
using namespace std;
vector<int> rule;
int n, m;
vector<int> sg;
int get_sg()
{
    for(int i=0;i<rule[0];i++)
        sg[i]=0;
    int hash[30+1];
    
    for (int i = rule[0]; i <100000+1; i++)
    {
        memset(hash,0,sizeof(hash));
        for(int j=0;j<m;j++){
            if(rule[j]>i)
                break;
            hash[sg[i-rule[j]]]++;
        }
        for(int j=0;j<31;j++)
            if(!hash[j]){
                sg[i]=j;
                break;
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int ans,x;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rule.clear();
        rule.resize(m);
        sg.clear();
        sg.resize(100000 + 1, -1);
        for (int i = 0; i < m; i++)
            cin >> rule[i];
        sort(rule.begin(), rule.end());
        ans = 0;
        get_sg();
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            ans ^= sg[x];
        }
        cout<<((ans)?"Ada\n":"Vinit\n");
    }

    return 0;
}
