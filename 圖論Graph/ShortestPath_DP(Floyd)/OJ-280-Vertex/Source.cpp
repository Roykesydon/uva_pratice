#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define INF 999999999

int main()
{
	int repeat;
	int** DP;
	int tmpa;
	int point_start;
	int search_case;
	int ans;
	int point_end;
	int tmp;
	while (scanf("%d", &repeat)&&repeat)
	{
		ans = 0;
		DP = (int**)malloc(sizeof(int*) * repeat);
		for (int i = 0; i < repeat; i++)
			*(DP + i) = (int*)malloc(sizeof(int) * repeat);
		for (int i = 0; i < repeat; i++)
			for (int j = 0; j < repeat; j++)
				*(*(DP + i) + j) = INF;
		

		while (scanf("%d", &point_start)&&point_start)
		{
			while (scanf("%d", &point_end) && point_end)
			{
				DP[point_start-1][point_end-1] = 1;
			}
		}

		for (int k = 0; k < repeat; k++)
			for (int j = 0; j < repeat; j++)
				for (int i = 0; i < repeat; i++)
					DP[j][i] = min(DP[j][i],DP[j][k] + DP[k][i]);

		//------------------------------------
		/*
		puts("");
		for (int i = 0; i < repeat; i++)
		{
			for (int j = 0; j < repeat; j++)
			{
				cout << DP[i][j] << ' ';
			}
			puts("");
		}
		cout << endl;
		*/
		//-------------------------------------


		scanf("%d",&search_case);
		for (int i = 0; i < search_case; i++)
		{
			ans = 0;
			scanf("%d", &tmp);
			for (int k = 0; k < repeat; k++)
				if (DP[tmp-1][k] == INF)
					ans++;
			cout << ans;
			if(ans!=0)
			{
				for (int j = 0; j < repeat; j++)
				{
					if (DP[tmp-1][j] == INF)
					{
						cout << ' ';
						printf("%d", j + 1);
					}
				}
			}
			puts("");
		}

		for (int i = 0; i < repeat; i++)
			free(*(DP + i));
		free(DP);
	}

	return 0;
}