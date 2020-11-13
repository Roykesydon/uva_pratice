#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> arr;
bitset<125001>bit;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, cnt, ans;
	ll sum, mid, l, r,tmp;
	string str;
	stringstream ss;
	while (getline(cin, str))
	{
		arr.resize(5000);
		ss.clear();
		ss.str("");
		ss << str;
		cnt = 0;
		while (ss >> x)
			arr[cnt++] = x;
		sum = 0;
		//cerr<<0<<'\n';
		for (int i = 0; i < cnt; i++)
			sum += arr[i];
        bit=1;
        for(int i=0;i<cnt;i++)
        {
            bit|=bit<<arr[i];
        }
        // for(int i=sum;i>=0;i--)
        // {
        //     cout<<"bit["<<i<<"]= "<<bit[i]<<endl;
        // }
        for(int i=sum/2;i>0;i--)
        {
            if(bit[i]==true)
            {
                cout<<i*(sum-i)<<'\n';
                break;
            }
        }


		//cerr << 2 << '\n';

		arr.clear();
	}
}
