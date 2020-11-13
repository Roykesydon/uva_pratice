#include <bits/stdc++.h>
using namespace std;
#define MAXN (100)
int failure[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,len;
	string str;
	cin >> n;
	for(int cas=1;cas<=n;cas++)
	{
		cin >> str;
		for (int i = 1, j = failure[0] = -1; i < str.size(); ++i)
		{
			while (j >= 0 && str[j + 1] != str[i])
				j = failure[j];
			if (str[j + 1] == str[i])
				j++;
			failure[i] = j;
		}
		len=str.size();
		for(int i=0;i<len;i++)
			failure[i]++;
		
		if(cas!=1)cout<<'\n';
		if(len%(len-failure[len-1])!=0)
			cout<<len<<'\n';
		else
			cout<<len-failure[len-1]<<'\n';
	}
<<<<<<< HEAD

=======
>>>>>>> 7f2a55bfb6b02b5937addd9ef61909a5229d4769
	return 0;
}
