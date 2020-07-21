#include<iostream>
using namespace std;
int main()
{
	int caseCount;
	int card[5][5];
	int flag[5][5];
	int ans[75];
	int sum = 0;
	int detect;
	int count;
	cin >> caseCount;
	while (caseCount--)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (i == 2 && j == 2)
					continue;
				else
					cin >> card[i][j];
		for (int i = 0; i < 75; i++)
			cin >> ans[i];


		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				flag[i][j] = 0;
		flag[2][2] = 1;

		for (int k = 0; k < 75; k++)
		{
			for(int i=0;i<5;i++)
				for (int j = 0; j < 5; j++)
					if (card[i][j] == ans[k])
					{
						flag[i][j] = 1;
						break;
					}
			
			detect = 0;
			for (int i = 0; i < 5; i++)
				if (flag[i][0] + flag[i][1] + flag[i][2] + flag[i][3] + flag[i][4] == 5)
					detect = 1;
				else if (flag[0][i] + flag[1][i] + flag[2][i] + flag[3][i] + flag[4][i] == 5)
					detect = 1;
			sum = 0;
			for (int i = 0; i < 5; i++)
				sum += flag[i][i];
			if (sum == 5)
				detect = 1;
			sum = 0;
			for (int i = 0; i < 5; i++)
				sum += flag[i][4 - i];
			if (sum == 5)
				detect = 1;
			
			if (detect == 1)
			{
				count = k;
				break;
			}
		}
		cout << "BINGO after " << count+1 << " numbers announced\n";
	}
	return 0;
}