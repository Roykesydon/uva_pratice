#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

int dfs(char* ans, int *ans_index, int ans_auth)
{
	int tmpsum=0;
	for(int i=0;i<4;i++)
	{
		if (ans[*ans_index] == 'p')
		{
			(*ans_index)++;
			tmpsum += dfs(ans, ans_index, ans_auth / 4);
		}
		else
		{
			if (ans[*ans_index] == 'f')
			{
				tmpsum += ans_auth;
			}
			(*ans_index)++;
		}
	}
	return tmpsum;
}
int main()
{
	int N;
	int s1_index;
	int count;
	int s2_index;
	int ans_index;
	int sum;
	int ans_auth;
	char s1[2500], s2[2500], ans[2500];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < 2500; i++)
		{
			s1[i] = '\0';
			s2[i] = '\0';
			ans[i] = '\0';
		}
		scanf("%s", s1);
		scanf("%s", s2);
		s1_index = 0;
		s2_index = 0;
		ans_index = 0;

		while (s1[s1_index] != '\0' && s2[s2_index] != '\0')
		{
			if (s1[s1_index] == 'p' && s2[s2_index] == 'p')	//皆進入下一層 
			{
				s1_index++;
				s2_index++;
				ans[ans_index++] = 'p';
			}
			else if (s1[s1_index] == 'p' && s2[s2_index] != 'p')
			{
				if (s2[s2_index] == 'f')
				{
					ans[ans_index++] = 'f';
					s1_index++;
					count = 0;
					while (count != 4)
					{
						if (s1[s1_index++] != 'p')
							count++;
						else if (s1[s1_index] == 'p')
							count = 0;
					}
				}
				else
				{
					ans[ans_index++] = 'p';
					s1_index++;
					count = 0;
					while (count != 4)
					{
						if (s1[s1_index] != 'p')
							count++;
						else if (s1[s1_index] == 'p')
							count = 0;
						ans[ans_index++] = s1[s1_index++];
					}
				}
				s2_index++;
			}
			else if (s1[s1_index] != 'p' && s2[s2_index] == 'p')
			{
				if (s1[s1_index] == 'f')
				{
					ans[ans_index++] = 'f';
					s2_index++;
					count = 0;
					while (count != 4)
					{
						if (s2[s2_index++] != 'p')
							count++;
						else if (s2[s2_index] == 'p')
							count = 0;
					}
				}
				else
				{
					ans[ans_index++] = 'p';
					s2_index++;
					count = 0;
					while (count != 4)
					{
						if (s2[s2_index] != 'p')
							count++;
						else if (s2[s2_index] == 'p')
							count = 0;
						ans[ans_index++] = s2[s2_index++];
					}
				}
				s1_index++;
			}
			else if (s1[s1_index] != 'p' && s2[s2_index] != 'p')
			{
				if (s1[s1_index] == 'f' || s2[s2_index] == 'f')
					ans[ans_index++] = 'f';
				else
					ans[ans_index++] = 'e';

				s1_index++;
				s2_index++;
			}			
		}
		//printf("%s\n", ans);
		ans_auth = 1024;
		ans_index = 1;
		if (ans[0] == 'p')
			sum = dfs(ans, &ans_index, ans_auth / 4);
		else
		{
			if (ans[0] == 'f')
				sum = 1024;
			else
				sum = 0;
		}
		printf("There are %d black pixels.\n", sum);
	}

	return 0;
}
