#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
int main(void)
{
	int round;
	int M, N;
	int* A,*u;
	int times;
	int j;
	scanf("%d", &round);
	priority_queue<int, vector<int>, less<int> > a;
	priority_queue<int, vector<int>, greater<int> > b;
	while (round--)
	{
		times = 0;
		scanf("%d %d", &M, &N);
		A = (int*)malloc(sizeof(int) * M);
		u = (int*)malloc(sizeof(int) * N);
		for (int i = 0; i < M; i++)
			scanf("%d", &(A[i]));
		for(int i=0;i<N;i++)
			scanf("%d", &(u[i]));
		j = 0;
		for (int i = 0; i < M; i++)
		{
			a.push(A[i]);
			b.push(a.top());
			a.pop();
			
			while (((a.size())+(b.size()))==u[j])
			{
				cout << b.top() << endl;
				a.push(b.top());
				b.pop();
				j++;
				if (j == N)
					j = 0;
			}
		}
		if (round)
			cout << endl;
		while (!(a.empty()))
			a.pop();
		while (!(b.empty()))
			b.pop();
	}
	return 0;
}