#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int get_max(vector<ll> &v)
{
    int n = v.size();
    ll max_id = 0;
    for(int i = 1; i < n; i++)
    {
        if (v[max_id] < v[i]) 
            max_id = i;
    }

    return max_id;
}

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int max_id = get_max(a);

    if (max_id != 0)
    {
        cout << -1 << "\n";
        return;
    }
    else
    {
        stack<ll> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() and s.top() <= a[i])
                s.pop();
            s.push(a[i]);
        }

        cout << s.size() - 1 << "\n";
    }
}

int main()
{
    int t ; cin >> t;
    while(t--)
        solve();
    return 0;
}