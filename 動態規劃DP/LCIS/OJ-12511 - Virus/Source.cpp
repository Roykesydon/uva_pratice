#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int caseNum;
	int s1Num,s2Num;
	int s1[1002], s2[1002];
	int **LCIS;
	int tmpmax;
	LCIS = (int**)malloc(sizeof(int*) * 1002);
	for (int i = 0; i < 1002; i++)
		*(LCIS + i) = (int*)malloc(sizeof(int) * 1002);
	scanf("%d", &caseNum);
	while (caseNum--)
	{
		scanf("%d", &s1Num);
		for (int i = 1; i <= s1Num; i++)
			scanf("%d", &s1[i]);
		scanf("%d", &s2Num);
		for (int i = 1; i <= s2Num; i++)
			scanf("%d", &s2[i]);
		
		for (int i = 0; i < 1002; i++)
		{
			LCIS[i][0] = 0;
			LCIS[0][i] = 0;
		}
		for (int i = 1; i <= s1Num; i++)
		{
			tmpmax = 0;
			for (int j = 1; j <= s2Num; j++)//---s2
			{								//-
				if (s2[j] < s1[i])			//s1
				{
					if (tmpmax < LCIS[i - 1][j])
						tmpmax = LCIS[i - 1][j];

					LCIS[i][j] = LCIS[i - 1][j];
				}

				if (s2[j] == s1[i])
					LCIS[i][j] = tmpmax + 1;

				else if(s2[j]>s1[i])
					LCIS[i][j] = LCIS[i - 1][j];
			}
		}
		tmpmax = 0;


		//------------------
		/*
		puts("");
		for (int i = 0; i <= s1Num; i++)
		{
			for (int j = 0; j <= s2Num; j++)
			{
				cout << LCIS[i][j] << ' ';
			}
			puts("");
		}
		*/
		//-----------------------

		for (int i = 0; i <= s2Num; i++)
			tmpmax = max(tmpmax, LCIS[s1Num][i]);

		cout << tmpmax<<endl;
	}


	return 0;
}