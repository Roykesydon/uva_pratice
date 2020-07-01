#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int repeat;
	scanf("%d", &repeat);
	double ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
	double ma, mb,ka,kb;
	double ansx, ansy;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while (repeat--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2);
		if (ay2 == ay1)//如果是水平線
			ma = 0;
		else if (ax1 == ax2)//如果a是垂直線
		{
			if (bx1 == bx2)//a垂直,b也垂直
			{
				if (ax1 == bx1)
					cout << "LINE" << endl;
				else
					cout << "NONE" << endl;

				/*
				printf("---------------------------------\n");
				printf("ma=%.2lf  mb=%.2lf\n", ma, mb);
				printf("ka=%.2lf  kb=%.2lf\n", ka, kb);
				printf("=================================\n");
				puts("");
				*/


				continue;
			}
			else//a垂直,b不垂直
			{
				if (by2 == by1)
					mb = 0;
				else
					mb = (by2 - by1) / (bx2 - bx1);
				kb = by1 - mb * bx1;
				ansx = ax1;
				ansy = ansx * mb + kb;
				printf("POINT %.2lf %.2lf\n", ansx, ansy);

				/*
				printf("---------------------------------\n");
				printf("ma=%.2lf  mb=%.2lf\n", ma, mb);
				printf("ka=%.2lf  kb=%.2lf\n", ka, kb);
				printf("=================================\n");
				puts("");
				*/

				continue;
			}
		}
		else
			ma = (ay2 - ay1) / (ax2 - ax1);
		if (by2 == by1)
			mb = 0;
		else if (bx1 == bx2)//如果b是垂直線
		{
			if (bx1 == ax1)//b垂直,a也垂直
			{
				if (bx1 == ax1)
					cout << "LINE" << endl;
				else
					cout << "NONE" << endl;

				/*
				printf("---------------------------------\n");
				printf("ma=%.2lf  mb=%.2lf\n", ma, mb);
				printf("ka=%.2lf  kb=%.2lf\n", ka, kb);
				printf("=================================\n");
				puts("");
				*/

				continue;
			}
			else//b垂直,a不垂直
			{
				if (ay2 == ay1)//如果是水平線
					ma = 0;
				else
					ma = (ay2 - ay1) / (ax2 - ax1);
				ka = ay1 - ma * ax1;
				ansx = bx1;
				ansy = ansx * ma + ka;
				printf("POINT %.2lf %.2lf\n", ansx, ansy);
				/*
				printf("---------------------------------\n");
				printf("ma=%.2lf  mb=%.2lf\n", ma, mb);
				printf("ka=%.2lf  kb=%.2lf\n", ka, kb);
				printf("=================================\n");
				puts("");
				*/

				continue;
			}
		}
		else
			mb = (by2 - by1) / (bx2 - bx1);
		//y=mx+k; k=y-mx;
		ka = ay1 - ma * ax1;
		kb = by1 - mb * bx1;
		if (ma == mb)
		{
			if (ka == kb)
				cout << "LINE" << endl;
			else
				cout << "NONE" << endl;
		}
		else
		{
			//y=m1*x+k1
			//y=m2*x+k2
			//(m1-m2)*x+(k1-k2)=0
			//x=(k1-k2)/(m1-m2)*(-1)
			ansx = (ka - kb) / (ma - mb)*(-1);
			ansy = ma * ansx + ka;
			printf("POINT %.2lf %.2lf\n", ansx,ansy);
		}
		/*
		printf("---------------------------------\n");
		printf("ma=%.2lf  mb=%.2lf\n", ma, mb);
		printf("ka=%.2lf  kb=%.2lf\n", ka, kb);
		printf("=================================\n");
		puts("");
		*/
	}
	cout << "END OF OUTPUT" << endl;




	return 0;
}