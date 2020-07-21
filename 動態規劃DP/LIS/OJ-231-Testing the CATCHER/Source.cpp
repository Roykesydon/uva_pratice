#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int* missile;
	int MissileNum;
	int casenum=0;
	int* len;
	int max;
	missile = (int*)malloc(sizeof(int)*100000);
	len = (int*)malloc(sizeof(int) * 100000);
	while (scanf("%d", &missile[0]) && missile[0] != -1)
	{
		MissileNum = 1;
		while (scanf("%d", &missile[MissileNum]) && missile[MissileNum] != -1)
			MissileNum++;
		//----------------------
		/*
		for (int i = 0; i < MissileNum; i++)
			printf("%d ", missile[i]);
		*/
		//----------------------
		for (int i = 0; i < MissileNum; i++)
			len[i] = 1;

		for (int i = 0; i < MissileNum; i++)
			for (int j = i + 1; j < MissileNum; j++)
				if (missile[j] < missile[i])
					if (len[i] + 1 > len[j])
						len[j] = len[i] + 1;

		max = 0;
		for (int i = 0; i < MissileNum; i++)
			if (len[i] > max)
				max = len[i];

		if (++casenum > 1)
			cout << endl;
		cout << "Test #" << casenum << ":" << endl;
		cout << "  maximum possible interceptions: " << max << endl;

	}




	return 0;
}