#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<char> vec;
class cmp
{
public:
    bool operator()(char a, char b)
    {
        return a > b;
    }
};
int main()
{
    int n, m, cnt = 0;
    while (cin >> n >> m)
    {
        if (cnt++)
            cout << '\n';

        while (n--)
            vec.push_back('S');
        while (m--)
            vec.push_back('L');
        sort(vec.begin(), vec.end(), cmp());
        do
        {
            for (auto i : vec)
                cout << i;
            cout << endl;
        } while (prev_permutation(vec.begin(), vec.end()));
        vec.clear();
    }
}
