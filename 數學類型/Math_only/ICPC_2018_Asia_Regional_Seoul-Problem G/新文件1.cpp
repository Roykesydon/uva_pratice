#include <bits/stdc++.h>
using namespace std;
#define ERR 1e-9
#define ll long long
vector<ll> vec;
vector<vector<double>> arr;
class cmp
{
public:
	bool operator()(int a, int b) //f
	{
		double tmp;
		double ans1 = 0, ans2 = 0;
		int other;
		for (int i = 1; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				// other=6-i-j;
				// tmp = (arr[a][i] / arr[a][0] * arr[a][j] / arr[a][0]) * (arr[a][other]/arr[a][0]*(arr[a][j] / arr[a][0]) + arr[a][other]/arr[a][0]*(arr[a][i] / arr[a][0]));
				tmp = arr[a][i] / arr[a][0] * (arr[a][0] - arr[a][i]) / arr[a][0] * arr[a][j] / arr[a][0]; //好算的先處理 i在等待時間後的機率*B落在等待時間的機率*C落在B的機率
				tmp += arr[a][j] / arr[a][0] * (arr[a][0] - arr[a][j]) / arr[a][0] * arr[a][i] / arr[a][0];
				ans1 += tmp;
			}
		}
		swap(a, b);
		for (int i = 1; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				// other=6-i-j;
				// tmp = (arr[a][i] / arr[a][0] * arr[a][j] / arr[a][0]) * (arr[a][other]/arr[a][0]*(arr[a][j] / arr[a][0]) + arr[a][other]/arr[a][0]*(arr[a][i] / arr[a][0]));
				tmp = arr[a][i] / arr[a][0] * (arr[a][0] - arr[a][i]) / arr[a][0] * arr[a][j] / arr[a][0]; //好算的先處理 i在等待時間後的機率*B落在等待時間的機率*C落在B的機率
				tmp += arr[a][j] / arr[a][0] * (arr[a][0] - arr[a][j]) / arr[a][0] * arr[a][i] / arr[a][0];
				ans2 += tmp;
			}
		}
		swap(a, b);
		if (abs(ans1 - ans2) < ERR)
			return a < b;
		return ans1 < ans2;
	}
};
int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i].resize(4);
	for (int i = 0; i < n; i++)
	{
		vec.push_back(i);
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}

	sort(vec.begin(), vec.end(), cmp());
	for (auto i : vec)
		cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}
