#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void road_to_zero()
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a*2 < b)
        cout << a*(x + y) << '\n';
    else
    {
        cout << min(x, y)*b + abs(x - y)*a << '\n'; 
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
        road_to_zero();
    return 0;
}