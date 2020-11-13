#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define MAX 60
using namespace std;
int main()
{
	long long int dif[MAX][MAX];
	int LCS[MAX][MAX];
	char s1[MAX], s2[MAX];
	int test;
	int casenum = 1;
	scanf("%d ", &test);
	while (test--)
	{
		fgets(s1, sizeof(s1), stdin);
		fgets(s2, sizeof(s2), stdin);
		for (int i = 0; i < MAX; i++)
			if (s1[i] == '\n')
				s1[i] = '\0';
		for (int i = 0; i < MAX; i++)
			if (s2[i] == '\n' )
				s2[i] = '\0';
		for (unsigned int i = 0; i <= strlen(s1); i++)
		{
			LCS[i][0] = 0;
			dif[i][0] = 1;
		}
		for (unsigned int i = 0; i <= strlen(s2); i++)
		{
			LCS[0][i] = 0;
			dif[0][i] = 1;
		}
		for(unsigned int i=1;i<=strlen(s1);i++)
			for (unsigned int j = 1; j <= strlen(s2); j++)
			{
				if (s1[i-1] == s2[j-1])
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					dif[i][j] = dif[i - 1][j - 1];
				}
				else
				{
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
					if (LCS[i - 1][j] > LCS[i][j - 1])
						dif[i][j] = dif[i - 1][j];
					else if (LCS[i][j - 1] > LCS[i - 1][j])
						dif[i][j] = dif[i][j - 1];
					else if (LCS[i][j - 1] == LCS[i - 1][j])
						dif[i][j] = dif[i - 1][j] + dif[i][j - 1];
				}
			}
		cout << "Case #" << casenum++ << ": " << strlen(s1)+strlen(s2)-LCS[strlen(s1)][strlen(s2)] << ' ' << dif[strlen(s1)][strlen(s2)] << endl;
		/*
		for (unsigned int i = 0; i < MAX; i++)
		{
			s1[i] = 0;
			s2[i] = 0;
			for (unsigned int j = 0; j < MAX; j++)
			{
				LCS[i][j] = 0;
				dif[i][j] = 0;
			}
		}
		*/
		
	}
	return 0;
}