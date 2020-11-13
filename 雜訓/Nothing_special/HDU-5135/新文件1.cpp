#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	double ans;
	while (cin >> n && n)
	{
		ans=0;
		arr.clear();
		arr.resize(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		while (true)
		{
			if (arr.size() < 3)
				break;
			if(arr[arr.size() - 1] < arr[arr.size() - 2] + arr[arr.size() - 3])
			{
				double a = arr[arr.size() - 1];
				double b = arr[arr.size() - 2];
				double c = arr[arr.size() - 3];
				double s = (a + b + c) / 2.0;
				ans+=sqrt(s * (s - a) * (s - b) * (s - c)) ;
				for(int i=0;i<3;i++)
					arr.pop_back();
			}
			else
				arr.pop_back();
		}
		cout <<fixed<<setprecision(2)<< ans<< '\n';
	}
}
