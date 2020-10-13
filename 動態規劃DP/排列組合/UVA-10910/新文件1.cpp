#include <bits/stdc++.h>
using namespace std;
#define MAXN (1120)
vector<vector<int>> C;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,p;
    C.resize(150);
    for(int i=0;i<150;i++)
        C[i].resize(150,0);
    for(int i=0;i<150;i++){
        C[i][i]=1;
        C[i][0]=1;
    }
    for(int i=1;i<150;i++){
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        cout<<C[m-n*p+n-1][n-1]<<'\n';
    }
    

    return 0;
}
