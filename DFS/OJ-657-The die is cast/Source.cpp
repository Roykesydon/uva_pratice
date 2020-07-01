#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;

char** pic;
int w, h;
int dot;
int dices[6];
void dfs(int a, int b);
void Xdfs(int a, int b);


int main(void)
{

	int times=0;
	while (scanf("%d %d", &w, &h) && (w + h))
	{
		pic = (char**)malloc(h * sizeof(char*));
		for (int i = 0; i < h; i++)
			*(pic + i) = (char*)malloc(w* sizeof(char));
		times++;
		//if (times++ > 0)
		//	cout << endl;
		getchar();
		for (int i = 0; i < h; i++) 
		{
			for (int j = 0; j < w; j++)
				scanf(" %c", (*(pic + i) + j));
		}
		
		/*
		cout << endl;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				printf("%c", *(*(pic + i) + j));
			cout << endl;
		}
		*/
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (pic[i][j] == '*'|| pic[i][j] == 'X')
				{
					dot = 0;
					dfs(i, j);
					dices[dot - 1]++;
				}
			}
		}
		printf("Throw %d\n", times);
		int j = 0;
		for (int i = 0; i < 6; i++)
		{
			while (dices[i]--)
			{
				if (j++ > 0)
					cout << ' ';
				printf("%d", i + 1);
			}

		}
		puts("");
		puts("");
		for (int i = 0; i < 6; i++)
			dices[i] = 0;

		for (int i = 0; i < h; i++)
			free(*(pic + i));
		free(pic);

	}
	return 0;
}

void dfs(int a, int b)
{
	if(pic[a][b] = '*')
		pic[a][b] = '.';
	for (int dx = -1; dx < 2; dx++)
	{
		for (int dy = -1; dy < 2; dy++)
		{
			if ((dx + dy == -1 || dx + dy == 1) && ((a + dy >= 0 && a + dy < h) && (b + dx >= 0 && b + dx < w)))
			{

				if (pic[a + dy][b + dx] == '*')
					dfs(a + dy, b + dx);
				if (pic[a + dy][b + dx] == 'X')
				{
					dot++;
					Xdfs(a + dy, b + dx);
					dfs(a + dy, b + dx);
				}

			}
		}
	}
}
void Xdfs(int a, int b)
{
	pic[a][b] = '*';
	for (int dx = -1; dx < 2; dx++)
	{
		for (int dy = -1; dy < 2; dy++)
		{
			if ((dx + dy == -1 || dx + dy == 1) && ((a + dy >= 0 && a + dy < h) && (b + dx >= 0 && b + dx < w)))
			{
				if (pic[a + dy][b + dx] == 'X')
				{
					Xdfs(a + dy, b + dx);
				}
			}
		}
	}

}