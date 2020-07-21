#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void chop(int start, int end);
char a[26] = { 0 }, b[26] = { 0 };
int index;

int main()
{
	int len;
	while (scanf("%s %s", a, b) != EOF)
	{
		index = 0;
		len = 0;
		for (int i = 0; i < 26; i++)
		{
			if (a[i] == 0)
				break;
			len++;
		}

		chop(0, len-1);
		puts("");
		for (int i = 0; i < 26; i++)
		{
			a[i] = 0;
			b[i] = 0;
		}
	}
	return 0;
}

void chop(int start, int end)
{
		for (int j = start; j <= end; j++)
		{
			if (a[index] == b[j])
			{
				
				if (start <= j - 1)
				{
					index++;
					chop(start, j - 1);
				}
				if (j + 1 <= end)
				{
					index++;
					chop(j + 1, end);
				}

				printf("%c", b[j]);

				break;
			}
		}
		
}