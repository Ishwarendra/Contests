#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;

ll sum(vi arr)
{
    ll sum = 0LL;
    for(auto i : arr)
        sum += i;

    return sum;
}

int main()
{
    int n; cin >> n;
    vi cost(n);

    for(int i = 0; i < n; i++)
        cin >> cost[i];
    
    int m; cin >> m;
    vi q(m);
    
    sort(cost.begin(), cost.end(), greater<long long>());
    ll total_cost = sum(cost);

    for(int i = 0; i < m; i++)
        cin >> q[i];

    for (auto &coupon : q)
    {
        cout << (total_cost - cost[coupon - 1]) << '\n';
    }

    return 0;
}