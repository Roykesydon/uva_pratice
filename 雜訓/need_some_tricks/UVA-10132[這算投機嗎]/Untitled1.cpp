#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> arr;
struct cmp{
    bool operator()(string a,string b){
        if(a.size()!=b.size())
            return a.size()<b.size();
        return a<b;
    }
};
bool check(string aim){
    string tmp;
    for(int i=0;i<arr.size();i++){
        if(arr[1].size()+arr[i].size()==aim.size()){
            if(arr[1]+arr[i]==aim)
                return true;
            if(arr[i]+arr[1]==aim)
                return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,len,cnt=0;
    string str,sa;
    cin >> t;
    getline(cin, str);
    getline(cin, str);
    while (t--)
    {
        if(cnt++)cout<<'\n';
        arr.clear();
        while (getline(cin, str)&&str.size() != 0)
            arr.push_back(str);
        sort(arr.begin(),arr.end(),cmp());
        len=arr[0].size()+arr[arr.size()-1].size();
        for(int i=arr.size()-1;i>=0&&arr[i].size()==arr[arr.size()-1].size();i--){
            sa=arr[0]+arr[i];
            if(check(sa))
                break;
            sa=arr[i]+arr[0];
            if(check(sa))
                break;
        }
        cout<<sa<<'\n';
    }

    return 0;
}
//a+(b-c)*d+e/g
