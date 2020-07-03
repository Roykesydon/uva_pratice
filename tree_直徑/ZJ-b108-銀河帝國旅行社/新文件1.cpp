#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >vec;
int maxd,maxp;
void DFS(int from, int cur,int value)
{

    if(value>maxd)
    {
        maxd=value;
        maxp=cur;
    }

    for(auto i:vec[cur])
    {
        if(i!=from)
            DFS(cur,i,value+1);
    }
}
int main()
{
    int n,tmp;
    while(cin>>n)
    {
        maxd=0;
        maxp=0;
        vec.resize(n);
        for(int i=0;i<n;i++)
        {
            while(cin>>tmp)
            {
                if(tmp==-1)
                    break;
                vec[i].push_back(tmp);
                vec[tmp].push_back(i);
            }
        }
        DFS(-1,0,0);
        maxd=0;
        DFS(-1,maxp,0);
        cout<<maxd<<'\n';


        for(int i=0;i<vec.size();i++)
            vec[i].clear();
        vec.clear();
    }
    
}
