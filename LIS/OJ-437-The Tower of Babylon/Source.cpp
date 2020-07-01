#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct block
{
	int x;
	int y;
	int height;
};
typedef struct block BLOCK;


void save_block(int* block_LWH, int tag, BLOCK* blocks);
void spin_block(int* block_LWH);
bool cmp(const BLOCK& a, const BLOCK& b);


int main()
{
	int casenum=0;
	int max;
	int block_LWH[3];
	int len[90];
	int difType;
	BLOCK blocks[90];

	while (scanf("%d", &difType) && difType)
	{
		int tag = 0;
		for (int i = 0; i < difType; i++)
		{
			scanf("%d %d %d", &block_LWH[0], &block_LWH[1], &block_LWH[2]);
			sort(block_LWH,block_LWH+3);
			save_block(block_LWH, tag,blocks);
			tag++;
			spin_block(block_LWH);
			save_block(block_LWH, tag,blocks);
			tag++;
			spin_block(block_LWH);
			save_block(block_LWH, tag,blocks);
			tag++;
		}
		sort(blocks, blocks + (difType * 3), cmp);
		for (int i = 0; i < difType*3; i++)
			len[i] = blocks[i].height;

		//--------------------------------
		/*
		for (int i = 0; i < difType * 3; i++)
			printf("block#%d %d %d     height=%d    len[%d]=%d\n", i, blocks[i].x, blocks[i].y, blocks[i].height,i,len[i]);
		*/
		//--------------------------------

		
		for (int i = 0; i < difType*3;i++)
		{
			for(int j=i+1;j<difType*3;j++)
				if (blocks[j].x > blocks[i].x&& blocks[j].y > blocks[i].y)
				{
					if (len[j] < len[i] + blocks[j].height)
					len[j] = len[i] + blocks[j].height;
				}
		}
		


		//--------------------------------
		/*
		for (int i = 0; i < difType * 3; i++)
			printf("len[%d]=%d\n", i, len[i]);
		*/
		//--------------------------------

		max = 0;
		for (int i = 0; i < difType * 3; i++)
			if (len[i] > max)
				max = len[i];

		printf("Case %d: maximum height = %d\n", ++casenum, max);
	}
	return 0;
}

void save_block(int* block_LWH, int tag,BLOCK* blocks)
{
	blocks[tag].x = block_LWH[0];
	blocks[tag].y = block_LWH[1];
	blocks[tag].height = block_LWH[2];
}

void spin_block(int* block_LWH)
{
	int tmp;
	tmp = block_LWH[0];
	block_LWH[0] = block_LWH[1];
	block_LWH[1] = block_LWH[2];
	block_LWH[2] = tmp;
	if (block_LWH[0] > block_LWH[1])
	{
		tmp = block_LWH[0];
		block_LWH[0] = block_LWH[1];
		block_LWH[1] = tmp;
	}
}


bool cmp(const BLOCK &a, const BLOCK &b)
{
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}