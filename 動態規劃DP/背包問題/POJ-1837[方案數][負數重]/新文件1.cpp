#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAXN 1000
int dp[21][MAXN * 2 + 1];
vector<int> hook, item;
int main()
{
	int c, g, x;
	cin >> c >> g;
	hook.resize(c + 1);
	item.resize(g + 1);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= c; i++)
		cin >> hook[i];
	for (int i = 1; i <= g; i++)
		cin >> item[i];
	dp[0][MAXN] = 1;
	for (int i = 1; i <= g; i++) //所有物品i
		for (int k = 1; k <= c; k++) //所有hook k
			for (int j = 2 * MAXN; j >= 0; j--) //遍歷
				if (j + item[i] * hook[k] >= 0 && j + item[i] * hook[k] <= MAXN * 2)
					dp[i][j + item[i] * hook[k]] += dp[i - 1][j];
	cout<<dp[g][MAXN]<<'\n';

	return 0;
}
