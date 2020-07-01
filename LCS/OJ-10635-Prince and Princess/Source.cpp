#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
	int testNum;
	int testCount;

	int n, p, q;

	int tmp, s2Count;
	int max;
	int *cmp;
	int *len;
	int *s1, *s2;
	cmp = (int*)malloc(sizeof(int) * 62501);
	len = (int*)malloc(sizeof(int) * 62501);
	s1 = (int*)malloc(sizeof(int) * 62501);
	s2 = (int*)malloc(sizeof(int) * 62501);
	scanf("%d", &testNum);
	for (testCount = 1; testCount <= testNum; testCount++)
	{
		//memset(flag, 0, sizeof(flag));
		//memset(cmp, 0, sizeof(cmp));
		for (int i = 0; i < 62501; i++)
			cmp[i] = 0;
		scanf("%d %d %d", &n, &p, &q);
		for (int i = 1; i <= p + 1; i++)
		{
			scanf("%d", &s1[i]);
			cmp[s1[i]] = i;
		}
		s2Count = 0;
		for (int i = 0; i < q + 1; i++)
		{
			scanf("%d", &tmp);
			if (cmp[tmp])
				s2[++s2Count] = tmp;
		}

		for (int i = 1; i <= s2Count; i++)
			len[i] = 1;

		for (int i = 1; i <= s2Count; i++)
			for (int j = i + 1; j <= s2Count; j++)
				if (cmp[s2[j]]>cmp[s2[i]])
					if (len[i] + 1 > len[j])
						len[j] = len[i] + 1;
		max = 0;
		for (int i = 1; i <= s2Count; i++)
			if (len[i] > max)
				max = len[i];

		cout << "Case " << testCount << ": " << max << endl;

	}
	return 0;
}