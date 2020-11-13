#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int map[500][500];
int visit[500][500];
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
class dot
{
	public:
		int x;
		int y;
		int len;
};
int BFS(int i,int j,int M)
{
	dot tmpdot;
	queue<dot>q;
	q.push({i,j,0});
	while(!q.empty())
	{
		if(map[q.front().x][q.front().y]==3)
			return q.front().len;
		visit[q.front().x][q.front().y]=1;
		for(int i=0;i<4;i++)
		{
			if(q.front().x+dir[i][0]>=0&&q.front().x+dir[i][0]<M&&q.front().y+dir[i][1]>=0&&q.front().y+dir[i][1]<M&&!visit[q.front().x+dir[i][0]][q.front().y+dir[i][1]])
				q.push({q.front().x+dir[i][0],q.front().y+dir[i][1],q.front().len+1});
		}
		q.pop();
	}
	return 0;
}
int main()
{
	int M,ans;
	char tmp;
	while(cin>>M)
	{
		ans=0;
		for(int i=0;i<M;i++)
			for(int j=0;j<M;j++)
			{
				cin>>tmp;
				map[i][j]=tmp-'0';
				visit[i][j]=0;
			}


		for(int i=0;i<M;i++)
			for(int j=0;j<M;j++)
			{
				if(map[i][j]==1)
					ans=max(ans,BFS(i,j,M));
				for(int x=0;x<M;x++)
					for(int y=0;y<M;y++)
						visit[x][y]=0;
			}

		cout<<ans<<endl;
	}

	return 0;
}