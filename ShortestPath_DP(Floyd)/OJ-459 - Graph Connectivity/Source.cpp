#define _CRT_SECURE_NO_WARNINGS
#define INF 99999
#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
	int caseNum;
	char size;
	scanf("%d", &caseNum);
	getchar();
	getchar();
	char tmpAlphabets[4];
	int DP[26][26];
	int flag[26];
	int detect;
	int ans;
	int caseCount;
	caseCount = 0;
	while (caseCount<caseNum)
	{
		fgets(tmpAlphabets, 4, stdin);
		size = tmpAlphabets[0];
		//cout << "size=" << size << endl;
		for (int i = 0; i < size - 'A' + 1; i++)
			for (int j = 0; j < size - 'A' + 1; j++)
				if (i != j)DP[i][j] = INF;
				else DP[i][j] = 1;
		for (int i = 0; i < size - 'A' + 1; i++)
			flag[i] = 0;

		while (fgets(tmpAlphabets, 4, stdin) && tmpAlphabets[0] != '\n')
		{
			DP[tmpAlphabets[0] - 'A'][tmpAlphabets[1] - 'A'] = 1;
			DP[tmpAlphabets[1] - 'A'][tmpAlphabets[0] - 'A'] = 1;

			for (int i = 0; i < 3; i++)
				tmpAlphabets[i] = '\0';
		}

		for (int k = 0; k < size - 'A' + 1; k++)
			for (int i = 0; i < size - 'A' + 1; i++)
				for (int j = 0; j < size - 'A' + 1; j++)
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
		//------------------------------------------
		/*
		for (int i = 0; i < size - 'A' + 1; i++)
		{
			for (int j = 0; j < size - 'A' + 1; j++)
				cout << DP[i][j] << ' ';
			cout << endl;
		}
		*/
		//-------------------------------------------
		ans = 0;
		for (int i = 0; i < size - 'A' + 1; i++)
		{
			detect = 0;
			for (int j = 0; j < size - 'A' + 1; j++)
			{
				if (DP[i][j] != INF && flag[j] == 0)
				{
					flag[i] = 1;
					flag[j] = 1;
					detect = 1;
				}
			}
			if (detect == 1)
				ans++;
			
		}
		if (caseCount++)
			cout << endl;
		cout << ans << endl;
				
	}

	return 0;
}