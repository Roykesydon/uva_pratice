#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct dint
{
	int xpos;
	int ypos;
};
typedef struct dint DINT;

int main()
{
	double** DP;
	DINT* pos;
	int icase;
	double ans;
	double tmp;
	double maxp;
	int times=0;
	int tmpi, tmpj;
	while (scanf("%d", &icase) && icase)
	{
		DP = (double**)malloc(sizeof(double*)*icase);
		for (int i = 0; i < icase; i++)
			*(DP + i) = (double*)malloc(sizeof(double) * icase);
		pos = (DINT*)malloc(icase * sizeof(DINT));
		for (int i = 0; i < icase; i++)
		{
			(*(pos + i)).xpos = -1;
			(*(pos + i)).ypos = -1;
		}
		for (int i = 0; i < icase; i++)
		{
			scanf("%d %d", &tmpi, &tmpj);
			(*(pos + i)).xpos = tmpi;
			(*(pos + i)).ypos = tmpj;
		}
		for (int i = 0; i < icase; i++)
		{
			for (int j = 0; j < icase; j++)
			{
				if ((*(pos + i)).xpos == -1)
					break;
				if ((*(pos + j)).xpos != -1)
				{
					DP[i][j] = sqrt(pow((double)((*(pos + j)).xpos) - ((double)((*(pos + i)).xpos)), 2) + pow((double)((*(pos + j)).ypos) - ((double)((*(pos + i)).ypos)), 2));
					DP[j][i] = DP[i][j];
				}
			}
		}


		//-----------
		/*
		puts("");
		for (int i = 0; i < icase; i++)
		{
			for (int j = 0; j < icase; j++)
			{
				cout << DP[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		*/
		//-----------



		for (int k = 0; k < icase; k++)
		{
			for (int j = 0; j < icase; j++)
			{
				for (int i = 0; i < icase; i++)
				{
					DP[i][j] = min(DP[i][j],DP[i][k] + DP[k][j]);
				}
			}
		}
		for (int k = 0; k < icase; k++)
		{
			for (int j = 0; j < icase; j++)
			{
				for (int i = 0; i < icase; i++)
				{
					tmp= max(DP[i][k], DP[k][j]);
					DP[i][j] = min(DP[i][j],tmp);
				}
			}
		}

		//---------------
		/*
		puts("");
		for (int i = 0; i < icase; i++)
		{
			for (int j = 0; j < icase; j++)
			{
				cout << DP[i][j]<<' ';
			}
			cout << endl;
		}
		puts("");
		*/
		//---------------

		times++;
		printf("Scenario #%d\nFrog Distance = %.3f\n", times, DP[0][1]);
		puts("");
	}
}