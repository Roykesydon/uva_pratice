#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<algorithm>	//min()
#include<sstream>	//stringstream
#include<string>	//getline(cin,s1)
using namespace std;

int main()
{
	int** DP;
	int tmp;
	int tmpi, tmpj;
	int* fire_pos;
	int icase;
	string s1;
	int npos, npos_index;
	int times=0;
	int tmpmin;
	int tmpmax;
	stringstream ss;
	int num_fire, num_intersection;
	scanf("%d", &icase);
	while (icase--)
	{
		if (times++)
			puts("");
		npos = 999999999;
		npos_index = 0;
		tmpmax = 0;
		scanf("%d %d", &num_fire, &num_intersection);
		DP = (int**)malloc(sizeof(int*) * num_intersection);
		for(int i=0;i<num_intersection;i++)
			*(DP+i)= (int*)malloc(sizeof(int) * num_intersection);
		fire_pos = (int*)malloc(sizeof(int) * num_intersection);

		for (int i = 0; i < num_intersection; i++)
			for (int j = 0; j < num_intersection; j++)
				*(*(DP + i) + j) = 999999999;
		for (int i = 0; i < num_intersection; i++)
			*(fire_pos + i) = 0;

		for (int i = 0; i < num_fire; i++)
		{
			scanf("%d", &tmp);
			fire_pos[tmp - 1] = 1;
		}
		/*
		if (1 == num_intersection)
		{
			cout << 1 << endl;
			for (int i = 0; i < num_intersection; i++)
				free(*(DP + i));
			free(DP);
			free(fire_pos);
			continue;
		}
		*/
		getchar();
		while (getline(cin, s1)&&!(s1.empty()))
		{
			ss.str(""); //****important
			ss << s1;
			ss >> tmpi >> tmpj >> tmp;
			ss.clear(); //****important
			s1.clear(); 

			//scanf("%d %d %d", &tmpi, &tmpj, &tmp);
			DP[tmpi-1][tmpj-1] = tmp;
			DP[tmpj-1][tmpi-1] = tmp;
		}
		for (int i=0; i < num_intersection; i++)
			DP[i][i] = 0;
		//-------т翴翴程祏隔畖-------------
		for (int k = 0; k < num_intersection; k++)
			for (int i = 0; i < num_intersection; i++)
				for (int j = 0; j < num_intersection; j++)
					DP[i][j] = min(DP[i][j], DP[i][k]+ DP[k][j]);
		//--------------------------------------------
		//---------程祏禯瞒--------		
		/*
		puts("");
		for (int i = 0; i < num_intersection; i++)
		{
			for (int j = 0; j < num_intersection; j++)
				printf("%3d ", DP[i][j]);
			puts("");
		}
		*/
		//---------------------------
		for (int i = 0; i < num_intersection; i++) //–intersection常穝ňЫ
		{
			//tmp = 0;
			tmpmax = 0;
			if (fire_pos[i] == 1)
				continue;
			fire_pos[i] = 1;
			for (int j = 0; j < num_intersection; j++)	//代赣–intersection禯瞒
			{
				tmpmin = 99999999;
				for (int k = 0; k < num_intersection; k++)
				{
					if (fire_pos[k] == 1)
					{
						tmpmin = min(tmpmin, DP[j][k]);  //т赣intersection程ňЫ程祏禯瞒
					}
				}
				tmpmax = max(tmpmax, tmpmin);//т程穦琌ぶ
				//tmp = min(tmp, tmpmin);
				
			}
			//printf("\n%d腹砞穝ňЫ瞒程ňЫ程禯瞒%d\n", i+1, tmpmax);
			if (tmpmax < npos)
			{
				npos = tmpmax;
				npos_index = i;
			}
			fire_pos[i] = 0;
		}
		printf("%d\n", npos_index+1);
		//--------------------------------------
		for (int i = 0; i < num_intersection; i++)
				free(*(DP + i));
		free(DP);
		free(fire_pos);
		
	}
	return 0;
}