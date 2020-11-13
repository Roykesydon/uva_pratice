#include<bits/stdc++.h>
using namespace std;
vector<int>choice;
int sg[10000+1];
int dfs(int x) {
    if (sg[x]!=-1)return sg[x];
    int mex[x+1];
    memset(mex, 0, sizeof(mex));
    for (int i=0;i<choice.size()&&choice[i]<=x;i++)
        mex[dfs(x-choice[i])]++;
    for (int j=0;j<=x;j++)
        if (!mex[j])
            return sg[x]=j;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, m, l, ans, x;
    while (cin>>k&&k) {
        choice.clear();choice.resize(k);
        for (int i=0;i<k;i++)
            cin>>choice[i];
        sort(choice.begin(), choice.end());
        cin>>m;
        memset(sg, -1, sizeof(sg));
        for (int i=0;i<choice[0];i++)
            sg[i]=0;
        for (int i=0;i<m;i++) {
            cin>>l;
            ans=0;
            for (int j=0;j<l;j++) {
                cin>>x;
                if (sg[x]!=-1)
                    ans^=sg[x];
                else {
                    ans^=dfs(x);
                }
            }
            if (ans)cout<<"W";
            else cout<<"L";
        }
        cout<<'\n';
    }


    return 0;
}
// void get_sg() {
//     memset(sg, 0, sizeof(sg));
//     for (int i=0;i<choice[0];i++)
//         sg[i]=0;
//     for (int i=choice[0];i<10000+1;i++) {
//         memset(mex, 0, sizeof(mex));
//         for (int j=0;j<choice.size()&&choice[j]<=i;j++) {
//             mex[sg[i-choice[j]]]++;
//             for (int j=0;j<10000+1;j++)
//                 if (!mex[j]) {
//                     sg[i]=j;
//                     break;
//                 }
//         }
//     }
// }
