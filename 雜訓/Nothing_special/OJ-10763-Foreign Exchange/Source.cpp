#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,j,k;
	int round;
	int ans = 1;

	//int place1[500000] = { 0 }, place2[500000] = { 0 };
	int* place1, * place2;
	place1 = (int*)calloc(500000, sizeof(int));
	place2 = (int*)calloc(500000, sizeof(int));


	while (scanf("%d", &round))
	{
		if (round == 0)
			break;
		ans = 1;
		for (i = 0; i < round; i++)
		{
			scanf("%d %d", &(place1[i]),&(place2[i]));
		}
		sort(place1, place1 + round);
		sort(place2, place2 + round);
		for (int i = 0; i < round; i++)
		{
			if (place1[i] != place2[i])
			{
				ans = 0;
				break;
			}
		}
		if (ans == 1)
			printf("YES\n");
		else
			cout << "NO"<<endl;

	}
	return 0;
}