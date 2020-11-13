#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct elephant
{
	int weight;
	int IQ;
	int ID;
};
typedef struct elephant ELEPHANT;

bool cmp( ELEPHANT& A, ELEPHANT& B)
{
	if (A.weight != B.weight)
		return A.weight < B.weight;
	else
		return A.IQ>B.IQ;
}

void trace(int* prev, int index,ELEPHANT *elephants)
{
	if (prev[index] != -1)
		trace(prev, prev[index],elephants);
	cout << elephants[index].ID + 1<<endl;
}

int main()
{
	ELEPHANT elephants[1000];
	int num = 0;
	int len[1000];
	int prev[1000];
	int max, maxp;
	while (~scanf("%d %d", &(elephants[num].weight), &(elephants[num].IQ)))num++;
	for (int i = 0; i < num; i++)
		elephants[i].ID = i;
	sort(elephants, elephants + num, cmp);

	//----------------
	/*
	for (int i = 0; i < num; i++)
		printf("elephants[%d]  weight=%d   IQ=%d    ID=%d\n", i, elephants[i].weight, elephants[i].IQ,elephants[i].ID);
	*/
	//----------------
	for (int i = 0; i < num; i++)
	{
		len[i] = 1;
		prev[i] = -1;
	}



	for (int i = 0; i < num; i++)
		for (int j = i + 1; j < num; j++)
			if ((elephants[i].weight < elephants[j].weight) && (elephants[i].IQ > elephants[j].IQ))
				if (len[i] + 1 > len[j])
				{
					len[j] = len[i] + 1;
					prev[j] = i;
				}
	//-----------------------
	/*	
	for (int i = 0; i < num; i++)
		cout << "len[" << i << "]=" << len[i] << endl;
		*/
	//----------------------
	max = 0;
	for (int i = 0; i < num; i++)
	{
		if (len[i] > max)
		{
			max = len[i];
			maxp = i;
		}
	}

	cout << max << endl;
	trace(prev,maxp,elephants);
}