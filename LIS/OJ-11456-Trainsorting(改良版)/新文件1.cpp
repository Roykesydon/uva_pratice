#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    int cnt;
    int n;
    int tmp;
    deque<int> deq;
    vector<int> ans;
    cin >> cnt;
    while (cnt--)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "0\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (i == 0)
                deq.push_back(tmp);
            else
            {
                deq.push_front(tmp);
                deq.push_back(tmp);
            }
        }
        // for (auto i : deq)
        //     cout << i << ' ';
        ans.push_back(*deq.begin());

        for (auto i = deq.begin(); i < deq.end(); i++)
        {
            if (i == deq.begin())
                continue;
            //cout << "*i= " << *i << ' ';
            if (*i > ans.back())
                ans.push_back(*i); // 9 8 5 2 1     4 3
            else                   //   2   3  4      4
            {
                *lower_bound(ans.begin(), ans.end(), *i) = *i;
            }
        }

        cout << ans.size() << '\n';
        ans.clear();
        deq.clear();
    }
}
