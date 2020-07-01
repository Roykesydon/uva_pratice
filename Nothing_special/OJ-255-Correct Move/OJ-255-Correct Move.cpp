#include<iostream>
using namespace std;
int main()
{
	int k,q,d,ans;
	int ki,qi,kj,qj,di,dj,tmpi,tmpj;
	while(cin>>k>>q>>d)	
	{
		ki=k/8;
		kj=k%8;
		qi=q/8;
		qj=q%8;
		di=d/8;
		dj=d%8;
		ans=4;
		if(q==k)
			ans=1;
		else if(qi==di&&qj==dj)
			ans=2;
		else if(qi==di||qj==dj)
		{
			if(qi==di)
			{
				if(((qj<kj&&kj<=dj)&&qi==ki)||((qj>kj&&kj>=dj)&&qi==ki))
					ans=2;
			}
			else if(qj==dj)
			{
				if(((qi<ki&&ki<=di)&&qj==kj)||((qi>ki&&ki>=di)&&qj==kj))
					ans=2;
			}
			tmpi=di-ki;
			tmpj=dj-kj;
			if(ans!=2)
				if((dj==kj&&(tmpi==1||tmpi==-1))||(di==ki&&(tmpj==1||tmpj==-1)))
					ans=3;
			if(ans==4)
				if((k==0&&d==9)||(k==7&&d==14)||(k==56&&d==49)||(k==63&&d==54))
					ans=5;
		}
		else
			ans=2;
		
		switch(ans)
		{
			case 1:
				cout<<"Illegal state\n";
				break;
			case 2:
				cout<<"Illegal move\n";
				break;
			case 3:
				cout<<"Move not allowed\n";
				break;
			case 4:
				cout<<"Continue\n";
				break;
			case 5:
				cout<<"Stop\n";
				break;
		}
	} 
	return 0;
} 
