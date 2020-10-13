#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int tmp;
	int num1, num2;
	int ans;
	int cursum=0;
	int* DP;
	int* DPsum;
	DP = (int*)malloc(sizeof(int) * 1000001);
	for (int i = 0; i < 1000001; i++)
		DP[i] = 2;
	DPsum = (int*)malloc(sizeof(int) * 1000001);

	for (int i = 4; i <= 1000000; i += 2)
		DP[i] = 0;

	DP[0] = 0;
	DP[1] = 0;
	for (int i = 3; i <= 1000000; i += 2)
	{
		if (DP[i] == 2)
		{
			tmp = i;
			tmp += i;
			while(tmp <= 1000000)
			{
				DP[tmp] = 0;
				tmp += i;
			}
		}
	}
	//-------------------------琌р獶借计常эΘ0
		ans = 0;
		int count = 1000;
		for (int i = 0; i <= 1000000; i++)
		{
			if (DP[i] == 1)
				cursum++;
			else if (DP[i] == 2)
			{
				tmp = i;
				int check = 1;
				//ex:986 count=1000
				while (i / count != 0)
					count *= 10;
				for (int j = 10; j < count; j *= 10)//近瑈传计竚絋粄
				{
					int highest;
					highest = tmp / (count / 10);
					tmp = tmp % (count / 10);
					tmp *= 10;
					tmp += highest;
					if (DP[tmp] == 0)
					{
						tmp = i;
						check = 1;
						for (int j = 10; j < count; j *= 10)
						{
							tmp = tmp / count * 10 + 10 * (tmp % (count / 10));
							if (tmp / count * 10 != 0)
								DP[tmp] = 0;
						}
						DP[i] = 0;
						check = 0;
						break;
					}

				}
				if (check == 1)
				{
					tmp = i;
					for (int j = 10; j < count; j *= 10)
					{
						tmp = tmp / count * 10 + 10 * (tmp % (count / 10));
						if (tmp / count * 10 != 0)
							DP[tmp] = 1;
					}
					DP[i] = 1;
					cursum++;
					//printf("Circular Number: %d\n", i);
				}
			}
			DPsum[i] = cursum;
		}
		while (scanf("%d", &num1) && num1 != -1)
		{
			scanf("%d", &num2);
			if (DPsum[num2] - DPsum[num1 - 1] == 0)
				printf("No Circular Primes.\n");
			else if (DPsum[num2] - DPsum[num1 - 1] == 1)
				printf("1 Circular Prime.\n");
			else
				printf("%d Circular Primes.\n", DPsum[num2] - DPsum[num1 - 1]);
		}


	free(DP);
	free(DPsum);
	return 0;
}