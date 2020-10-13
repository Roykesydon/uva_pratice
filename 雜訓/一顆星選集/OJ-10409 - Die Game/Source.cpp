#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int count;
	int mode;
	int dice[4][3];
	string tmp;
	while (cin >> count && count != 0)
	{
		dice[0][1] = 2;
		dice[1][0] = 3;
		dice[1][1] = 1;
		dice[1][2] = 4;
		dice[2][1] = 5;
		dice[3][1] = 6;
		for (int i = 0; i < count; i++)
		{
			mode = 0;
			cin >> tmp;
			if (!strcmp("north", tmp.c_str()))
				mode=1;
			if (!strcmp("south", tmp.c_str()))
				mode=2;
			if (!strcmp("east", tmp.c_str()))
				mode=3;
			if (!strcmp("west", tmp.c_str()))
				mode=4;

			switch (mode) 
			{
				case 1:
					swap(dice[0][1], dice[3][1]);
					swap(dice[0][1], dice[1][1]);
					swap(dice[1][1], dice[2][1]);
					break;
				case 2:
					swap(dice[0][1], dice[3][1]);
					swap(dice[3][1], dice[2][1]);
					swap(dice[1][1], dice[2][1]);
					break;
				case 3:
					swap(dice[3][1], dice[1][2]);
					swap(dice[1][2], dice[1][1]);
					swap(dice[1][0], dice[1][1]);
					break;
				case 4:
					swap(dice[3][1], dice[1][0]);
					swap(dice[1][0], dice[1][1]);
					swap(dice[1][1], dice[1][2]);
					break;
			}
		}
		cout << dice[1][1] << endl;
	}

	return 0;
}