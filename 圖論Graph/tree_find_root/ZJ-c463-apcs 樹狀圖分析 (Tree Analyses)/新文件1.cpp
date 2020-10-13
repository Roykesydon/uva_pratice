#include<bits/stdc++.h>
using namespace std;

vector <long long>node;
vector <vector<int> >vec;
void DFS(int cur,long long value)
{
    if(node[cur]<value)
        node[cur]=value;
    for(auto i:vec[cur])
    {
        DFS(i,value+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,maxp;
    long long ans,maxd;
    int k,tmp;
    while(cin>>n)
    {
        vec.resize(n+1);
        node.resize(n+1);
        for(int i=1;i<=n;i++)
            node[i]=-1e9;
        for(int i=1;i<=n;i++)
        {
            cin>>k;
            for(int j=0;j<k;j++)
            {
                cin>>tmp;
                vec[tmp].push_back(i);
            }
            if(k==0)
                node[i]=0;
        }
        for(int i=1;i<=n;i++)
            if(node[i]==0)
                DFS(i,0);
        /*
        for(int i=1;i<=n;i++)
        {
            for(auto j:vec[i])
            {
                if(node[j]<node[i]+1)
                    node[j]=node[i]+1;
            }
        }
        */
        ans=0;
        maxd=0;
        maxp=-1;

        // for(int i=1;i<=n;i++)
        // {
        //     cout<<"node["<<i<<"]="<<node[i]<<endl;
        // }

        for(int i=1;i<=n;i++)
        {
            ans+=node[i];
            if(node[i]>maxd)
            {
                maxd=node[i];
                maxp=i;
            }
        }
        cout<<maxp<<'\n'<<ans<<'\n';
    }

    
    
    //system("PAUSE");
}
