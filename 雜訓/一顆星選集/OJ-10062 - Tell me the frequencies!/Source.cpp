#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct alphabet
{
	int ID;
	int num;
};
typedef struct alphabet ALPHA;

bool cmp(const ALPHA& a,const ALPHA& b)
{
	if (a.num != b.num)
	{
		if (b.num == 0||a.num==0)
			return a.num > b.num;
		else
			return a.num < b.num;
	}
	else
		return a.ID > b.ID;
}

int main()
{
	int CaseCount=0;
	ALPHA num[128];
	int i;
	string tmp;
	while (getline(cin,tmp))
	{
		for (int i = 0; i < 128; i++)
			num[i].num = 0;
		for (int i = 0; i < 128; i++)
			num[i].ID = i;

		for (int i = 0; i < strlen(tmp.c_str()); i++)
			(num[*(tmp.c_str() + i)].num)++;

		sort(num, num + 128, cmp);
		if (CaseCount++)
			cout << endl;

		i = 0;
		while (num[i++].num != 0)
			cout << num[i-1].ID << ' ' << num[i - 1].num << endl;
	}
	
}