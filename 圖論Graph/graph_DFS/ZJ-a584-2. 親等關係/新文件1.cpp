#include<bits/stdc++.h>
using namespace std;

map<string, vector<string> >mp;
int ans;
int DFS(string from,string cur,int value,string aim)
{
    if(cur==aim)
        ans=value;
    for(auto i:mp[cur])
    {
        if(i!=from)
        {
            DFS(cur,i,value+1,aim);
        }
    }
}
int main()
{
    int n;
    string a,b;
    stringstream ss;
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    while(cin>>n)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
 
            getline(cin,a);
            ss.str("");
            ss<<a;
            ss>>a;
            while(ss>>b)
            {
                if(a!=b)
                    mp[a].push_back(b);
                if(b!=a)
                    mp[b].push_back(a);
            }
            ss.clear();
        }
        /*
        for(auto i:mp)
        {
            cout<<"//-------------------\n";
            cout<<i.first<<endl;
            for(auto j:i.second)
                cout<<j<<' ';
            cout<<endl;
            cout<<"//-------------------\n";
        }
        */
        cin>>a>>b;
        ans=0;
        DFS("\n",a,0,b);
        cout<<ans<<'\n';



        for(auto i:mp)
            i.second.clear();
        mp.clear();
    }
    
}
