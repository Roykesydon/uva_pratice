#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, ans, x;
    while (cin>>m) {
        ans=0;
        for (int i=0;i<m;i++) {
            cin>>x;
            ans^=x;
        }
        if (ans)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
