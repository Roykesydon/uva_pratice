#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<long long> vec;
int main()
{
    long long n, k;
    long long tmp;
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            vec.push_back(tmp);
        }

        for (int i = 0; i < k; i++)
        {
            cin >> tmp;
            if (tmp < vec.front() || tmp > vec.back())
            {
                cout << "0\n";
                continue;
            }
            if (lower_bound(vec.begin(), vec.end(), tmp) != vec.end()&&*lower_bound(vec.begin(), vec.end(), tmp)==tmp)
                cout << lower_bound(vec.begin(), vec.end(), tmp) - vec.begin() + 1 << '\n';
            else
                cout << "0\n";
        }
        vec.clear();
    }

    //system("PAUSE");
}
