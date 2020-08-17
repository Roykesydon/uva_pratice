#include <iostream>
#include<deque>
#include<vector>
using namespace std;
deque<pair<int, int> > deq_b, deq_s;
vector<int> ans_b, ans_s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!deq_b.empty() && (deq_b.front().first <= x || i - deq_b.front().second >= k))
            deq_b.pop_front();
        while (!deq_b.empty() && (deq_b.back().first <= x || i - deq_b.back().second >= k))
            deq_b.pop_back();
        // cerr << "deq_b.front= " << deq_b.front().first << ' ' << deq_b.front().second << " || "
        //      << " x= " << x << '\n';
        if (deq_b.empty() || deq_b.front().first < x)
            deq_b.push_front({x, i});
        else
            deq_b.push_back({x, i});
        //ans_b.push_back(deq_b.front());
        while (!deq_s.empty() && (deq_s.front().first >= x || i - deq_s.front().second >= k))
            deq_s.pop_front();
        while (!deq_s.empty() && (deq_s.back().first >= x || i - deq_s.back().second >= k))
            deq_s.pop_back();
        // cerr << "deq_s.front= " << deq_s.front().first << ' ' << deq_s.front().second << " || "
        //      << " x= " << x << '\n';
        if (deq_s.empty() || deq_s.front().first > x)
            deq_s.push_front({x, i});
        else
            deq_s.push_back({x, i});
        // cerr << "i= " << i << '\n';
        // cerr << "deq_b.front= " << deq_b.front().first << ' ' << deq_b.front().second << '\n';
        // cerr << "deq_s.front= " << deq_s.front().first << ' ' << deq_s.front().second << '\n';
        //cerr<<"i= "<<i<<" deq.size()= "<<deq_s.size()<<' '<<deq_b.size()<<'\n';
        if (i >= k - 1)
        {
            ans_b.push_back(deq_b.front().first);
            ans_s.push_back(deq_s.front().first);
        }
    }
    //cout<<ans_s.size()<<' '<<ans_b.size()<<'\n';
    for (int i = 0; i < ans_s.size(); i++)
        cout << ans_s[i] << ' ';
    cout << '\n';
    for (int i = 0; i < ans_b.size(); i++)
        cout << ans_b[i] << ' ';
    cout << '\n';

    return 0;
}
