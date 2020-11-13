#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

void trace(int j, int* prev, int* tag, int last);
int main()
{

	int k, n;
	int box[30][10];
	int len[30];
	int max;
	int maxp;
	int prev[30];
	int sum[30];
	int tmp;
	int tag[30];


	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 10; j++)
			box[i][j] = 0;


	while (cin >> k >> n)
	{
		for (int i = 0; i < k; i++)		/*輸入箱子，並且每箱都順便把邊長由小到大sort好*/
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &box[i][j]);
			}
			tag[i] = i;					/*把每個箱子也都編上自己的編號，因為之後會再依各個箱子的邊長總和排序，會打亂，所以要記錄本來的位子*/
			sort(box[i], box[i] + n);
		}


		for (int i = 0; i < k; i++)		/*初始化*/
			len[i] = 1;
		for (int i = 0; i < k; i++)
			prev[i] = -1;
		for (int i = 0; i < k; i++)
			sum[i] = 0;


		for (int i = 0; i < k; i++)		/*紀錄每個箱子的邊長總和*/
			for (int j = 0; j < n; j++)
				sum[i] += box[i][j];


		for (int i = 0; i < k; i++)		/*依照每個箱子的邊長總和排序，對調位子時也會一併把tag(原本的位子)還有箱子各個邊長的資訊都對調*/
			for (int j = i + 1; j < k; j++)
			{
				if (sum[j] < sum[i])
				{
					tmp = sum[i];
					sum[i] = sum[j];
					sum[j] = tmp;
					for (int g = 0; g < n; g++)
					{
						tmp = box[i][g];
						box[i][g] = box[j][g];
						box[j][g] = tmp;
					}
					tmp = tag[i];
					tag[i] = tag[j];
					tag[j] = tmp;
				}
			}


		for (int i = 0; i < k; i++)							
			for (int j = i+1; j < k; j++)
			{
				//if (i != j)
				//{
					int check = 1;
					for (int g = 0; g < n; g++)
					{
						if (box[i][g] >= box[j][g])			//如果j不能接在i後面
						{
							//printf("box[%d][%d] > box[%d][%d]\n", i, g, j, g);
							check = 0;
							break;
						}
					}
					if ((check == 1) && (len[i] + 1 > len[j]))	//如果j可以接在i後面
					{
						//printf("len[j] = %d , len[i] + 1 = %d;\n", len[j], len[i] + 1);
						len[j] = len[i] + 1;
						prev[j] = i;
					}
				//}
			}

		max = 0;
		maxp = 0;
		for (int i = 0; i < k; i++)
			if (len[i] > max)
			{
				maxp = i;
				max = len[i];
			}

		//puts("");
		cout << max << endl;
		trace(maxp, prev, tag, 1);
		/*
		puts("");
		for (int i = 0; i < k; i++)
			cout << len[i] << " ";
		puts("");
		puts("");
		*/
	}

	return 0;
}

void trace(int j, int* prev, int* tag, int last)
{
	if (*(prev + j) != -1)
		trace(*(prev + j), prev, tag, 0);
	cout << tag[j] + 1;
	if (last)
		puts("");
	else
		cout << ' ';
	return;
}