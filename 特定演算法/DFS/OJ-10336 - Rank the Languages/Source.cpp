#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef struct alphanum
{
	int num;
	char letter;
}ALPHANUM;

void dfs(ALPHANUM* alphabetNum,char**map,int i,int j ,char theLetter,int H,int W)
{
	map[i][j] = '#';
	int q, k;
	q = -1; k = 0;
	if ((i + q >= 0 && i + q < H) && (j + k < W && j + k >= 0))
		if (map[i + q][j + k] == theLetter)
			dfs(alphabetNum, map, i + q, j + k, theLetter, H, W);
	q = 0; k = -1;
	if ((i + q >= 0 && i + q < H) && (j + k < W && j + k >= 0))
		if (map[i + q][j + k] == theLetter)
		dfs(alphabetNum, map, i + q, j + k, theLetter, H, W);
	q = 1; k = 0;
	if ((i + q >= 0 && i + q < H) && (j + k < W && j + k >= 0))
		if (map[i + q][j + k] == theLetter)
		dfs(alphabetNum, map, i + q, j + k, theLetter, H, W);
	q = 0; k = 1;
	if ((i + q >= 0 && i + q < H) && (j + k < W && j + k >= 0))
		if (map[i + q][j + k] == theLetter)
		dfs(alphabetNum, map, i + q, j + k, theLetter, H, W);
}
bool cmp(ALPHANUM a, ALPHANUM b)
{
	if (a.num != b.num)
		return a.num > b.num;
	else
		return a.letter < b.letter;
}
int main()
{
	int caseNum=1;
	int caseSum;
	ALPHANUM alphabetNum[26];
	char **map;
	map = (char**)malloc(sizeof(char*) * 1000);
	for (int i = 0; i < 1000; i++)
		*(map + i) = (char*)malloc(sizeof(char) * 1000);

	scanf("%d", &caseSum);
	while (caseNum<=caseSum)
	{
		int H, W;
		scanf("%d %d ", &H, &W);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin>>map[i][j];

		for (int i = 0; i < 26; i++)
		{
			alphabetNum[i].num = 0;
			alphabetNum[i].letter = i + 'a';
		}

		//-----------------------
		/*
		puts("");
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cout << map[i][j];
			puts("");
		}
		puts("");
		*/
		//------------------------

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] >= 'a' && map[i][j] <= 'z')
				{
					(alphabetNum[map[i][j] - 'a'].num)++;
					dfs(alphabetNum, map, i, j,map[i][j],H,W);
				}
			}
		}

		//-----------------------
		/*
		puts("");
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cout << map[i][j];
			puts("");
		}
		puts("");
		*/
		//------------------------
		sort(alphabetNum, alphabetNum + 26, cmp);
		cout << "World #" << caseNum++<<endl;
		for (int i = 0; i < 26; i++)
		{
			if (alphabetNum[i].num == 0)
				break;
			cout << alphabetNum[i].letter << ": " << alphabetNum[i].num << endl;
		}
	}

	return 0;
}