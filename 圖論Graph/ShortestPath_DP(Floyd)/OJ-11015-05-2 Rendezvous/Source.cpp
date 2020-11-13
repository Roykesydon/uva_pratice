#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int N, M;
	int times=0;
	int ans;

	int DP[22][22];
	int tmp_distance;
	int min_distance;
	int p_start, p_end, p_distance;
	while (scanf("%d %d", &N, &M) && (N || M))
	{
		char peoplename[22][11] = { '0' };
		for (int i = 0; i < 22; i++)
			for (int j = 0; j < 22; j++)
				DP[i][j] = 9999999;

		for (int i = 0; i < N; i++)
			scanf("%s", *(peoplename + i));
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &p_start, &p_end, &p_distance);
			DP[p_start - 1][p_end - 1] = p_distance;
			DP[p_end - 1][p_start - 1] = p_distance;
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);


		//-------------------------------
		/*
		puts("");
		cout << "This is Case " << times + 1<<endl;
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				printf("%5d",DP[k][i]);
			}
			for (int i = 0; i < N; i++)
			{
				tmp_distance = 0;
				for (int j = 0; j < N; j++)
				{
					tmp_distance += DP[i][j];
				}
			}
			cout << "┴`ж@кс" << tmp_distance<<endl;
			cout << endl;
		}
		cout << endl;
		*/
		//-----------------------
		ans = 0;
		min_distance = 999999999;
		for (int i = 0; i < N; i++)
		{
			tmp_distance = 0;
			for (int j = 0; j < N; j++)
			{
				if(j!=i)
				tmp_distance += DP[i][j];
			}
			if (tmp_distance < min_distance)
			{
				min_distance = tmp_distance;
				ans = i;
			}
		}

		printf("Case #%d : %s\n", ++times,*(peoplename+ans));
	}
	return 0;
}