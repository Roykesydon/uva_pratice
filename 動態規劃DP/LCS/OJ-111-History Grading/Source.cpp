#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int n;
	int tmp[21];
	int correct[21];
	int test[21];
	int len[21][21];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &tmp[i]);
	for (int i = 1; i <= n; i++)
		correct[tmp[i]] = i;
	while (scanf("%d",&tmp[1]) != EOF)
	{
		for (int i = 2; i <= n; i++)
			scanf("%d", &tmp[i]);
		for (int i = 1; i <= n; i++)
			test[tmp[i]] = i;

		correct[0] = 0;
		test[0] = 0;

		for (int i = 0; i <= n; i++)
		{
			len[i][0] = 0;
			len[0][i] = 0;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (correct[i] == test[j])
					len[i][j] = len[i - 1][j - 1] + 1;
				else
					len[i][j] = max(len[i - 1][j],len[i][j - 1]);

		cout <<len[n][n]<<endl;

	}

	return 0;
}