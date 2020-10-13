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
		for (int i = 0; i < k; i++)		/*��J�c�l�A�åB�C�c�����K������Ѥp��jsort�n*/
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &box[i][j]);
			}
			tag[i] = i;					/*��C�ӽc�l�]���s�W�ۤv���s���A�]������|�A�̦U�ӽc�l������`�M�ƧǡA�|���áA�ҥH�n�O�����Ӫ���l*/
			sort(box[i], box[i] + n);
		}


		for (int i = 0; i < k; i++)		/*��l��*/
			len[i] = 1;
		for (int i = 0; i < k; i++)
			prev[i] = -1;
		for (int i = 0; i < k; i++)
			sum[i] = 0;


		for (int i = 0; i < k; i++)		/*�����C�ӽc�l������`�M*/
			for (int j = 0; j < n; j++)
				sum[i] += box[i][j];


		for (int i = 0; i < k; i++)		/*�̷ӨC�ӽc�l������`�M�ƧǡA��զ�l�ɤ]�|�@�֧�tag(�쥻����l)�٦��c�l�U���������T�����*/
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
						if (box[i][g] >= box[j][g])			//�p�Gj���౵�bi�᭱
						{
							//printf("box[%d][%d] > box[%d][%d]\n", i, g, j, g);
							check = 0;
							break;
						}
					}
					if ((check == 1) && (len[i] + 1 > len[j]))	//�p�Gj�i�H���bi�᭱
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