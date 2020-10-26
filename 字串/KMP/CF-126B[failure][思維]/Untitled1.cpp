#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define endl '\n'
int failure[MAXN];
bool vis[MAXN]; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int tmp,len,ans;
    while (cin >> str)
    {
        len=str.size();
        memset(vis,0,sizeof(vis));

        for (int i = 1, j = failure[0] = -1; i < str.size(); ++i)
        {
            while (j >= 0 && str[j + 1] != str[i])
                j = failure[j];
            if (str[j + 1] == str[i])
                j++;
            failure[i] = j;
        }
        for (int i = 0; i < len; i++)
            failure[i]++;
        
        tmp=failure[len-1];
        while(tmp){
            vis[tmp]=1;
            tmp=failure[tmp-1];
        }

        ans=0;
        for(int i=0;i<len-1;i++)
            if(vis[failure[i]])
                ans=max(ans,failure[i]);
        if(ans==0)
            cout<<"Just a legend\n";
        else
            cout<<str.substr(0,ans)<<endl;

    }

    return 0;
}
