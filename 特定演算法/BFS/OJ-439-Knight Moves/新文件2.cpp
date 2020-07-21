#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct point{
	int x;
	int y;
	int pos;
};
int BFS(int sx,int sy,int ex,int ey )
{
	//char a;
	int ans;
	int move[8][2]={{1,2},{2,1},{-1,2},{-2,1},
					{1,-2},{-1,-2},{2,-1},{-2,-1}};
	queue<point>q;
	q.push({sx,sy,0});
	while(q.size())
	{
	//	a=sx+'a';
		//cout<<a<<sy+1<<' ';
		if(q.front().x==ex&&q.front().y==ey)
			break;
		for(int i=0;i<8;i++)
		{
			if((q.front().x+move[i][0]>=0&&q.front().x+move[i][0]<8)&&(q.front().y+move[i][1]>=0&&q.front().y+move[i][1]<8))
				q.push({q.front().x+move[i][0],q.front().y+move[i][1],q.front().pos+1});
		}
		q.pop();
	}
	return q.front().pos;
}
int main()
{
	int ans;
	string s1,s2;
	int sx,sy,ex,ey;
	while(cin>>s1>>s2)
	{
		sx=s1[0]-'a';
		sy=s1[1]-'1';
		ex=s2[0]-'a';
		ey=s2[1]-'1';
		ans=BFS(sx,sy,ex,ey);
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<ans<<" knight moves.\n";


	}
	
	
	return 0;
}
