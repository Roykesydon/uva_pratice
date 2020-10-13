#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;
class people
{
public:
    int time;
    int x;
    long long num;
};
class cmp
{
public:
    bool operator()(people a, people b)
    {
        if (abs(a.time) != abs(b.time))
            return abs(a.time) < abs(b.time);
        return a.x > b.x;
    }
};
vector<people> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, tmp;
    int x, y, z;
    long long maxd;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> x >> y >> z;
            arr.push_back({x, 1, z});
            arr.push_back({y, -1, z});
        }
        maxd = 0;
        sort(arr.begin(), arr.end(), cmp());
        //sort(arr.begin(), arr.end(), cmp());
        /*
        for (auto i : arr)
            cout << i.time * i.x << ' ';
        cout << endl;
        */
        tmp = 0, maxd = 0;
        for (auto i : arr)
        {
            if (i.time > 0)
                tmp += i.num * i.x;
            else
                tmp -= i.num * i.x;
            //cout << tmp << ' ';
            maxd = max(maxd, tmp);
        }
        cout << maxd << '\n';

        arr.clear();
    }
}
