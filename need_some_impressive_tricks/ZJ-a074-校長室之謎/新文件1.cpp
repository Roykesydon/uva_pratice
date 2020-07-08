#include<bits/stdc++.h>
using namespace std;

int vec[10000000+1];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k,tmp;
    int i,j;
    int cnt;
    int ans;
    while(cin>>n>>k)
    {
        ans=0;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        vec[n]=0;
        i=0;
        j=-1;
        while(j<n)
        {
            if(ans==k)
            {
                j++;
                ans+=vec[j];
                cnt++;
                
            }
            else if(ans>k)
            {
                ans-=vec[i];
                i++;
            }
            else if(ans<k)
            {
                j++;
                ans+=vec[j];
                
            }
            //cout<<"i: "<<i<<" j: "<<j<<" ans: "<<ans<<endl;
        }

        cout<<cnt<<'\n';
    }
    //system("PAUSE");
    return 0;
}
