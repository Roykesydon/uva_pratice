#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int at[101];
	int bt[101];
	int LCS[101][101];
	int casenum = 0;
	int anum, bnum;
	at[0] = 0;
	bt[0] = 0;
	while (scanf("%d %d", &anum, &bnum) && (anum || bnum))
	{
		for (int i = 1; i <= anum; i++)
			scanf("%d", &at[i]);
		for (int i = 1; i <= bnum; i++)
			scanf("%d", &bt[i]);

		for (int i = 0; i < anum; i++)
			LCS[i][0] = 0;
		for (int i = 0; i < bnum; i++)
			LCS[0][i] = 0;

		for (int i = 1; i <= anum; i++)
			for (int j = 1; j <= bnum; j++)
			{
				if (at[i] == bt[j])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		cout << "Twin Towers #" << ++casenum << endl;
		cout << "Number of Tiles : " << LCS[anum][bnum] << endl;
		puts("");
	}

	return 0;
}