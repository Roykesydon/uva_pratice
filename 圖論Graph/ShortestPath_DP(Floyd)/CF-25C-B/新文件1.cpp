#include<bits/stdc++.h>
using namespace std;
/*
class edge
{
    public:
        int node1;
        int node2;
        int weight;
};
*/
/*
class cmp
{
    public:
    bool operator()(edge a, edge b)
    {
        return a.weight<b.weight;
    }
};
*/
/*
bool cmp(edge a,edge b)
{
    return a.weight<b.weight;
}
*/
    

long long dp[301][301];
//int f[301];
/*
int find(int x)
{
    if(f[x]==x)
        return x;
    else
        return f[x]=find(f[x]);
}
void merge(int a,int b)
{
    f[a]=b;
}
*/
//vector<edge>vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    long long ans,c;
    int a,b;
    while(cin>>n)
    {
        //vec.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>dp[i][j];
            }
        }
        cin>>k;
  
        for(int z=0;z<k;z++)
        {
            ans=0;
            if(z)cout<<' ';
            cin>>a>>b>>c;
            /*
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    tmp[i][j]=dp[i][j];     
            */

            if(dp[a][b]>c)
            {
                int k;
                dp[a][b]=c;
                dp[b][a]=c;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        dp[i][j]=min(dp[i][j],dp[i][a]+dp[a][j]);
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        dp[i][j]=min(dp[i][j],dp[i][b]+dp[b][j]);
            }
            /*
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    vec.push_back({i,j,tmp[i][j]});
            */
  




            
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    ans+=dp[i][j];
            //-------------      
            /*
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    cout<<tmp[i][j]<<' ';
                cout<<endl;
            }        
            */
            //-------------  
            /*
            for(int i=1;i<=n;i++)
                f[i]=i;
            sort(vec.begin(),vec.end(),cmp);
            for(auto i:vec)
            {
                a=find(i.node1);
                b=find(i.node2);
                if(a!=b)
                {
                    ans+=i.weight;
                    merge(a,b);
                }
            }
            */
            cout<<ans;
            //vec.clear();
        }
        cout<<endl;
            
    }


}
