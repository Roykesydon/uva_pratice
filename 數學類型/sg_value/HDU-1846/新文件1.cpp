#include<bits/stdc++.h>
using namespace std;
int sg[1000+1];
int mex[1000+1];
int n, m;
void sg_value() {
    sg[0]=0;
    for (int i=1;i<1001;i++) {
        memset(mex, 0, sizeof(mex));
        for (int j=1;j<=m&&j<=i;j++) {
            mex[sg[i-j]]++;
        }
        for (int j=0;j<1000+1;j++)
            if (!mex[j]) {
                sg[i]=j;
                break;
            }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin>>c;
    while (c--) {
        cin>>n>>m;
        sg_value();
        if (sg[n])cout<<"first\n";
        else cout<<"second\n";
    }
}
