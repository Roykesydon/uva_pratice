#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int P, R;
	int s1index, s2index;
	int count,flag;
	char** people;
	int** DP;
	int caseCount=1;
	DP = (int**)malloc(sizeof(int*) * 51);
	for (int i = 0; i < 51; i++)
		*(DP + i) = (int*)malloc(sizeof(int) * 51);

	people = (char**)malloc(sizeof(char*) * 51);
	for (int i = 0; i < 51; i++)
		*(people + i) = (char*)malloc(sizeof(char) * 100);

	while (cin >> P >> R&&(P||R))
	{


		string s1, s2;
		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 100; j++)
				people[i][j] = '\0';
		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 51; j++)
				DP[i][j] = 999999999;
		for (int i = 0; i < P; i++)
			DP[i][i] = 0;
		count = 0;
		for (int i = 0; i < R; i++)
		{
			cin >> s1 >> s2;
			flag = 0;
			for (int i = 0; i < count; i++)
			{
				if (strcmp(s1.c_str(), *(people + i)) == 0)
				{
					s1index = i;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				strcpy(*(people + count++), s1.c_str());
				s1index = count - 1;
			}
			flag = 0;
			for (int i = 0; i < count; i++)
			{
				if (strcmp(s2.c_str(), *(people + i)) == 0)
				{
					s2index = i;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				strcpy(*(people + count++), s2.c_str());
				s2index = count - 1;
			}

			DP[s1index][s2index] = 1;
			DP[s2index][s1index] = 1;
		}
		for (int k = 0; k < P; k++)
			for (int i = 0; i < P; i++)
				for (int j = 0; j < P; j++)
					DP[i][j] = min(DP[i][j],DP[i][k] + DP[k][j]);

		int tmpmax = 0;
		for (int i = 0; i < P; i++)
			for (int j = 0; j < P; j++)
				tmpmax = max(DP[i][j], tmpmax);
		
		/*
		cout << P << ' ' << R << endl;
		for (int i = 0; i < P; i++)
			cout << *(people + i)<<' ';
		*/
		if (tmpmax != 999999999)
			cout << "Network " << caseCount++ << ": " << tmpmax << endl<<endl;
		else
			cout << "Network " << caseCount++ << ": " << "DISCONNECTED" << endl << endl;
	} 
	
	

	return 0;
}