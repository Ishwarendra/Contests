#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    deque<int> dq;
    int n; cin >> n;
    vi a(n);
    cin >> a[0];
    dq.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < dq.front())
            dq.push_front(a[i]);
        else
            dq.push_back(a[i]);
    }

    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}