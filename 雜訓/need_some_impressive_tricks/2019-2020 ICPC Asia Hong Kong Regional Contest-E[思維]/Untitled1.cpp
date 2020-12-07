#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>arr;
int n,t;
//1 2 3 4 5 6 7 8 9
//  3 2 1 0 1 2 3
bool check(int pos){
    if(arr[pos]==n||arr[pos]==1)return 0;
    int dif=abs(arr[pos]-(n+1)/2);
    bool flag=0;
    int now=0,cnt=0;
    if(arr[pos]==(n+1)/2)return true;
    if(arr[pos]>(n+1)/2)flag=1;
    for(int i=0;i<n;i++){
        if(i==pos){
            now=0;
            continue;
        }

        if(flag){//too many zero 
            if(arr[i]<arr[pos]){
                now++;
                if(now==3){
                    cnt++;
                    now-=2;
                }   
            }
            else
                now=max(now-1,0);
        }
        else{
            if(arr[i]>arr[pos]){
                now++;
                if(now==3){
                    cnt++;
                    now-=2;
                }   
            }
            else
                now=max(now-1,0);
        }
    }
    return cnt>=dif;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        arr.clear();
        arr.resize(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
            cout<<((check(i))?"1":"0");
        cout<<'\n';
    }


    return 0;
}
