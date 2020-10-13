#include <bits/stdc++.h>
using namespace std;
#define MAXN 20000000
#define ll long long
int sg[MAXN + 1];
int sprime[MAXN+1];
inline int find_factor(int x){
    int ans=1;
    int cnt,tmp;
    while(x>1){
        cnt=1;
        tmp=sprime[x];
        while(x%tmp==0){
            cnt++;
            x/=tmp;
        }
        ans*=cnt;
    }
    return ans;
}
inline void init()
{
    for(int i=1;i<=MAXN;i++)
        sprime[i]=i;
    for(ll i=2;i<=MAXN;i++){
        if(sprime[i]!=i)continue;
        for(ll j=i*i;j<=MAXN;j+=i){
            sprime[j]=min(sprime[j],(int)i);
        }
    }
}
inline void getsg()
{
    int maxn=0;
    sg[0] = 0;
    for(int i=1;i<=MAXN;i++){
        if(i-find_factor(i)<=maxn)
            sg[i]=1;
        else
        {
            sg[i]=0;
            maxn=i;
        }   
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, x;
    cin >> t;
    init();
    getsg();
    while (t--)
    {
        cin >> x;
        if (sg[x])
            cout << "Ada\n";
        else
            cout << "Vinit\n";
    }

    return 0;
}
/*
1   1
1

2   2
1 2

3   2
1 3

4   3
1 2 4

5   2  
1 5

6   4   
1 2 3 6

7   2  
1 7 

8   4
1 2 4 8

9   3
1 3 9

10  3
1 2 5 10

11  2
1 11

12  6
1 2 3 4 6 12  

13  2
1 13

14  4
1 2 7 14

15  4
1 3 5 15

30  8
1 2 3 5 6 10 15 30
*/
