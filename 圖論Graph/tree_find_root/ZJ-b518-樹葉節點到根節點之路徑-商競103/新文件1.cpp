#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >vec;
vector<int>ans;
set<int>myset;
int root;
void DFS(int cur)
{
    if(cur==root)
        return;
    for(auto i:vec[cur])
    {
        ans.push_back(i);
        DFS(i);
    }
}
int main()
{
    int n,m;
    int cnt;
    int x,y;
    char ch;
    string a;
    //stringstream ss;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i)cout<<'\n';
        cin>>m;
        vec.resize(m);
        for(int j=0;j<m;j++)
        {
            //ss.str("");
            cin>>x;
            cin.ignore(1,',');
            cin>>y;
            //cout<<x<<y<<endl;
            if(y==99)
            {
                root=x;
                continue;
            }
            vec[x].push_back(y);
            myset.insert(y);
            //ss.clear();
        }
        if(m==1)
        {
            for(auto i:vec)
                i.clear();
            vec.clear();
            myset.clear();
            cout<<"0:N\n"; 
            continue;
        }

        /*
        for(int i=0;i<m;i++)
        {
            cout<<"vec["<<i<<"]: ";
            for(auto j:vec[i])
                cout<<j<<' ';
        }
        cout<<endl;

        cout<<"myset: ";
        for(auto i:myset)
            cout<<i<<' ';
        cout<<endl;
        */

        for(int i=0;i<m;i++)
        {
            if(myset.find(i)==myset.end())
            {
                ans.clear();
                DFS(i);
                ans.pop_back();          
                cout<<i<<":";

                if(!ans.empty())
                {
                    cout<<'{';
                    for(int i=0;i<ans.size();i++)
                    {
                        if(i)cout<<',';
                        cout<<ans[i];
                    }
                    cout<<"}\n";
                }
                else
                    cout<<"N\n";
                ans.clear();
            }

            

        }


        
        for(auto i:vec)
            i.clear();
        vec.clear();
        myset.clear();

    }
    
    //system("PAUSE");
}
