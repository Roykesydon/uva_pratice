#include<bits/stdc++.h>
using namespace std;
#define reszie resize
vector<int>dp;
int main(){
    int st=0,start=0,ans=0;
    string str;
    cin>>str;
    dp.reszie(str.size(),0);
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            st++;
        }
        else{
            if(st!=0){
                if(str[i-1]=='('){
                    if(i>=2)
                        dp[i]=dp[i-2]+1;
                    else
                        dp[i]=1;
                }
                else{
                    if(i-dp[i-1]*2-1>=0&&str[i-dp[i-1]*2-1]=='('){
                        dp[i]=dp[i-1]+1;
                        if(i-dp[i-1]*2-1-1>=0)
                            dp[i]+=dp[i-dp[i-1]*2-1-1];
                    }
                }
                st--;
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans*2<<'\n';

    return 0;
}
