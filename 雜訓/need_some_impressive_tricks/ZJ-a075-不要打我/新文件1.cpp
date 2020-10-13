#include<bits/stdc++.h>
using namespace std;

//int vec[5000000+2];
vector<int>vec;
//int arr[5000000+1];
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
        vec.resize(n+2);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        vec[n]=1e9;
        vec[n+1]=1e9;
        i=0,j=-1;
        ans=0;
        while(j<=n&&i<n)
        {
            if(ans>k)
            {
                if(i!=0)cout<<' ';
                cout<<j;
                ans-=vec[i];
                i++;
            }
            else if(ans==k)
            {
                if(i!=0)cout<<' ';
                cout<<j+1;
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
        cout<<endl;
        vec.clear();
    }
    //system("PAUSE");
    return 0;
}
