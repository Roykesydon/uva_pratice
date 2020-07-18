#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> LCS;
vector<vector<int>> pre;
int main()
{
	string s1, s2;
	string ans;
	int i, j;
	while (cin >> s1 >> s2)
	{
		//cerr<<s1<<' '<<s2<<'\n';
		LCS.resize(s1.size() + 1);
		for (int i = 0; i <= s1.size(); i++)
			LCS[i].resize(s2.size() + 1, 0);
		pre.resize(s1.size() + 1);
		for (int i = 0; i <= s1.size(); i++)
			pre[i].resize(s2.size() + 1, -1);
		//cerr<<"step 1\n";
		for (int i = 1; i <= s1.size(); i++)
		{
			for (int j = 1; j <= s2.size(); j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					pre[i][j] = 0;
				}

				else
				{
					LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
					if(LCS[i - 1][j]>= LCS[i][j - 1])
						pre[i][j]=1;//¤W­±
					else
						pre[i][j]=2;
				}
			}
		}
		//cerr<<"step 2\n";
		i = s1.size();
		j = s2.size();
		ans = "";
		while (i > 0 && j > 0)
		{
			if(pre[i][j]==0)
			{
				ans+=s1[i-1];
				i--;j--;
			}
			else if(pre[i][j]==1)
			{
				i--;
			}
			else
			{
				j++;
			}
			
		}
		/*
		for (int i = 0; i <= s1.size(); i++)
		{
			for (int j = 0; j <= s2.size(); j++)
				cout << setw(5) << LCS[i][j];
			cout << '\n';
		}
		*/
		//cerr<<ans.size()<<'\n';
		if (ans.size() == 0)
			ans += 'E';
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i];
		cout << '\n';
	}

	return 0;
}
