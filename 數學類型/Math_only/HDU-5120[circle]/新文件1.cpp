#include <bits/stdc++.h>
using namespace std;
#define pi (acos(-1))
#define eps (1e-6)
struct circle
{
    int x, y;
    double r;
    circle() { x = 0, y = 0, r = 0; }
    circle(int a, int b, double c)
    {
        x = a, y = b, r = c;
    }
};
double intersection(circle a, circle b)
{
    double dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    double radius_minus_dif = abs(a.r - b.r);
    double radius_plus_dif = abs(a.r + b.r);
    if (dis < radius_minus_dif || abs(dis - radius_minus_dif) < eps)//include
        return (min(a.r, b.r) * min(a.r, b.r) * pi);
    else if (dis > radius_plus_dif || abs(dis - radius_plus_dif) < eps)//outside
        return +0.0;
    else
    {
        double theta_a = acos((a.r * a.r + dis * dis - b.r * b.r) / 2.0 / a.r / dis);
        double theta_b = acos((b.r * b.r + dis * dis - a.r * a.r) / 2.0 / b.r / dis);
        double polygon = 1.0 / 2.0 * a.r * dis * sin(theta_a) * 2.0;
        double sector_a = a.r * a.r / 2.0 * theta_a * 2.0;
        double sector_b = b.r * b.r / 2.0 * theta_b * 2.0;
        //cout<<"theta_a= "<<theta_a<<" theta_b= "<<theta_b<<"  polygon= "<< polygon<<" sector_a= "<<sector_a<<" sector_b= "<<sector_b<<'\n';
        return (sector_a+sector_b-polygon);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, r, R, x1, y1, x2, y2;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> r >> R;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        circle s1(x1, y1, r), b1(x1, y1, R), s2(x2, y2, r), b2(x2, y2, R);
        //cout<<"intersection(b1, b2)= "<<intersection(b1, b2)<<" - intersection(b1, s1)= "<<-intersection(b1, s1)<<" - intersection(b2, s2)= "<<- intersection(b2, s2)<<" + intersection(s1, s2)="<<intersection(s1, s2)<<'\n';
        cout << "Case #" << cas << ": " <<fixed<<setprecision(6)<< intersection(b1, b2) - intersection(b1, s2) - intersection(b1, s2) + intersection(s1, s2)<<'\n';
    }

    return 0;
}
