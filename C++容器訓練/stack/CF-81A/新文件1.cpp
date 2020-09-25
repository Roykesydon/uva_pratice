#include <bits/stdc++.h>
using namespace std;
#define ll long long
stack<char>st;
vector<char>vec;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(!st.empty()){
            auto u=st.top();
            if(u==str[i])
                st.pop();
            else
                st.push(str[i]);
        }
        else
            st.push(str[i]);
    }
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    while(vec.size()){
        cout<<vec.back();
        vec.pop_back();
    }
    cout<<'\n';

    return 0;
}
