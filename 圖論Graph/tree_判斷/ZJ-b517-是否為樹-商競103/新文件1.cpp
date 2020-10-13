#include<bits/stdc++.h>
using namespace std;

vector<int>vec[81];
bool vis[81];
set<int>myset;
bool flag;
void DFS(int from,int cur)
{
    //cout<<"from: "<<from<<"  cur: "<<cur<<endl; 
    if(vis[cur])
    {
        flag=false;
        return;
    }

    vis[cur]=true;
    for(auto i:vec[cur])
    {
        if(i!=from)
        {
            DFS(cur,i);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    int x,y;
    char ch;
    string a;
    stringstream ss,ss2;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        flag=true;
        myset.clear();
        ss.str("");
        getline(cin,a);
        ss<<a;
        while(ss>>a)
        {
            ss2.str("");
            ss2<<a;
            ss2>>x>>ch>>y;
            myset.insert(x);
            myset.insert(y);
            vec[x].push_back(y);
            vec[y].push_back(x);
            ss2.clear();
        }
        ss.clear();
        for(int i=0;i<81;i++)
            vis[i]=false;

        
        /*
        for(int i=0;i<81;i++)
        {
            cout<<i<<" : ";
            for(auto j:vec[i])
            {
                cout<<j<<' ';
            }
            cout<<endl;
        }
        */
        DFS(-1,x);
        //cout<<"YES";
        for(auto i:myset)
        {
            if(vis[i]==false)
                flag=false;
        }
        if(flag)
            cout<<"T\n";
        else
            cout<<"F\n";
        for(int i=0;i<81;i++)
            vec[i].clear();

    }
    
    
    //system("PAUSE");
}
