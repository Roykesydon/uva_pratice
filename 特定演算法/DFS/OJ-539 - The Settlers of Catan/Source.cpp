#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

void DFS(int DP[][25], int len,int &max,int node,int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (DP[node][i] == 1)
		{
			DP[node][i] = 2;
			DP[i][node] = 2;

			if (len + 1 > max)
				max = len + 1;

			DFS(DP, len + 1, max, i, n);
			DP[node][i] = 1;
			DP[i][node] = 1;
		}

}

int main(void)
{
	int n, m;
	int max;
	int tmp;
	int DP[25][25];
	int maybeMax[25];
	int node_1, node_2;
	int INF = 9999999;
	while (scanf("%d %d", &n, &m) && (n || m))
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				DP[i][j] = INF;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &node_1, &node_2);
			DP[node_1][node_2] = 1;
			DP[node_2][node_1] = 1;
		}
		for (int i = 0; i < n; i++)
			DP[i][i] = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			tmp = 0;
			DFS(DP, 0, tmp, i,n);
			//cout << "DFSnode#" << i << " : tmp=" << tmp << endl;
			if (tmp > max)
				max = tmp;
			/*
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (DP[i][j] ==2)
						DP[i][j] = 1;
			*/
		}


		cout << max << endl;
		//---------------------------------------------------
		/*
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				for (int i = 0; i < n; i++)
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
		*/
		//----------------------------------------------------

		//---------------------------------
		/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%10d",DP[i][j]);
			cout << endl;
		}
		*/
		//----------------------------------
	}


	return 0;
}