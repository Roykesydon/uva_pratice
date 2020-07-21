#include<iostream>
#include<algorithm>
using namespace std;
int arr[60000];
int n, k;
bool check(int d)//greedy 
{
	int i = 0,tmp,cnt=1;

	while (i < n)
	{
		//cout << "i="<<i << endl;
		tmp = arr[i] + d;
		while (i < n && arr[i] <= tmp)
			i++;
		if (i == n&&cnt<=k)
			return true;
		if (cnt > k)
			return false;
		cnt++;
	}


}
int main()
{

	cin >> n >> k;
	int l, r,mid;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	l = 0;
	r = arr[n - 1]-arr[0];
	mid = (l + r) / 2;
	while (l < r)
	{
		if (check(mid))
		{
			//cout <<"mid="<< mid << endl;
			r = mid;
			mid = (l + r) / 2;
		}
		else
		{
			l = mid+1;
			mid = (l + r) / 2;
		}
	}
	cout << mid << endl;
	

	return 0;
}
