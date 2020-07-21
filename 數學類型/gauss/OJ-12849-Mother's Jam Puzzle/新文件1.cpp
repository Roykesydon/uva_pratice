#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> arr;
void gauss()
{
	int x = 0, y = 0;
	while (x < 3 && y < 4)
	{
		/*
		cout << '\n';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/

		if (-0.000001 < arr[x][y] && arr[x][y] < 0.000001)
		{
			for (int i = 0; i < 3; i++)
			{
				if (-0.000001 > arr[i][y] || arr[i][y] > 0.000001)
				{
					for (int j = 0; j < 4; j++)
						swap(arr[x][j], arr[i][j]);
				}
			}
		}

		double tmp = arr[x][y];
		for (int k = 0; k < 4; k++)
			arr[x][k] /= tmp;
		arr[x][y] = 1;
		for (int j = 0; j < 3; j++)
		{
			if (x == j)
				continue;
			tmp = arr[j][y];
			for (int k = 0; k < 4; k++)
				arr[j][k] -= tmp * arr[x][k];
		}
		y++;
		x++;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 4; j++)
				if (arr[i][j] <= 1e-6 && arr[i][j] >= -1e-6)
					arr[i][j] = 0.000001;
	}

	/*
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
	*/
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, cnt = 1;
	cin >> t;
	while (t--)
	{
		arr.resize(3);
		for (int i = 0; i < arr.size(); i++)
			arr[i].resize(4);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 4; j++)
			{
				cin >> arr[i][j];
			}

		gauss();

		cout << "Case " << cnt++ << ": " << fixed << setprecision(2) << arr[0][3] << ' ' << arr[1][3] << ' ' << arr[2][3] << '\n';
		arr.clear();
	}

	return 0;
}
